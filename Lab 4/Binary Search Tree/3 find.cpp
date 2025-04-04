bool find(T i) {
    Node* current = this->root;
    while (current) {
        if (i == current->value) return true;  // Found the value
        if (i < current->value) {
            current = current->pLeft;  // Move to left subtree
        } else {
            current = current->pRight;  // Move to right subtree
        }
    }
    return false;  // Value not found
}

T sumInRange(Node* node, T l, T r) {
    if (!node) return 0;  // Base case: null node contributes 0 to the sum

    T total = 0;

    // If node value is within range, include it in the sum
    if (node->value >= l && node->value <= r) {
        total += node->value;
    }

    // Traverse left subtree if there's a chance of values in range
    if (node->value > l) {
        total += sumInRange(node->pLeft, l, r);
    }

    // Traverse right subtree if there's a chance of values in range
    if (node->value < r) {
        total += sumInRange(node->pRight, l, r);
    }

    return total;
}

T sum(T l, T r) {
    return sumInRange(this->root, l, r);  // Start from the root
}