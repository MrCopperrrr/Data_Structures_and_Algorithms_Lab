    int countTwoChildrenNode()
    {
        return countTwoChildrenNodeHelper(root);
    }


    int countTwoChildrenNodeHelper(Node* node)
    {
        if (node == nullptr)
            return 0;

        int count = 0;
        if (node->pLeft && node->pRight)
            count = 1;

        return count + countTwoChildrenNodeHelper(node->pLeft) + countTwoChildrenNodeHelper(node->pRight);
    }

