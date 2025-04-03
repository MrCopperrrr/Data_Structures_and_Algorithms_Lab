template<class T>
void ArrayList<T>::ensureCapacity(int cap){
  if(cap<0){
    throw std::out_of_range("Index is out of range!");
  }
  if (cap >=capacity) {
    try{
      int newCapacity = capacity * 2 + 1;
      T* newData = new T[newCapacity];
      for (int i = 0; i < count; i++) {
        newData[i] = data[i];
      }
      delete[] data;
      data = newData;
      capacity = newCapacity;
    } catch (const std::bad_alloc& ) {}
  }
}


template <class T>
void ArrayList<T>::add(T e) {
    /* Insert an element into the end of the array. */
    ensureCapacity(count);//kiểm tra xem có đủ chỗ không nếu khong thì tăng capacity count+1
  data[count] = e;//chèn e vào cuối mảng
  count++;//tăng số phần tử
}

template<class T>
void ArrayList<T>::add(int index, T e) {
  if (index < 0 || index > count) { // Check the index bounds
    throw std::out_of_range("Index is out of range!");
  }
  ensureCapacity(count);//kiểm tra xem có đủ chỗ không nếu khong thì tăng capacity count+1
  for (int i = count; i > index; i--) {//duyệt từ count đến index
    data[i] = data[i - 1];//gán giá trị từ i-1 sang i
  }
  data[index] = e;//gán giá trị
  count++;//tăng count lên 1
}

template<class T>
int ArrayList<T>::size() {
    /* Return the length (size) of the array */ 
      return count;//trả về count

    
}
