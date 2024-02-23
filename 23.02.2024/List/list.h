#pragma once
#include <iostream>
#include <ostream>
#include <tuple>

template <typename T>
class Node {
public:
	template <typename T>
	struct mynode {
	public:
		T data;
		mynode<T>* previous;
		mynode<T>* next;
		mynode(T d, mynode<T>* p, mynode<T>* n) : data(d), previous(p), next(n) {}
	};
	mynode<T>* first;
	Node<T>(T d) {
		mynode<T> f = mynode<T>(d, nullptr, nullptr);
		first = &f;
	}
	Node<T>(T d, mynode<T>* p, mynode<T>* n) {
		mynode<T> m = mynode<T>(d, p, n);
		first = &m;
	}
	T& operator*() { return first->data; }
	Node<T>& operator++() {
		first = first->next;
		return *this;
	}
	Node<T>& operator--() {
		first = first->previous;
		return *this;
	}
	Node<T>* previous() {
		Node<T> res = Node<T>(first->data, first, first);
		if (first->previous != nullptr)
			res.first = first->previous;
		return &res;
	}
	friend bool operator==(Node<T> n1, Node<T> n2) {
		return n1.first == n2.first;
	}
	friend bool operator!=(Node<T> n1, Node<T> n2) {
		return !(n1 == n2);
	}
	friend std::ostream& operator<<(std::ostream& os, Node<T> n) {
		os << n.first->data;
		return os;
	}
};

template <typename T>
class List {
	Node<T>* first;
	Node<T>* last;
public:
	List<T>() {
		Node<T> l = Node<T>(0);
		first = &l;
		Node<T> m=Node<T>(0, first->first, first->first);
		last = &m;
		first->first->previous = last->first;
		first->first->next= last->first;
	}
	void push_back(T d) {
		if (first->first->data == 0)
			first->first->data = d;
		else {
			last->first->data = d;
			Node<T>* n = last;
			n->first->next = last->first;
			last->first->previous = n->first;
		}
	}
	Node<T>* begin() { return first; }
	Node<T>* end() { return last->previous();}
	//Развернуть список в обратном направлении, меняя указатели на элементы. 
	void reverse() {
		Node<T>* l1 = begin();
		Node<T>* l2 = end();
		while (l1 != l2) {
			std::swap(l1.data, l2.data);
			++l1;
			--l2;
		}
	}
	friend std::ostream& operator<<(std::ostream& os, List<T> l) {
		auto n = l.begin();
		while (n != nullptr) {
			os << n;
			n++;
		}
		return os;
	}
};