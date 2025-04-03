template <class T>
void DLinkedList<T>::add(const T& e) {
    Node* newNode = new Node(e);
    if (count == 0) {  
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    if (index < 0 || index > count) {
        throw out_of_range("Index out of range");
    }
    Node* newNode = new Node(e);
    if (index == 0) {  
        if (count == 0) {
            head = tail = newNode;
        } else {
            newNode->next=head;
            head->previous=newNode;
            head=newNode;
        }
    } else if (index == count) {  
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    } else {  
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        newNode->next = current;
        newNode->previous = current->previous;
        current->previous->next = newNode;
        current->previous = newNode;
    }
    count++;
    
}

template<class T>
int DLinkedList<T>::size() {
    return count;
    //return 0;
}