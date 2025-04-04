int pairMatching(vector<int>& nums, int target) {
    unordered_map<int, int> count;
    int pairCount = 0;
    for (int num : nums) {
        if (count.find(target - num) != count.end() && count[target - num] > 0) {
            pairCount++;
            count[target - num]--;
        } else {
            count[num]++;
        }
    }
    return pairCount;
}