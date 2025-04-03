vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations) {
    // STUDENT ANSWER
    int len=operations.size();
    for(int i =0;i<len;i++){
        int L=operations[i][0];
        int R=operations[i][1];
        int X=operations[i][2];
        for(int j=L;j<=R;j++){
            nums[j]+=X;
        }
    
    }
    return nums;
}