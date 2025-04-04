const int MOD = 27022001;
int sumDigitPathHelper(BTNode* node, int currentSum) {
    if (!node) return 0; // Base case: null node

    // Update the current sum to include the current node's value
    currentSum = (currentSum * 10 + node->val) % MOD;

    // If the current node is a leaf, return its path sum
    if (!node->left && !node->right) {
        return currentSum;
    }

    // Recur for left and right children
    int leftSum = sumDigitPathHelper(node->left, currentSum);
    int rightSum = sumDigitPathHelper(node->right, currentSum);

    // Combine the results from both subtrees
    return (leftSum + rightSum) % MOD;
}

int sumDigitPath(BTNode* root) {
    if (!root) return 0; // If the tree is empty, return 0
    return sumDigitPathHelper(root, 0); // Start recursion with initial sum 0
}