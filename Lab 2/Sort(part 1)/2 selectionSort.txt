template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    int size = end - start;
    for (int i = 0; i < size - 1; ++i)
    {
        // Find the minimum element in the unsorted part of the array
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (start[j] < start[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        if (minIndex != i)
        {
            T temp = start[i];
            start[i] = start[minIndex];
            start[minIndex] = temp;
        }

        // Print the array after each selection
        printArray(start, end);
    }
}
