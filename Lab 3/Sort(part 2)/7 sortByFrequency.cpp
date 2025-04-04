#include <vector>
void sortByFrequency(int arr[], int n) {
    vector<pair<int, int>> freq;

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (size_t j = 0; j < freq.size(); j++) {
            if (freq[j].first == arr[i]) {
                freq[j].second++;  // Increase frequency
                found = true;
                break;
            }
        }
        if (!found) {
            freq.push_back(make_pair(arr[i], 1));  // Add new element with count 1
        }
    }

    stable_sort(freq.begin(), freq.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;  // Sort by frequency in descending order
    });

    int index = 0;
    for (const auto& p : freq) {
        for (int i = 0; i < p.second; i++) {
            arr[index++] = p.first;
        }
    }
}