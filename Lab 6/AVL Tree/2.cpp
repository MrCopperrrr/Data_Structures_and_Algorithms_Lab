void insert(const T &value) {
        bool taller = false;
        root = insertRec(root, value, taller);
    }
Node* insertRec(Node* node, const T& value, bool& taller) {
        if (node == NULL) {
            node = new Node(value);
            taller = true;
            return node;
        }

        if (value < node->data) {
            node->pLeft = insertRec(node->pLeft, value, taller);
            if (taller) {
                if (node->balance == EH) {
                    node->balance = LH;
                } else if (node->balance == LH) {
                    node = balance(node);
                    taller = false;
                } else {
                    node->balance = EH;
                    taller = false;
                }
            }
        } else {
            node->pRight = insertRec(node->pRight, value, taller);
            if (taller) {
                if (node->balance == EH) {
                    node->balance = RH;
                } else if (node->balance == RH) {
                    node = balance(node);
                    taller = false;
                } else {
                    node->balance = EH;
                    taller = false;
                }
            }
        }
        return node;
    }
Node* balance(Node* node) {
        if (node->balance == LH) {
            if (node->pLeft->balance == RH) {
                node->pLeft = rotateLeft(node->pLeft);
            }
            node = rotateRight(node);
        } else if (node->balance == RH) {
            if (node->pRight->balance == LH) {
                node->pRight = rotateRight(node->pRight);
            }
            node = rotateLeft(node);
        }
        return node;
    }
Node* rotateLeft(Node* node) {
    Node* newRoot = node->pRight;
    node->pRight = newRoot->pLeft;
    newRoot->pLeft = node;
    // Update balance factors
    node->balance = (newRoot->balance == LH) ? EH : RH;
    newRoot->balance = (newRoot->balance == LH) ? EH : EH;
    return newRoot;
}

Node* rotateRight(Node* node) {
    Node* newRoot = node->pLeft;
    node->pLeft = newRoot->pRight;
    newRoot->pRight = node;
    // Update balance factors
    node->balance = (newRoot->balance == RH) ? EH : LH;
    newRoot->balance = (newRoot->balance == RH) ? EH : EH;
    return newRoot;
}