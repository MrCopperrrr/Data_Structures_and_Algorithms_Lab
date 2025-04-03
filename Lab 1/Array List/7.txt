int equalSumIndex(vector<int>& nums) {
    // STUDENT ANSWER
   int min_index=-1;
   int total=0,total_left=0,total_right;
    for (int i=0;i<nums.size();i++){
        total+=nums[i];
    }

    for(int i=0;i<nums.size();i++){
        total_right=total-total_left-nums[i];
        if (total_left==total_right){
            return i;
        }
        total_left+=nums[i];
    }

    return -1;
}