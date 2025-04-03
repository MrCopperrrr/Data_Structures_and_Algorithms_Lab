    V& get(K key) {
        int index = hashFunction(key, capacity);

        Entry* entry = table[index];
        while (entry != 0) {
            if (entry->key == key) {
                return entry->value;             }
            entry = entry->next;
        }
        
        throw std::out_of_range("Key not found"); 
    }


