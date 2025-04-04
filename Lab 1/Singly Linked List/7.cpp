LLNode* rotateLinkedList(LLNode* head, int k) {
    if (!head || k == 0) return head;
    LLNode* current = head;
    int length = 1;
    while (current->next) {
        current = current->next;
        length = length + 1;
    }
    k = k % length;
    if (k == 0) return head;
    current->next = head;
    LLNode* newTail = head;
    for (int i = 1; i < length - k; ++i) {
        newTail = newTail->next;
    }
    LLNode* newHead = newTail->next;
    newTail->next = nullptr;
 
    return newHead;
}
