// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

void BFS() {
    if (this->root == nullptr) return; // If the tree is empty, there's nothing to traverse

    queue<Node*> q;
    q.push(this->root); // Start from the root

    bool isFirst = true; // Used to avoid trailing spaces
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (!isFirst) {
            cout << " ";
        }
        cout << current->value;
        isFirst = false;

        // Enqueue left and right children if they exist
        if (current->pLeft) q.push(current->pLeft);
        if (current->pRight) q.push(current->pRight);
    }
}
// STUDENT ANSWER END
