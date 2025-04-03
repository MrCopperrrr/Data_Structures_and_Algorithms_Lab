Node* rotateRight(Node* root) {
    Node* newRoot = root->pLeft;
    root->pLeft = newRoot->pRight;
    newRoot->pRight = root;
    return newRoot;
}

Node* rotateLeft(Node* root) {
    Node* newRoot = root->pRight;
    root->pRight = newRoot->pLeft;
    newRoot->pLeft = root;
    return newRoot;
}