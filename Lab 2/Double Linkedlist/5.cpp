ListNode* reverse(ListNode* head, int a, int b) {
    if (!head || a == b) return head;
    
    // Use a dummy node to handle cases where a = 1
    ListNode* dummy = new ListNode(0);
    dummy->right = head;
    head->left = dummy;
    
    // Find the node before position 'a'
    ListNode* beforeA = dummy;
    for (int i = 1; i < a; i++) {
        beforeA = beforeA->right;
    }
    
    // Find the node at position 'b'
    ListNode* nodeB = beforeA;
    for (int i = 0; i <= b-a; i++) {
        nodeB = nodeB->right;
    }
    
    // Save the node after position 'b'
    ListNode* afterB = nodeB->right;
    
    // Cut the sublist from the main list
    ListNode* nodeA = beforeA->right;
    beforeA->right = nullptr;
    if (afterB) afterB->left = nullptr;
    nodeA->left = nullptr;
    nodeB->right = nullptr;
    
    // Reverse the sublist from position a to b
    ListNode *prev = nullptr, *curr = nodeA, *next = nullptr;
    while (curr) {
        next = curr->right;
        curr->right = prev;
        curr->left = next;
        prev = curr;
        curr = next;
    }
    
    // Connect the reversed sublist back to the main list
    beforeA->right = nodeB;
    nodeB->left = beforeA;
    nodeA->right = afterB;
    if (afterB) afterB->left = nodeA;
    
    // Get the new head of the list
    head = dummy->right;
    head->left = nullptr;
    
    // Clean up dummy node
    delete dummy;
    
    return head;
}