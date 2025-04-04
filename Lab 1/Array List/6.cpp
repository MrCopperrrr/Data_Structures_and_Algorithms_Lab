int buyCar(int* nums, int length, int k) {
sort (nums,nums+length);

int car_capacity=0;
int total=0;

for (int i=0;i<length;i++){
    if (total+nums[i]<=k){
        total+=nums[i];
        car_capacity++;
    }
    else break;
}
return car_capacity;
}