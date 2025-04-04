    // Function to add a node to the BST
    void add(T value) {
        root = addRec(root, value);
    }

    Node* addRec(Node* node, T value) {
        if (node == nullptr) {
            return new Node(value);
        }
        // Add the value in the left subtree if it's the same as the parent node's value
        if (value <= node->value) {
            node->pLeft = addRec(node->pLeft, value);
        } else {
            node->pRight = addRec(node->pRight, value);
        }
        return node;
    }

    // Function to delete a node from the BST
    void deleteNode(T value) {
        root = deleteRec(root, value);
    }

    Node* deleteRec(Node* node, T value) {
        if (node == nullptr) {
            return node;
        }
        // Navigate the tree to find the node to delete
        if (value < node->value) {
            node->pLeft = deleteRec(node->pLeft, value);
        } else if (value > node->value) {
            node->pRight = deleteRec(node->pRight, value);
        } else {
            // Node with only one child or no child
            if (node->pLeft == nullptr) {
                Node* temp = node->pRight;
                delete node;
                return temp;
            } else if (node->pRight == nullptr) {
                Node* temp = node->pLeft;
                delete node;
                return temp;
            }

            // Node with two children: get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(node->pRight);
            node->value = temp->value;
            node->pRight = deleteRec(node->pRight, temp->value);
        }
        return node;
    }

    // Helper function to find the minimum value node in a subtree
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->pLeft != nullptr) {
            current = current->pLeft;
        }
        return current;
    }