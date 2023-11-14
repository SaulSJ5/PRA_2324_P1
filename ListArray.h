#include <ostream>
#include "List.h"
#include <vector>
#include <iostream>

template <typename T>

class ListArray : public List<T> {

 private:
  T* arr;
  int max;
  int n;
  static const int MINSIZE = 2;


 public:


  void insert(int pos, T e) override{
    if (pos < 0 || pos > max-1) {
      throw std::out_of_range("Índice fuera de los límites de la lista");
    }
    if (n == max) {
      resize(1 + max);
    }
    for (int i = n; i > pos; i--) {
      arr[i] = arr[i - 1];
    }
    arr[pos] = e;
    n++;
  }
  
  void append(T e) override{
    
    if (n == max) {
      resize(1 + max);
    }
    arr[n] = e;
    n++;
  }
  
  void prepend(T e) override{
    
    if (n == max) {
      resize(1 + max);
    }
    for (int i = n; i > 0; i--) {
      arr[i] = arr[i - 1];
    }
    arr[0] = e;
    n++;
  }
  
  T remove(int pos) override{
   if (pos < 0 || pos > n-1) {
      throw std::out_of_range("Índice fuera de los límites de la lista");
    }
   T m = arr[pos];
   
   for(int i = pos; i < max; i++){
     arr[i] = arr[i + 1];
   }
   max--;
   n--;
   resize(max);
   return m;
  }
  
  T get(int pos) override{
    

    if (pos < 0 || pos > n-1) {
      throw std::out_of_range("Índice fuera de los límites de la lista");
    }
 
     return arr[pos];
  }
  
  int search(T e) override{
    int i= 0;
    while(arr[i]!= e){
      i++;
      if(i >= max){
	return -1;
	  }
    }
    return i;
  }
  
  int size() override{
    

    return n;
  }
  
  bool empty() override{

     return n == 0;   
  }
  
  ListArray(){
 arr = new T[MINSIZE];
  max = MINSIZE;
n = 0;
}

  ~ListArray(){
  delete[] arr;
}

  T operator[](int pos){

  
  if(pos < 0 || pos >= max){
    throw std::out_of_range("Índice fuera de los límites del array");
    
  }
  else{
    return arr[pos];
  }
 

}
  
  friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
  int i;
  out << "[";
    for (int i = 0; i < list.max; ++i) {
        out << list.arr[i];
        if (i < list.max-1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
  
    }

  
 void resize(int new_size){
  T* m = new T[new_size];

  for(int i = 0; i < n; i++){
    m[i] = arr[i];
  }

  delete[] arr;
  max = new_size;
  arr = m;

  
  }
 
};















