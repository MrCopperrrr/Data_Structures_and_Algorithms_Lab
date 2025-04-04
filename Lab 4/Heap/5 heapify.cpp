static void heapify(T* arr, int n, int i){
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && arr[left] > arr[largest])
            largest = left;
        if(right < n && arr[right] > arr[largest])
            largest = right;
        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    static void heapSort(T* start, T* end){
        int n = end - start;
        
        // Build heap
        for(int i = n/2 - 1; i >= 0; i--)
            heapify(start, n, i);
        
        // One by one extract elements
        for(int i = n - 1; i >= 0; i--){
            swap(start[0], start[i]);
            heapify(start, i, 0);
        }

        Sorting<T>::printArray(start, end);
    }