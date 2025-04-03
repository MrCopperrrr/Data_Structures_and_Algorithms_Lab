
    V remove(K key) {
        int index = hashFunction(key, capacity);

        Entry* entry = table[index];
        Entry* prev = nullptr;
        while (entry != 0) {
            if (entry->key == key) {
                V value = entry->value;
                if (prev == nullptr) {
                    table[index] = entry->next;
                } else {
                    prev->next = entry->next;
                }
                delete entry;
                count--;
                return value; 
            }
            prev = entry;
            entry = entry->next;
        }

        throw std::out_of_range("Key not found");     }

