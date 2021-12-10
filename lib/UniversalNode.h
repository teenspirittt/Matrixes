#ifndef MATRIXES__UNIVERSALNODE_H_
#define MATRIXES__UNIVERSALNODE_H_

#include "Matrix.h"

template<typename T>

class UniversalList {
 public:
  UniversalList() : head(nullptr), tail(nullptr), size(0) {};
  UniversalList(T*a);
  ~UniversalList();
  void add_by_pos(T *a, unsigned int pos);
  void del_by_pos(unsigned int pos);
  void add(T *field);
  void del();
  void show(int size);
  int count();
  Matrix &operator[](int d);
 private:
  struct Node {
    T *field;
    struct Node *next;
    /* Node(Matrix *b) {
       field = b;
       next = tail;
     }
      //~Node();*/
  };
  Node *head;
  Node *tail;
  int size;
};



#endif //MATRIXES__UNIVERSALNODE_H_

