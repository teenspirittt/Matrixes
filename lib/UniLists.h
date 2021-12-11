#ifndef MATRIXES__UNIVERSALNODE_H_
#define MATRIXES__UNIVERSALNODE_H_

#include "Matrix.h"

template<typename T>

class UniversalList {
 public:
  UniversalList() : head(nullptr), tail(nullptr), size(0) {};
  ~UniversalList();
  void add(T *field);
  void add(T *a, unsigned int pos);
  void del();
  void del(unsigned int pos);
  void show();
  int count();
  T &operator[](int d);
 private:
  struct Node {
    T *field;
    struct Node *next;
  };
  Node *head;
  Node *tail;
  unsigned int size;
};


#include "../src/UniLists.inl"



#endif //MATRIXES__UNIVERSALNODE_H_

