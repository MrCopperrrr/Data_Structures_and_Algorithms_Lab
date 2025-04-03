void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < numberOfElements && maxHeap[leftChild] > maxHeap[largest])
        largest = leftChild;
    if (rightChild < numberOfElements && maxHeap[rightChild] > maxHeap[largest])
        largest = rightChild;

    if (largest != index) {
        swap(maxHeap[index], maxHeap[largest]);
        reheapDown(maxHeap, numberOfElements, largest);
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    if (index == 0)
        return;

    int parent = (index - 1) / 2;
    if (maxHeap[index] > maxHeap[parent]) {
        swap(maxHeap[index], maxHeap[parent]);
        reheapUp(maxHeap, numberOfElements, parent);
    }
}