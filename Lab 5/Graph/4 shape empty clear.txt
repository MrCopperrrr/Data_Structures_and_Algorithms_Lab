template<class T>
string DGraph<T>::shape() {
    return "[Vertices: " + to_string(this->countVertex) + ", Edges: " + to_string(this->countEdge) + "]";
}

template<class T>
bool DGraph<T>::empty() {
    return this->countVertex == 0 && this->countEdge == 0;
}

template<class T>
void DGraph<T>::clear() {
    VertexNode* current = this->nodeList;
    while (current != nullptr) {
        VertexNode* temp = current;
        current = current->next;
        delete temp;
    }
    this->nodeList = nullptr;
    this->countVertex = 0;
    this->countEdge = 0;
}
