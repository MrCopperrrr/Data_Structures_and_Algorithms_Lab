static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total) {
        int size = end - start;
        for (int i = segment_idx + cur_segment_total; i < size; i += cur_segment_total) {
            T key = start[i];
            int j = i - cur_segment_total;
            while (j >= segment_idx && start[j] > key) {
                start[j + cur_segment_total] = start[j];
                j -= cur_segment_total;
            }
            start[j + cur_segment_total] = key;
        }
    }

    // Shell sort using segment lists for each phase.
    static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) {
        // Start sorting with the largest segments first (reverse order)
        for (int phase = num_phases - 1; phase >= 0; --phase) {
            int cur_segment_total = num_segment_list[phase];
            for (int segment_idx = 0; segment_idx < cur_segment_total; ++segment_idx) {
                sortSegment(start, end, segment_idx, cur_segment_total);
            }
            cout << cur_segment_total << " segments: ";
            printArray(start, end);
        }
    }