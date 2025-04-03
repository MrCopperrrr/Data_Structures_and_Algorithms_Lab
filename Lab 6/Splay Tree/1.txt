void rightRotate(Node* x) {
    Node* y = x->pLeft;
    x->pLeft = y->pRight;
    if (y->pRight) y->pRight->pParent = x;
    y->pParent = x->pParent;
    if (!x->pParent) {
        root = y;  // If x is root, update the root
    } else if (x == x->pParent->pLeft) {
        x->pParent->pLeft = y;
    } else {
        x->pParent->pRight = y;
    }
    y->pRight = x;
    x->pParent = y;
}

void leftRotate(Node* x) {
    Node* y = x->pRight;
    x->pRight = y->pLeft;
    if (y->pLeft) y->pLeft->pParent = x;
    y->pParent = x->pParent;
    if (!x->pParent) {
        root = y;  // If x is root, update the root
    } else if (x == x->pParent->pLeft) {
        x->pParent->pLeft = y;
    } else {
        x->pParent->pRight = y;
    }
    y->pLeft = x;
    x->pParent = y;
}

void splay(Node* p) {
    while (p->pParent) {
        if (!p->pParent->pParent) {
            // Zig step: p is the child of the root
            if (p == p->pParent->pLeft) {
                rightRotate(p->pParent);
            } else {
                leftRotate(p->pParent);
            }
        } else if (p == p->pParent->pLeft && p->pParent == p->pParent->pParent->pLeft) {
            // Zig-zig step: both p and its parent are left children
            rightRotate(p->pParent->pParent);
            rightRotate(p->pParent);
        } else if (p == p->pParent->pRight && p->pParent == p->pParent->pParent->pRight) {
            // Zig-zig step: both p and its parent are right children
            leftRotate(p->pParent->pParent);
            leftRotate(p->pParent);
        } else {
            // Zig-zag step: p is a left child and its parent is a right child or vice versa
            if (p == p->pParent->pLeft) {
                rightRotate(p->pParent);
                leftRotate(p->pParent);
            } else {
                leftRotate(p->pParent);
                rightRotate(p->pParent);
            }
        }
    }
}
void insert(int val) {
    Node* newNode = new Node(val);
    Node* current = root;
    Node* parent = nullptr;

    // Find the correct position for the new node
    while (current) {
        parent = current;
        if (val < current->val) {
            current = current->pLeft;
        } else {
            current = current->pRight;
        }
    }

    // Insert the new node
    newNode->pParent = parent;
    if (!parent) {
        root = newNode;  // Tree is empty, the new node is the root
    } else if (val < parent->val) {
        parent->pLeft = newNode;
    } else {
        parent->pRight = newNode;
    }

    // Perform splay operation to move the new node to the root
    splay(newNode);
}
