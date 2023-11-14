#include <ostream>
#include "List.h"
#include "Node.h"
#include <iostream>

template <typename T>
class ListLinked : public List<T> {

    private:
 
     	Node<T>* first;
	int n;

    public:
	
	ListLinked(){

	  this->n = 0;
	  first = nullptr;
	}

	
	~ListLinked(){

	  while(first !=  nullptr){
	    Node<T>* aux = first;
	    first = first->next;
	    delete aux;
	  }

	}
	
	T operator[](int pos){

	  int i;
	  Node<T>* aux = first;
	  if(pos<0 || pos> n-1){
	    throw std::out_of_range("Posición fuera del rango");
	  }
	  else{
	  for(i = 0;i<pos;i++){
		  aux = aux->next;
		}
		return aux->data;
	}
	}
	  
	  friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){

	    int i;
	    Node<T>* aux = list.first;
	    
	    for(i = 0; i < list.n; i++){
	      out<<aux->data;	
	      out<<" ";
	      aux = aux->next;
	    }
	    return out;
	  }


	  void insert(int pos, T e) override{
	    
	    Node<T>* nuevoNodo = new Node<T>(e);
	    if (pos < 0 || pos > n) {
	      throw std::out_of_range("Posición fuera del rango");
	    }
	    if(pos == 0){
	      prepend(e);
	    }
	    else if(pos == n){
	      append(e);
	    }
	    else{
	      
	      Node<T>* aux1 = first;
	      Node<T>* aux2 = first->next;
	      
	      for(int i = 1; i < pos; i++){
		aux1 = aux2;
		aux2 = aux2->next;
	      }
	      aux1->next = nuevoNodo;
	      nuevoNodo->next = aux2;
	      n++;
	    }
	  }

	  
  void append(T e) override{
	    Node<T>* aux = first;
	    Node<T>* nuevoNodo = new Node<T>(e);
	    if(aux == nullptr){
	      first = nuevoNodo;
	    }
	    else{
	      while (aux->next != nullptr) {
	      aux = aux->next;
	      }
	      aux->next = nuevoNodo;
	    }
	    n++;
	  }
	    
       
	  void prepend(T e) override{
	    
	    Node<T>* nuevoNodo = new Node<T>(e);
	  
	    if (first == nullptr) {
	      first = nuevoNodo;
	      nuevoNodo->next = nullptr;
	    } else {
       
	      nuevoNodo->next = first;
	      first = nuevoNodo;
	    }

	    n++;
	  }
	  
	  T remove(int pos) override{
	    if (pos < 0 || pos >= n) {
	      throw std::out_of_range("Posición fuera del rango");
	    }
	    T m;
	    Node<T>* aux1 = first;
	    Node<T>* aux2 = first->next;
	    
	    if(pos == 0){
	      m = first->data;
	      first = aux2;
	      delete aux1;
	    }
	    else{
	      for (int i = 1; i < pos; i++) {
		aux1 = aux2;
		aux2 = aux2->next;
	      }

	      aux1->next = aux2->next;
	      m = aux2->data;
	      delete aux2;
	    }
	    n--;
	    return m;
	  }
  
	  T get(int pos) override{

	    if (pos < 0 || pos >= n) {
	      throw std::out_of_range("Posición fuera del rango");
	    }
	    Node<T>* aux = first;
	    int i = 0;

	    while (aux != nullptr && i < pos) {
	      aux = aux->next;
	      i++;
	    }
	    return aux->data;
	  
	  }
	  
	  int search(T e) override{
	     Node<T>* aux = first;
	     int i = 0;
	     
	     while(aux!= nullptr && aux->data != e){
	       aux = aux->next;
	       i++;
	     }
	     if(aux != nullptr){
	       return i;
	     }
	     else{
	       return -1;
	     }
	     
	  }
	  
	  int size() override{
	    return n;
	  }
	  bool empty() override{
	    return n == 0;
	  }

	

};
