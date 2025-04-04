void LinkedList::partition(int k) {
    if (!head) return;
 
    Node* lessHead = nullptr;
    Node* lessTail = nullptr;
    Node* equalHead = nullptr;
    Node* equalTail = nullptr;
    Node* greaterHead = nullptr;
    Node* greaterTail = nullptr;
 
    Node* current = head;
 
    while (current) {
        if (current->value < k) {
            if (!lessHead) {
                lessHead = lessTail = current;
            } else {
                lessTail->next = current;
                lessTail = current;
            }
        } else if (current->value == k) {
            if (!equalHead) {
                equalHead = equalTail = current;
            } else {
                equalTail->next = current;
                equalTail = current;
            }
        } else {
            if (!greaterHead) {
                greaterHead = greaterTail = current;
            } else {
                greaterTail->next = current;
                greaterTail = current;
            }
        }
        current = current->next;
    }
 
    if (lessTail) lessTail->next = equalHead;
    if (equalTail) equalTail->next = greaterHead;
    if (greaterTail) greaterTail->next = nullptr;
 
    if (lessHead) {
        head = lessHead;
    } else if (equalHead) {
        head = equalHead;
    } else {
        head = greaterHead;
    }
    if (greaterTail) {
        tail = greaterTail;
    } else if (equalTail) {
        tail = equalTail;
    } else {
        tail = lessTail;
    }
}
