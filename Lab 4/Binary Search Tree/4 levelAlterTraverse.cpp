vector<int> levelAlterTraverse(BSTNode* root) {
    if (!root) return {}; // If tree is empty, return an empty vector

    vector<int> result;
    deque<BSTNode*> dq;
    dq.push_back(root);

    bool leftToRight = true; // Start with left-to-right traversal

    while (!dq.empty()) {
        int levelSize = dq.size();
        vector<int> levelValues(levelSize);

        for (int i = 0; i < levelSize; ++i) {
            BSTNode* node = nullptr;

            // Pop nodes based on current direction
            if (leftToRight) {
                node = dq.front();
                dq.pop_front();
            } else {
                node = dq.back();
                dq.pop_back();
            }

            // Add the node's value to the level vector
            levelValues[i] = node->val;

            // Enqueue child nodes based on the current direction
            if (leftToRight) {
                if (node->left) dq.push_back(node->left);
                if (node->right) dq.push_back(node->right);
            } else {
                if (node->right) dq.push_front(node->right);
                if (node->left) dq.push_front(node->left);
            }
        }

        // Append the level's values to the result
        result.insert(result.end(), levelValues.begin(), levelValues.end());

        // Switch direction for the next level
        leftToRight = !leftToRight;
    }

    return result;
}