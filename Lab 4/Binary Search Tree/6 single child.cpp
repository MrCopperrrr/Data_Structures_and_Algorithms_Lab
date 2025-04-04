int singleChildHelper(BSTNode* node, BSTNode* parent) {
    if (!node) return 0;
    int count = 0;
    if (parent && ((parent->left && !parent->right) || (!parent->left && parent->right))) {
        count++;
    }
    count += singleChildHelper(node->left, node);
    count += singleChildHelper(node->right, node);
    return count;
}

int singleChild(BSTNode* root) {
    return singleChildHelper(root, nullptr);
}