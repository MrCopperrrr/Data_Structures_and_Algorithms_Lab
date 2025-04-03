template<class T>
typename DGraph<T>::Edge* DGraph<T>::VertexNode::getEdge(VertexNode* toNode) {
    Edge* current = this->adList;
    while (current != nullptr) {
        if (current->toNode == toNode) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template<class T>
void DGraph<T>::VertexNode::addAdjacentEdge(Edge* newEdge) {
    newEdge->next = this->adList;
    this->adList = newEdge;
}

template<class T>
bool DGraph<T>::VertexNode::connectTo(VertexNode* toNode, float weight) {
    Edge* existingEdge = getEdge(toNode);
    if (existingEdge == nullptr) {
        Edge* newEdge = new Edge(this, toNode, weight);
        addAdjacentEdge(newEdge);
        return true;
    } else {
        existingEdge->weight = weight;
        return false;
    }
}

template<class T>
bool DGraph<T>::VertexNode::removeTo(VertexNode* toNode) {
    Edge* current = this->adList;
    Edge* prev = nullptr;
    while (current != nullptr) {
        if (current->toNode == toNode) {
            if (prev == nullptr) {
                this->adList = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}
