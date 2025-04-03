template<class T>
int Heap<T>::getItem(T item) {
    for (int i = 0; i < count; i++) {
        if (elements[i] == item)
            return i;
    }
    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    int index = getItem(item);
    if (index == -1)
        return; // Item not found
    elements[index] = elements[count - 1];
    count--;
    if (index > 0 && elements[index] > elements[(index - 1)/2]) {
        reheapUp(index);
    } else {
        reheapDown(index);
    }
}
template<class T>
void Heap<T>::clear() {
    delete [] elements;
    capacity = 10;
    count = 0;
    elements = new T[capacity];
}