#include <ostream>
#include "List.h"

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


  void insert(int pos, T e) override;
  void append(T e) override;
  void prepend(T e) override;
  T remove(int pos) override;
  T get(int pos) override;
  int search(T e) override;
  int size() override;
  bool empty() override;
  
  
};

ListArray::ListArray(){

}

ListArray::~ListArray(){}

template <typename T>
void List<T>::insert(int pos, T e) override{
  try{    
    this-> arr[pos]=e;
  }
  catch(const std::out_of_range& oor) {
    std::cerr << "Out of Range error: " << oor.what() << '\n';
  }

}
  
  template <typename T>       
  void List<T>::append(T e) override{
    this->arr[max-1] = e;
  }


 template <typename T>       
  void List<T>::prepend(T e) override{
    this->arr[0] = e;
  }


 template <typename T>
 T List<T>::remove(int pos) override{
   T aux;
   try{
     aux = arr[pos];
    this-> arr[pos]= '/0';
  }
  catch(const std::out_of_range& oor) {
    std::cerr << "Out of Range error: " << oor.what() << '\n';
  }
  return aux;
 }



template <typename T>
 T List<T>::get(int pos) override{
   T aux;
   try{
     aux = arr[pos];
  }
  catch(const std::out_of_range& oor) {
    std::cerr << "Out of Range error: " << oor.what() << '\n';
  }
  return aux;
 }

template <typename T>
int List<T>::search(T e) override{
  int i= 0;
  while(arr[i]!= e){
     i++;
    if(i >= max){
      return -1
    }
  }
  return i;
}

template <typename T>
int List<T>::size() override{
  int i,j = 0;
  for(i = 0; i<max;i++){
    if(arr[i]!='/0'){
      j++;   
    }
  }

  return j;
}

template <typename T>
bool List<T>::empty() override{
  int i;
  for(i = 0; i<max; i++){
   if(arr[i]!='/0'){
     return false;   
    }
  }

  return true;
}

