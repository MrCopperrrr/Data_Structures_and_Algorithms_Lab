bool consecutiveOnes(vector<int>& nums) {
    // STUDENT ANSWER
    bool appear_1=false;
    bool appear_other_after_1=false;
    
    for (int i=0;i<nums.size();i++){
        if (nums[i]==1){
            if (appear_other_after_1) return false;
            appear_1=true;
        }
        else {
            if (appear_1){
                appear_other_after_1=true;
            }
        }
        
    }

    return true;
}