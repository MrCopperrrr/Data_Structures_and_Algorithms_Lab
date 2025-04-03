void push(T item) {
    this->list.add(item);
}

T pop() {
    if (!list.empty()) {
            return list.removeAt(0); 
        }
        throw std::out_of_range("Queue is empty!");
}

T top() {
    if (!list.empty()) {
            return list.get(0);  
        }
        throw std::out_of_range("Queue is empty!");
}

bool empty() {
    return this->list.empty();
}

int size() {
    return this->list.size();
}

void clear() {
    this->list.clear();
}
