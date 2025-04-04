template <class T>
bool DGraph<T>::removeEdge(T from, T to) {
    VertexNode* fromNode = getVertexNode(from);
    VertexNode* toNode = getVertexNode(to);

    if (!fromNode || !toNode) {
        throw VertexNotFoundException("Vertex doesn't exist!");
    }

    if (fromNode->removeTo(toNode)) {
        countEdge--;
        return true;
    }
    return false;
}

template <class T>
void DGraph<T>::removeVertex(T removeVertex) {
VertexNode* removeNode = getVertexNode(removeVertex);
    if (removeNode == nullptr) {
        throw VertexNotFoundException("Vertex doesn't exist!");
    }
    
    VertexNode* current = nodeList;
    while (current != nullptr) {
        if (current->removeTo(removeNode)) {
            countEdge--; 
        }
        if (removeNode->removeTo(current)) {
            countEdge--; 
        }
        current = current->next; 
    }
    
    if (this->nodeList == removeNode) nodeList = nodeList->next;
    else {
        VertexNode* previous = nullptr;
        current = this->nodeList;
        while (current != removeNode) {
            previous = current;
            current = current->next;
        }
        previous->next = removeNode->next;
    }
    
    delete removeNode; 
    countVertex--;
}