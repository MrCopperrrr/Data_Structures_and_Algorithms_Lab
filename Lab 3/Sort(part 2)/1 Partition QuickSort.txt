static T* Partition(T* start, T* end) {
    // TODO: return the pointer which points to the pivot after rearrange the array.
    T pivot = *start;
    T* i = start + 1;
    T* j = end - 1;

    while (true) {
        while (i <= j && *i <= pivot) ++i;
        while (i <= j && *j > pivot) --j;
        if (i >= j) break;
        swap(*i, *j);
    }

    swap(*start, *j);
    return j;
}

static void QuickSort(T* start, T* end) {
    // TODO
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
     if (start < end) {
        T* index = Partition(start, end);
        cout << (index - start) << " ";
        QuickSort(start, index);
        QuickSort(index + 1, end);
    }
}