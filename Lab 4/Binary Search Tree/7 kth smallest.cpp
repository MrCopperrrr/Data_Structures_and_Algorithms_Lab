int kthSmallestHelper(BSTNode* root, int& k) {
    if (!root) return -1;
    // Traverse left subtree
    int val = kthSmallestHelper(root->left, k);
    if (k == 0) return val;
    // Visit current node
    k--;
    if (k == 0) return root->val;
    // Traverse right subtree
    return kthSmallestHelper(root->right, k);
}

int kthSmallest(BSTNode* root, int k) {
    return kthSmallestHelper(root, k);
}