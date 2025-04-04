ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;  
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* mergeLists(ListNode* a, ListNode* b) {
    ListNode dummy(0);  
    ListNode* tail = &dummy;

    while (a && b) {
        if (a->val <= b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    tail->next = (a) ? a : b;
    return dummy.next;
}

ListNode* mergeSortList(ListNode* head) {
    if (!head || !head->next)  
        return head;

    ListNode* middle = findMiddle(head);
    ListNode* rightHalf = middle->next;
    middle->next = nullptr;  // Split the list into two halves

    ListNode* leftSorted = mergeSortList(head);
    ListNode* rightSorted = mergeSortList(rightHalf);

    return mergeLists(leftSorted, rightSorted);
}