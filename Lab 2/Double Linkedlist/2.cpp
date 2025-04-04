template<class T>
T DLinkedList<T>::get(int index) {
    // Give the data of the element at given index in the list.
    if (index < 0 || index >= count) {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    // Assign new value for element at given index in the list
    if (index < 0 || index >= count) {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = e;
}

template<class T>
bool DLinkedList<T>::empty() {
    // Check if the list is empty or not.
    return count == 0;
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    // Return the first index where item appears in list, otherwise return -1
    Node* current = head;
    int index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1; // Item not found
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    // Check if item appears in the list
    return indexOf(item) != -1;
}
