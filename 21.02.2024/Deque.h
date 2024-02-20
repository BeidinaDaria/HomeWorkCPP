#pragma once
#include <iostream>
#include <ostream>

template<typename T>
class Deque{
	struct Node{
		T data;
		Node* next;
		Node* prev;
		Node(T data, Node* prev = nullptr, Node* next = nullptr):data(data), next(next), prev(prev){
			if (prev != nullptr)
				prev->next = this;

			if (next != nullptr)
				next->prev = this;
		}
	};
	Node* head=nullptr;
	Node* tail=nullptr;
public:
	Deque(){}
	Deque(T arr[], int count) {
		if (count < 0)
			throw std::exception("Unacceptable size!!!");
		if (count == 1) {
			head = new Node(arr[0]);
			tail = head;
			return;
		}
		head = new Node(arr[0], nullptr, tail);
		Node* n = head;
		for (int i = 1; i < count - 1; i++) {
			n->next = new Node(arr[i], n, tail);
			n = n->next;
		}
		tail = new Node(arr[count - 1], n, nullptr);
	}
	friend std::ostream& operator <<(std::ostream& os, const Deque<T>& q) {
		Deque::Node* p = q.head;
		while(p!=nullptr) {
			os << p->data << ", ";
			p = p->next;
		}
		os << std::endl;
		return os;
	}
	int size() {
		if (head == tail) {
			if (head == nullptr)
				return 0;
			else return 1;
		}
		int s = 1;
		Node* p = head;
		while (p != tail) {
			p = p->next;
			s++;
		}
		return s;
	}
	T front() {
		if (head == nullptr)
			return NULL;
		return head->data;
	}
	T back() {
		if (tail == nullptr)
			return NULL;
		return tail->data;
	}
	void push_front(T data) {
		if (head == nullptr) {
			head = new Node(data, nullptr, nullptr);
			tail = head;
			return;
		}
		Node* n = new Node(data, nullptr, head);
		head->prev = n;
		head = n;
	}
	void push_back(T data) {
		if (head == nullptr) {
			head = new Node(data, nullptr, nullptr);
			tail = head;
			return;
		}
		Node* n = new Node(data, tail, nullptr);
		tail->next = n;
		tail = n;
	}
	void pop_front() {
		if (head == nullptr) {
			return;
		}
		head = head->next;
		if (head != nullptr) {
			delete head->prev;
			head->prev = nullptr;
		}
	}
	void pop_back() {
		if (tail == nullptr) {
			return;
		}
		if (head == tail) {
			delete tail;
			head = nullptr;
			tail = nullptr;
			return;
		}
		tail = tail->prev;
		if (tail != nullptr) {
			delete tail->next;
			tail->next = nullptr;
		}
	}
	void clear() {
		if (head == nullptr)return;
		while (head != nullptr) pop_back();
	}
};