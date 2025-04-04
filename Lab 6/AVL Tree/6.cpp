Node *rotateRight1(Node *a)
{
    Node *b = a->pLeft;
    Node *c = b->pRight;
    a->pLeft = c;
    b->pRight = a;
    return b;
}

Node *rotateLeft1(Node *a)
{
    Node *b = a->pRight;
    Node *c = b->pLeft;
    a->pRight = c;
    b->pLeft = a;
    return b;
}
int getHeightRec1(Node *node)
{
    if (node == NULL)
        return 0;
    int lh = getHeightRec1(node->pLeft);
    int rh = getHeightRec1(node->pRight);
    return (lh > rh ? lh : rh) + 1;
}
int getBalance1(Node *subroot)
{
    if (!subroot)
        return 0;
    return getHeightRec1(subroot->pLeft) - getHeightRec1(subroot->pRight);
}
Node *minValueNode(Node *node)
{
    Node *current = node;

    while (current->pRight != NULL)
        current = current->pRight;

    return current;
}
Node *deleteNode(Node *root, const T &key)
{

    if (root == NULL)
        return root;

    if (key < root->data)
        root->pLeft = deleteNode(root->pLeft, key);

    else if (key > root->data)
        root->pRight = deleteNode(root->pRight, key);

    else
    {
        if ((root->pLeft == NULL) ||
            (root->pRight == NULL))
        {
            Node *temp = root->pLeft ? root->pLeft : root->pRight;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            free(temp);
        }
        else
        {
            Node *temp = minValueNode(root->pLeft);

            root->data = temp->data;

            root->pLeft = deleteNode(root->pLeft,
                                     temp->data);
        }
    }

    if (root == NULL)
        return root;

    int balance = getBalance1(root);

    if (balance > 1 &&
        getBalance1(root->pLeft) >= 0)
        return rotateRight1(root);

    if (balance > 1 &&
        getBalance1(root->pLeft) < 0)
    {
        root->pLeft = rotateLeft1(root->pLeft);
        return rotateRight1(root);
    }

    if (balance < -1 &&
        getBalance1(root->pRight) <= 0)
        return rotateLeft1(root);

    if (balance < -1 &&
        getBalance1(root->pRight) > 0)
    {
        root->pRight = rotateRight1(root->pRight);
        return rotateLeft1(root);
    }

    return root;
}

void remove(const T &value)
{
    this->root = deleteNode(this->root, value);
}