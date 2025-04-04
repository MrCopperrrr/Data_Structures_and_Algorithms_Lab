SLL#5

template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList, bool begin)
{
    /*
        Constructor of iterator
        * Set pList to pList
        * begin = true: 
        * * Set current (index = 0) to pList's head if pList is not NULL
        * * Otherwise set to NULL (index = -1)
        * begin = false: 
        * * Always set current to NULL
        * * Set index to pList's size if pList is not NULL, otherwise 0
    */
    this->pList = pList;
    if (begin) {
        if (pList != nullptr && pList->head != nullptr) {
            this->current = pList->head;
            this->index = 0;
        } else {
            this->current = nullptr;
            this->index = -1;
        }
    } else {
        this->current = nullptr;
        this->index = (pList != nullptr) ? pList->size() : 0;
    }
}

template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator=(const Iterator& iterator)
{
    /*
        Assignment operator
        * Set this current, index, pList to iterator corresponding elements.
    */
    this->pList = iterator.pList;
    this->current = iterator.current;
    this->index = iterator.index;
    return *this;
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
    /*
        Remove a node which is pointed by current
        * After remove current points to the previous node of this position (or node with index - 1)
        * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
        * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
    */
     if (current == nullptr) {
        throw std::out_of_range("Segmentation fault!");
    }

    if (current == pList->head) {
        pList->head = current->next;
        delete current;
        current = nullptr;
        index = -1;
    } else {
        Node* prev = pList->head;
        while (prev->next != current) {
            prev = prev->next;
        }
        prev->next = current->next;
        delete current;
        current = prev;
        index--;
    }
    pList->count--;
}

template <class T>
void SLinkedList<T>::Iterator::set(const T& e)
{
    /*
        Set the new value for current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if (current == nullptr) {
        throw std::out_of_range("Segmentation fault!");
    }
    current->data = e;
}

template <class T>
T& SLinkedList<T>::Iterator::operator*()
{
    /*
        Get data stored in current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if (current == nullptr) {
        throw std::out_of_range("Segmentation fault!");
    }
    return current->data;
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& iterator)
{
    /*
        Operator not equals
        * Returns false if two iterators points the same node and index
    */
    return (this->current != iterator.current || this->index != iterator.index);
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator++()
{
    /*
        Prefix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    if (current == nullptr) {
        throw std::out_of_range("Segmentation fault!");
    }
    current = current->next;
    index++;
    return *this;
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
    /*
        Postfix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    Iterator temp = *this; // Lưu lại trạng thái hiện tại
    ++(*this);             // Gọi prefix ++ để di chuyển iterator tới nút tiếp theo
    return temp;   
}