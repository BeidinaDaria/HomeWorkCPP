#pragma once
#include <iostream>
#include <ostream>

template<typename T>
class List{
    class Node {
    public:
        T data;
        Node* prev;
        Node* next;
    public:
        Node(T data) {
            this->data = data;
            this->prev = this->next = nullptr;
        }
    };
    Node* head;
    Node* tail;
public:
    List() {
        this->head = this->tail = nullptr;
    }
    List(T arr[], int size):List() {
        for (int i = 0; i < size; i++)
            push_back(arr[i]);
    }
    friend std::ostream& operator<<(std::ostream & os, const List<T>& l) {
        Node* n = l.head;
        while (n != l.tail) {
            os << n->data << " ";
            n = n->next;
        }
        os << n->data<<std::endl;
        return os;
    }
    int size() {
        int i = 0;
        Node* n = head;
        while (n != nullptr) {
            i++;
            n = n->next;
        }
        return i;
    }
    void push_front(T data) {
        Node* n = new Node(data);
        n->next = head;
        if (head != nullptr)
            head->prev = n;
        if (tail == nullptr)
            tail = n;
        head = n;
    }
    void push_back(T data) {
        Node* n = new Node(data);
        n->prev = tail;
        if (tail != nullptr)
            tail->next = n;
        if (head == nullptr)
            head = n;
        tail = n;
    }
    void pop_front() {
        if (head == nullptr) return;
        Node* n = head->next;
        if (n != nullptr)
            n->prev = nullptr;
        else
            tail = nullptr;
        delete head;
        head = n;
    }
    void pop_back() {
        if (tail == nullptr) return;
        Node* n = tail->prev;
        if (n != nullptr)
            n->next = nullptr;
        else
            head = nullptr;
        delete tail;
        tail = n;
    }
    T operator [] (int index) {
        if (index < 0)return NULL;
        Node* n = head;
        int i = 0;
        while (i != index) {
            if (n == nullptr)
                return NULL;
            n = n->next;
            i++;
        }
        return n->data;
    }
    void insert(int index, T data) {
        if (index == 0) {
            push_front(data);
            return;
        }
        Node* n = head;
        int i = 0;
        while ((n != nullptr) && (i < index)) {
            i++;
            n = n->next;
        }
        if (n == nullptr)
            return push_back(data);
        Node* left = n->prev;
        if (left == nullptr)
            return push_front(data);
        Node* p = new Node(data);
        p->prev = left;
        p->next = n;
        left->next = p;
        n->prev = p;
    }
    void erase(int index) {
        if (index == 0) {
            pop_front();
            return;
        }
        Node* n = head;
        int i = 0;
        while ((n != nullptr) && (i < index)) {
            i++;
            n = n->next;
        }
        if (n->prev == NULL) {
            pop_front();
            return;
        }
        if (n->next == NULL) {
            pop_back();
            return;
        }
        Node* left = n->prev;
        Node* right = n->next;
        left->next = right;
        right->prev = left;
        delete n;
    }
    ~List() {
        while (head != nullptr)
            pop_front();
    }
    //Развернуть список в обратном направлении, меняя указатели на элементы. 
    void reverse() {
        int s = size();
        int i = 0;
        Node* l1 = head;
        Node* l2 = tail;
        while (i<s/2) {
            T buf = l1->data;
            l1->data = l2->data;
            l2->data = buf;
            l1 = l1->next;
            l2 = l2->prev;
            i++;
        }
    }
};