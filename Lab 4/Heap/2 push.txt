template<class T>
void Heap<T>::push(T item){
    ensureCapacity(count + 1);
    elements[count] = item;
    reheapUp(count);
    count++;
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    if (capacity < minCapacity) {
        int newCapacity = capacity * 2;
        if (newCapacity < minCapacity)
            newCapacity = minCapacity;
        T* newElements = new T[newCapacity];
        for (int i = 0; i < count; i++) {
            newElements[i] = elements[i];
        }
        delete [] elements;
        elements = newElements;
        capacity = newCapacity;
    }
}

template<class T>
void Heap<T>::reheapUp(int position){
    if (position == 0)
        return;
    int parent = (position - 1) / 2;
    if (elements[position] > elements[parent]) {
        swap(elements[position], elements[parent]);
        reheapUp(parent);
    }
}