int findMax(int* arr, int length) {
    if (length == 1) {
        return arr[0];
    }
    int max=findMax(arr+1,length-1);
    return (arr[0]>max)?arr[0]:max;
    
}