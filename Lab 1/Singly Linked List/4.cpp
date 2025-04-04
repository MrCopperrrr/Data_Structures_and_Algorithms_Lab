void insertAtFront(LLNode*& head, int val) {
    if (head == nullptr) {
        head = new LLNode(val, nullptr);
    }
    else {
        LLNode* newNode = new LLNode(val, head);
        head = newNode;
    }
}
 
LLNode* reverseLinkedList(LLNode* head) {
    LLNode* reverseHead = nullptr;
    LLNode* curr = head;
    while (curr != nullptr) {
        insertAtFront(reverseHead, curr->val);
        curr= curr->next;
    }
    return reverseHead;
}
