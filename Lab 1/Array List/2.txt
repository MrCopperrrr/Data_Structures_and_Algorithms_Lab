template<class T>
T ArrayList<T>::removeAt(int index){
    /*
    Remove element at index and return removed value 
    if index is invalid:
        throw std::out_of_range("index is out of range");
    */
    if(index<0|| index>=count)
    throw std::out_of_range("index is out of range");
    
    T res=data[index];
    for (int i=index+1;i<count;i++){
        data[i-1]=data[i];
    }
    count --;
    // 1 2 3 4 5 6 7 8
    // 1 2 4 5 6 7 8
    return res;
}

template<class T>
bool ArrayList<T>::removeItem(T item){
     /* Remove the first apperance of item in array and return true, otherwise return false */
     for (int i=0;i<count;i++){
         if (item==data[i]){
             removeAt(i);
             return true;
             }
     }
     return false;
}

template<class T>
void ArrayList<T>::clear(){
    while (count > 0) {
        removeAt(0); 
    }
    /* 
        Delete array if array is not NULL
        Create new array with: size = 0, capacity = 5
    */
    capacity = 5;
    data = new T[capacity];  
    count = 0;
}
