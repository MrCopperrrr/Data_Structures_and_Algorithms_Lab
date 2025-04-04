template <class T>
T DLinkedList<T>::removeAt(int index) {
    // Remove element at the given index and return the removed value
    if (index < 0 || index >= count) {
        throw std::out_of_range("Index out of range");
    }

    Node* current = head;
    T removedData;

    if (index == 0) {  // Special case: removing the first element
        removedData = head->data;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;  // List is now empty
        }
    } else {
        Node* prev = nullptr;
        for (int i = 0; i < index; i++) {
            prev = current;
            current = current->next;
        }
        removedData = current->data;
        prev->next = current->next;
        if (current == tail) {
            tail = prev;  // If the removed node is the last one, update the tail
        }
    }
    
    delete current;
    count--;
    return removedData;
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item) {
    // Remove the first occurrence of the item and return true, otherwise return false
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data == item) {
            if (current == head) {  // Special case: removing the first element
                head = head->next;
                if (head == nullptr) {
                    tail = nullptr;  // List is now empty
                }
            } else {
                prev->next = current->next;
                if (current == tail) {
                    tail = prev;  // If the removed node is the last one, update the tail
                }
            }

            delete current;
            count--;
            return true;
        }

        prev = current;
        current = current->next;
    }

    return false;  // Item not found
}

template <class T>
void DLinkedList<T>::clear() {
    // Remove all elements from the list
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    head = tail = nullptr;
    count = 0;
}
