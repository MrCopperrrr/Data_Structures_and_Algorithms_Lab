void push(T item) {
    list.add(item);
}

T pop() {
    if(list.empty()){
        throw runtime_error("EmptyQueueException");
    }
    return list.removeAt(0);
}

T top() {
     if(list.empty()){
         throw std::runtime_error("EmptyQueueException");
     }   
     return list.get(0);
}

bool empty() {
    return list.empty();
}

int size() {
    return list.size();
}

void clear() {
    list.clear();
}