 void put(int key, int value) {
    //TODO: Compute the index using the hash function
    int index = hashFunction(key, capacity);

    //TODO: Check if the key exists in the linked list at the index, update if found
    Entry* current = table[index];
    while (current != nullptr) {
        if (current->key == key) {
            current->value = value; // Update value if key exists
            return;
        }
        current = current->next;
    }

    //TODO: If the key doesn't exist, create and insert a new entry
    Entry* newEntry = new Entry(key, value);
    newEntry->next = table[index];
    table[index] = newEntry;
    count++;

    //TODO: Increment the count and ensure load factor by resizing if needed
    ensureLoadFactor(count);
}

void ensureLoadFactor(int current_size) {
    //TODO: Calculate the maximum allowed size based on the load factor (0.75 * capacity)
    int maxcount = int(0.75 * this->capacity);

    //TODO: If the current size exceeds or equals the max allowed size, trigger rehashing
    if (this->count >= maxcount) {
        //TODO: Calculate the new capacity (1.5 times the old capacity)
        int newcapacity = int(this->capacity * 1.5);

        //TODO: Call the rehash function with the new capacity
        rehash(newcapacity);
    }
}

void rehash(int newCapacity) {
    //TODO: Store the current table and capacity
    Entry** oldTable = table;
    int oldCapacity = capacity;

    //TODO: Create a new table with the new capacity and update the capacity
    capacity = newCapacity;
    table = new Entry*[capacity];

    //TODO: Initialize the new table with nullptr values
    for (int i = 0; i < capacity; i++) {
        table[i] = nullptr;
    }

    //TODO: For each index in the old table:
    //      - Traverse the linked list at that index
    //      - Recompute the new index for each entry using the new capacity
    //      - Insert the entry into the new table at the recomputed index
    for (int i = 0; i < oldCapacity; i++) {
        Entry* current = oldTable[i];
        while (current != nullptr) {
            Entry* Enext = current->next;
            int newIndex = hashFunction(current->key, capacity);

            // Insert current entry at new index in the new table
            current->next = table[newIndex];
            table[newIndex] = current;

            current = Enext;
        }
    }

    //TODO: Delete all entries in the old table by traversing each linked list and deleting nodes
    for (int i = 0; i < oldCapacity; i++) {
        Entry* delEntry = oldTable[i];
        while (delEntry && delEntry->next) {
            Entry* deleteEntry = delEntry;
            delEntry = delEntry->next;
            delete deleteEntry;
        }
    }

    //TODO: Delete the old table array
    delete[] oldTable;
}