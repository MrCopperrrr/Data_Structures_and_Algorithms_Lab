template <class T>
void SLinkedList<T>::add(const T& e) {
    Node* newNode = new Node(e, nullptr);
    if (count == 0) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    if (index < 0 || index > count) {
        throw std::out_of_range("The input index is out of range!");
    }

    Node* newNode = new Node(e);

    if (index == 0) {
        newNode->next = head;
        head = newNode;
        if (count == 0) {
            tail = head;
        }
    } else {
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }
    count++;
}

template<class T>
int SLinkedList<T>::size() {
    return count;
    return 0;
}
