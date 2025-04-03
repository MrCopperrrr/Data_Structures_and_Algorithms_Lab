//Helping functions


int getbalance(Node* node) {
    if (node == nullptr)
        return 0;
    return getHeightRec(node->pLeft) - getHeightRec(node->pRight);
}

Node* rotateRight(Node* root) {
    Node* newRoot = root->pLeft;
    Node* temp = newRoot->pRight;

    newRoot->pRight = root;
    root->pLeft = temp;

    return newRoot;
}

Node* rotateLeft(Node* root) {
    Node* newRoot = root->pRight;
    Node* temp = newRoot->pLeft;

    newRoot->pLeft = root;
    root->pRight = temp;

    return newRoot;
}

Node* insert(Node* node, T value) {
    if (node == nullptr)
        return new Node(value);

    if (value < node->data)
        node->pLeft = insert(node->pLeft, value);
    else if (value > node->data)
        node->pRight = insert(node->pRight, value);


    int balance = getbalance(node);

    // Left of Left Case
    if (balance > 1 && value < node->pLeft->data)
        return rotateRight(node);

    // Right of Right Case
    if (balance < -1 && value > node->pRight->data)
        return rotateLeft(node);

    // Left of Right Case
    if (balance > 1 && value > node->pLeft->data) {
        node->pLeft = rotateLeft(node->pLeft);
        return rotateRight(node);
    }

    // Right of Left Case
    if (balance < -1 && value < node->pRight->data) {
        node->pRight = rotateRight(node->pRight);
        return rotateLeft(node);
    }

    return node;
}

void insert(const T& value) {
    //TODO
    this->root = insert(this->root, value);
}
