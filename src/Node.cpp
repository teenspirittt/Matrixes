#include <iostream>
#include "../lib/Node.h"

/*List::List(Matrix *a) {
  Node *tmp = new Node(a);
  tmp->field = a;
  tmp->next = tmp;
}*/


void List::del()
{
	Node* tmp = head;
	if (head!=nullptr && tmp!=nullptr) {
		head = head->next;
		size--;
		delete tmp;
	}
}

void List::add(Matrix* field)
{
	Node* tmp = new Node;
	tmp->next = head;
	tmp->field = field;
	if (head!=nullptr) {
		tail->next = tmp;
		tail = tmp;
	}
	else {
		head = tail = tmp;
	}
	size++;
}

void List::add(Matrix* a, unsigned int pos)
{
	if (pos==0)
		add(a);
	else {
		Node* tmp = new Node;
		tmp->field = a;
		tmp->next = head;
		Node* prev = head;
		for (unsigned int i = size; i>pos-1; i--) {
			prev = prev->next;
		}
		Node* elem = prev->next;
		prev->next = tmp;
		tmp->next = elem;
	}
	size++;
}

void List::del(unsigned int pos)
{
	if (pos==0) {
		if (head!=nullptr) {
			Node* tmp = head->next;
			delete head;
			head = tmp;
		}
	}
	else {
		Node* tmp = head;
		for (int i = 0; i<pos-1; ++i) {
			if (tmp->next==nullptr) {
				throw out_of_range("Out of list range");
			}
			tmp = tmp->next;
		}
		Node* elem = tmp->next;
		tmp->next = tmp->next->next;
		delete elem;
	}
	size--;
}

void List::show()
{
	Node* tmp_head = head;
	int tmp = size;
	while (tmp!=0) {
		std::cout << tmp_head->field->get_matrix();
		tmp_head = tmp_head->next;
		tmp--;
	}
}

int List::count() const
{
	return size;
}

List::~List()
{
	while (size!=0) {
		Node* tmp = head->next;
		delete head;
		head = tmp;
		size--;
	}
}

Matrix& List::operator[](int d)
{
	Node* tmp = head;
	for (int i = 0; i<d; ++i) {
		if (tmp->next==nullptr)
			throw out_of_range("Out of list range");
		tmp = tmp->next;
	}
	return *(tmp->field);
}

/*
List::Node::~Node ()
{
  delete field;
}
*/
