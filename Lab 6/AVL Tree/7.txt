private:
void printInorderRec(Node* node) {
    if (node == nullptr) {
        return;
    }
    printInorderRec(node->pLeft);
    cout << node->data << " ";
    printInorderRec(node->pRight);
}

bool searchRec(Node* node, const T& value) {
    if (node == nullptr) {
        return false;
    }
    if (node->data == value) {
        return true;
    }
    if (value < node->data) {
        return searchRec(node->pLeft, value);
    } else {
        return searchRec(node->pRight, value);
    }
}

public:
void printInorder() {
    if (root != nullptr) {
        printInorderRec(root);
        cout << " "; // Add whitespace at the end as per requirements
    }
}

bool search(const T& value) {
    return searchRec(root, value);
}