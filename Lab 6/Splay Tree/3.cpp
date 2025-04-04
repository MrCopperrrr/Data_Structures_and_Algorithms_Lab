Node* remove(int val) {
    if (!root) {
        // Tree is empty, nothing to remove
        return nullptr;
    }

    // Search for the node and splay it
    if (!search(val)) {
        // Node not found, return nullptr
        return nullptr;
    }

    // Now, the root contains the node to be removed
    Node* nodeToRemove = root;

    // If root's value is not equal to val, return NULL (this should be handled by search)
    if (root->val != val) {
        return nullptr;
    }

    // Split the tree into two parts
    Node* leftSubtree = root->pLeft;
    Node* rightSubtree = root->pRight;

    // Remove the root node
    if (leftSubtree) {
        leftSubtree->pParent = nullptr;  // Detach the left subtree from the root
    }
    if (rightSubtree) {
        rightSubtree->pParent = nullptr;  // Detach the right subtree from the root
    }

    // Now we need to reattach the subtrees
    if (leftSubtree) {
        // Splay the maximum node in the left subtree (rightmost node)
        Node* maxLeft = leftSubtree;
        while (maxLeft->pRight) {
            maxLeft = maxLeft->pRight;
        }

        // Splay the maximum node in the left subtree to the root of the left subtree
        splay(maxLeft);

        // Attach the right subtree to the right of the max node in the left subtree
        maxLeft->pRight = rightSubtree;
        if (rightSubtree) {
            rightSubtree->pParent = maxLeft;
        }

        // The new root will be the maximum node of the left subtree
        root = maxLeft;
    } else {
        // If there is no left subtree, the right subtree becomes the root
        root = rightSubtree;
    }

    // Return the node that was removed
    return nodeToRemove;
}
