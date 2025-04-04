#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <climits>
using namespace std;
string minDiffPairs(int* arr, int n){
    vector<int> nums(arr, arr + n);
    sort(nums.begin(), nums.end());

    int minDiff = INT_MAX;  
    for (int i = 1; i < n; i++) {
        minDiff = min(minDiff, nums[i] - nums[i-1]);
    }

    stringstream result;
    bool first = true;  
    for (int i = 1; i < n; i++) {
        if (nums[i] - nums[i-1] == minDiff) {
            if (!first) {
                result << ", ";  
            }
            result << "(" << nums[i-1] << ", " << nums[i] << ")";
            first = false;  
        }
    }

    return result.str();
}