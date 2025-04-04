template<class T>
typename DGraph<T>::VertexNode* DGraph<T>::getVertexNode(T vertex) {
    VertexNode* current = this->nodeList;
    while (current != nullptr) {
        if (current->vertex == vertex) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template<class T>
void DGraph<T>::add(T vertex) {
    if (getVertexNode(vertex) != nullptr) {
        return; // Vertex already exists, do not add it again
    }
    VertexNode* newNode = new VertexNode(vertex);
    if (this->nodeList == nullptr) {
        this->nodeList = newNode;
    } else {
        VertexNode* current = this->nodeList;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    this->countVertex++;
}

template <class T>
void DGraph<T>::connect(T from, T to, float weight) {
    VertexNode* fromNode = getVertexNode(from);
    VertexNode* toNode = getVertexNode(to);
    if (fromNode == nullptr || toNode == nullptr) {
        throw VertexNotFoundException("Vertex doesn't exist!");
    }
    if (fromNode == toNode) {
        throw std::runtime_error("Self-loops are not allowed!");
    }
    if (fromNode->connectTo(toNode, weight)) {
        this->countEdge++;
    }
}