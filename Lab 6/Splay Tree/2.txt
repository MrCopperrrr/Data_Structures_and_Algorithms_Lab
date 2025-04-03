bool search(int val) {
    Node* current = root;
    Node* lastAccessed = nullptr;

    // Perform standard BST search
    while (current) {
        lastAccessed = current;

        if (val < current->val) {
            current = current->pLeft;
        } else if (val > current->val) {
            current = current->pRight;
        } else {
            // Node found, splay it to the root
            splay(current);
            return true;
        }
    }

    // If node not found, splay the last accessed node
    splay(lastAccessed);
    return false;
}
