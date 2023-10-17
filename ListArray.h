#include <ostream>
#include "List.h"
#include <algorithm>

template <typename T>

class ListArray : public List<T> {

 private:
  T* arr;
  int max;
  int n;
  static const int MINSIZE = 2;

  void resize(int new_size);

 public:
  ListArray();
  
  ~ListArray();
  
  T operator[](int pos);
  
  friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);


  void insert(int pos, T e) override{

    if (pos >= 0 && pos < n) {
      arr[pos] = e;
    }
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
      resize(2 * max);
    }
    for (int i = n; i > 0; i--) {
      arr[i] = arr[i - 1];
    }
    arr[0] = e;
    n++;
  }
  
  T remove(int pos) override{

    	 T aux;
	int i;
  	if (pos < 0 || pos >= n) {
      throw std::out_of_range("Índice fuera de los límites de la lista");
    	}
   	 T aux = arr[pos];
	arr[pos]=nullptr;
    	for (i = pos; i < n - 1; i++) {
    	  arr[i] = arr[i + 1];
   	 }
	arr[max-1]=nullptr;
   	 n--;
   	 return aux;
  }
  
  T get(int pos) override{
    T aux;

if (pos < 0 || pos >= n) {
      throw std::out_of_range("Índice fuera de los límites de la lista");
    }
     aux = arr[pos];
 
     return aux;
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
    int i,j = 0;
    
    for(i = 0; i<max;i++){
      if(arr[i]!='/0'){
	j++;   
      }
    }

    return j;
  }
  
  bool empty() override{

     return n == 0;   
  }
  
  
};

template <typename T>
ListArray<T>::ListArray(){
 arr = new T[MINSIZE];
  max = MINSIZE;
n = 0;
}

template <typename T>
ListArray<T>::~ListArray(){
  delete[] arr;
}



template <typename T>
T ListArray<T>::operator[](int pos){

  try{
  if(pos < 0 || pos >= max){
    throw std::out_of_range("Índice fuera de los límites del array");
    
  }
  else{
    return arr[pos];
  }
  }
  catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

}

template <typename T>
std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
  int i;
  out << "[";
    for (int i = 0; i < max; ++i) {
        out << arr[i];
        if (i < max-1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
  
}

 void ListArray<T>::resize(int new_size){
  int* m = new int[new_size];

  for(int i = 0; i< n; i++){
	m[i] = arr[i];
}

  delete[] arr;

  arr = m;

  max = new_size;
  }

