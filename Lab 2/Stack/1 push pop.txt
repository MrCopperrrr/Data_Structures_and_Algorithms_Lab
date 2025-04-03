void push(T item) {
    this->list.add(item);
}

T pop() {
    if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return this->list.removeAt(list.size() - 1);
}

T top() {
    if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return this->list.get(list.size() - 1);
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
