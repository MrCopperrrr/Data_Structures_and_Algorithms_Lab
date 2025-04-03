template<class T>
T SLinkedList<T>::get(int index) {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        return head->data;
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        head->data = e;
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = e;
}

template<class T>
bool SLinkedList<T>::empty() {
    if (head == nullptr) {
        return true;
    }
    return false;
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    int num = 0;
    Node* current = head;
    while (current != nullptr) {
        if (current->data == item) {
            return num;
        }
        num++;
        current = current->next;
    }
    return -1;
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == item) {
            return true;
        }
        current = current->next;
    }
    return false;
}