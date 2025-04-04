int longestPathSumHelper(BTNode* node, int& maxLength, int& maxSum, int currentLength, int currentSum) {
    if (!node) return 0;

    currentLength++;
    currentSum += node->val;

    if (!node->left && !node->right) { // Leaf node
        if (currentLength > maxLength || (currentLength == maxLength && currentSum > maxSum)) {
            maxLength = currentLength;
            maxSum = currentSum;
        }
    } else {
        if (node->left) {
            longestPathSumHelper(node->left, maxLength, maxSum, currentLength, currentSum);
        }
        if (node->right) {
            longestPathSumHelper(node->right, maxLength, maxSum, currentLength, currentSum);
        }
    }
    return maxSum;
}

int longestPathSum(BTNode* root) {
    if (!root) return 0;
    int maxLength = 0;
    int maxSum = 0;
    return longestPathSumHelper(root, maxLength, maxSum, 0, 0);
}