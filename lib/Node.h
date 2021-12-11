#ifndef MATRIXES_LIB_NODE_H_
#define MATRIXES_LIB_NODE_H_

#include "Matrix.h"

class List {
 public:
  List() : head(nullptr), tail(nullptr), size(0) {};

  ~List();


  void add(Matrix *field);
  void add(Matrix *a, unsigned int pos);
  void del();
  void del(unsigned int pos);
  void show(int size);
  int count() const;
  Matrix &operator[](int d);
 private:
  struct Node {
    Matrix *field;
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

#endif //MATRIXES_LIB_NODE_H_
