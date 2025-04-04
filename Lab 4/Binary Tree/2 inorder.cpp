    int getHeightHelper(Node* node) {
        if (node == nullptr)
            return 0;
        int leftHeight = getHeightHelper(node->pLeft);
        int rightHeight = getHeightHelper(node->pRight);
        return 1 + max(leftHeight, rightHeight);
    }

    int getHeight() {
        return getHeightHelper(root);
    }

    // Helper function for pre-order traversal
    void preOrderHelper(Node* node, stringstream& ss) {
        if (node == nullptr)
            return;
        ss << node->value << " ";
        preOrderHelper(node->pLeft, ss);
        preOrderHelper(node->pRight, ss);
    }

    string preOrder() {
        stringstream ss;
        preOrderHelper(root, ss);
        string result = ss.str();
        if (!result.empty())
            result.pop_back(); // remove the trailing space
        return result;
    }

    // Helper function for in-order traversal
    void inOrderHelper(Node* node, stringstream& ss) {
        if (node == nullptr)
            return;
        inOrderHelper(node->pLeft, ss);
        ss << node->value << " ";
        inOrderHelper(node->pRight, ss);
    }

    string inOrder() {
        stringstream ss;
        inOrderHelper(root, ss);
        string result = ss.str();
        if (!result.empty())
            result.pop_back(); // remove the trailing space
        return result;
    }

    // Helper function for post-order traversal
    void postOrderHelper(Node* node, stringstream& ss) {
        if (node == nullptr)
            return;
        postOrderHelper(node->pLeft, ss);
        postOrderHelper(node->pRight, ss);
        ss << node->value << " ";
    }

    string postOrder() {
        stringstream ss;
        postOrderHelper(root, ss);
        string result = ss.str();
        if (!result.empty())
            result.pop_back(); // remove the trailing space
        return result;
    }