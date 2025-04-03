void push(T item) {
    list.add(item);
}

T pop() {
    if (list.empty()){
        throw std::runtime_error("EmptyStackException");
    }
    return list.removeAt(list.size()-1);    
}

T top() {
    if (list.empty()){
        throw std::runtime_error("EmptyStackException");
    }
    return list.get(list.size()-1);        
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