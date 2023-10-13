#include <ostream>

template <typename T> 
class Node {
    public:
  T data;
  Node<T>* next
    Node(T data, Node<T>* next = nullptr);
  friend std::ostream& operator<<(std::ostream &out, const Node<T> &node);


  void insert(int pos, T e) override;
  void append(T e) override;
  void prepend(T e) override;
  T remove(int pos) override;
  T get(int pos) override;
  int search(T e) override;
  int size() override;
  bool empty() override;
  
};
