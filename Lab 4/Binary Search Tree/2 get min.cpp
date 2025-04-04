T getMin() {
    if (!this->root) {
        throw runtime_error("Tree is empty, no minimum value.");
    }

    Node* current = this->root;
    while (current->pLeft) { // Traverse to the leftmost node
        current = current->pLeft;
    }
    return current->value; // The leftmost node contains the minimum value
}

T getMax() {
    if (!this->root) {
        throw runtime_error("Tree is empty, no maximum value.");
    }

    Node* current = this->root;
    while (current->pRight) { // Traverse to the rightmost node
        current = current->pRight;
    }
    return current->value; // The rightmost node contains the maximum value
}