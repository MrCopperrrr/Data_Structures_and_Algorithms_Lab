BTNode* findLowestAncestor(BTNode* root, int a, int b) {
    if (!root) return nullptr; // Base case: null node

    // If the current node matches either a or b, it's a potential ancestor
    if (root->val == a || root->val == b) {
        return root;
    }

    // Recur for left and right subtrees
    BTNode* leftLCA = findLowestAncestor(root->left, a, b);
    BTNode* rightLCA = findLowestAncestor(root->right, a, b);

    // If both left and right return non-null, the current node is the LCA
    if (leftLCA && rightLCA) {
        return root;
    }

    // Otherwise, return the non-null result from the subtrees
    return leftLCA ? leftLCA : rightLCA;
}

int lowestAncestor(BTNode* root, int a, int b) {
    BTNode* lcaNode = findLowestAncestor(root, a, b);
    return lcaNode ? lcaNode->val : -1; // Return the value of the LCA node
}