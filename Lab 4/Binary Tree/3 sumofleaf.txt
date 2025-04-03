int sumOfLeafs() {
        return sumOfLeafsHelper(root);
    }


    int sumOfLeafsHelper(Node* node) {
        if (node == nullptr)
            return 0;

        // Check if the current node is a leaf
        if (node->pLeft == nullptr && node->pRight == nullptr)
            return node->value;

        // Recursively sum up leaf nodes in the left and right subtrees
        return sumOfLeafsHelper(node->pLeft) + sumOfLeafsHelper(node->pRight);
    }