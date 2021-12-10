#include <iostream>
#include "../lib/UniversalNode.h"

/*List::List(Matrix *a) {
  Node *tmp = new Node(a);
  tmp->field = a;
  tmp->next = tmp;
}*/

template<typename T>
void UniversalList<T>::del() {
  Node *tmp = head;
  if (head != nullptr && tmp != nullptr) {
    head = head->next;
    size--;
    delete tmp;
  }
}

template<typename T>
void UniversalList<T>::add_by_pos(T *a, unsigned int pos) {
  if (pos == 0)
    add(a);
  else {
    Node *tmp = head;
    for (int i = 0; i < pos - 1; i++) {
      if (tmp->next == nullptr)
        throw out_of_range("Out of list range");
      tmp = tmp->next;
    }
    Node *elem = new Node;
    elem->next = tmp->next;
    tmp->next = elem;
  }
  size++;
}

template<typename T>
void UniversalList<T>::del_by_pos(unsigned int pos) {
  if (pos == 0) {
    if (head != nullptr) {
      Node *tmp = head->next;
      delete head;
      head = tmp;
    }
  } else {
    Node *tmp = head;
    for (int i = 0; i < pos - 1; ++i) {
      if (tmp->next == nullptr) {
        throw out_of_range("Out of list range");
      }
      tmp = tmp->next;
    }
    Node *elem = tmp->next;
    tmp->next = tmp->next->next;
    delete elem;
  }
  size--;
}

template<typename T>
void UniversalList<T>::add(T *field) {
  Node *tmp = new Node;
  tmp->next = head;
  tmp->field = field;
  if (head != nullptr) {
    tail->next = tmp;
    tail = tmp;
  } else {
    head = tail = tmp;
  }
  size++;
}

template<typename T>
void UniversalList<T>::show(int size) {
  Node *tmp_head = head;
  int tmp = size;
  while (tmp != 0) {
    std::cout << tmp_head->field->get_matrix() << " ";
    tmp_head = tmp_head->next;
    tmp--;
  }
}

template<typename T>
int UniversalList<T>::count() {
  return size;
}

template<typename T>
UniversalList<T>::~UniversalList() {
  while (size != 0) {
    Node *tmp = head->next;
    delete head;
    head = tmp;
    size--;
  }
}

template<typename T>
Matrix &UniversalList<T>::operator[](int d) {
  Node *tmp = head;
  for (int i = 0; i < d; ++i) {
    if (tmp->next == nullptr)
      throw out_of_range("Out of list range");
    tmp = tmp->next;
  }
  head->field = tmp->field;
  return *(tmp->field);

}
