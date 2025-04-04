LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    LLNode dummy;
    LLNode* current = &dummy;
    int carry = 0;
    while (l0 != nullptr || l1 != nullptr || carry != 0) {
        int val0 = (l0 != nullptr) ? l0->val : 0;
        int val1 = (l1 != nullptr) ? l1->val : 0;
        int sum = val0 + val1 + carry;
        carry = sum / 10;
        current->next = new LLNode(sum % 10, nullptr);
        current = current->next;
        if (l0 != nullptr) l0 = l0->next;
        if (l1 != nullptr) l1 = l1->next;
    }
    return dummy.next;
}
