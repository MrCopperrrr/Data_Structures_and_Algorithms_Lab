template <class T>
void SLinkedList<T>::bubbleSort()
{
    if (!head || !head->next)
        return; 
    bool swapped;
    Node *ptr1;
    Node *lptr = nullptr;

    do
    {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                // Swap the data of the nodes
                T temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;

        // Print the list only if a swap has been made
        if (swapped)
        {
            printList();
        }

    } while (swapped);
}
