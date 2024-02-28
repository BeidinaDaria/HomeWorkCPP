#pragma once
#include <iostream>

template<typename T>
class Tree{
	struct Node {
		T data;
		Node* parent;
		Node* left;
		Node* right;
		Node(T d = INT16_MIN, Node* par = nullptr, Node* l = nullptr, Node* r = nullptr) :data(d), parent(par), left(l), right(r) {}
	};
	Node* root;
	Node* find(T x, Node* n) {
		if (n == nullptr) {
			return nullptr;
		}
		if (n->data == x) {
			return n;
		}
		auto ans = find(x, n->left);
		if (ans!=nullptr) return ans;
		ans = find(x, n->right);
		return ans;
	}
	void del(Node* n) {
		if ((n->left == nullptr) && (n->right == nullptr)) {
			if (n->parent->left == n) n->parent->left = nullptr;
			else n->parent->right = nullptr;
			delete n;
			return;
		}
		if (n->left == nullptr) {
			if (n->parent->left == n) n->parent->left = n->right;
			else n->parent->right = n->right;
			n->right->parent = n->parent;
			delete n;
			return;
		}
		if (n->right == nullptr) {
			if (n->parent->left == n) n->parent->left = n->left;
			else n->parent->right = n->left;
			n->left->parent = n->parent;
			delete n;
			return;
		}
	}
public:
	Tree() :root(new Node()) {}
	Tree(T data) :root(new Node(data)) {}
	void show() {
		show(root);
	}
	void show(Node* n) {
		if (n == nullptr) {
			return;
		}
		std::cout << n->data << " ";
		show(n->left);
		show(n->right);
	}
	void insert(T data) {
		if (find(data,root)!=nullptr) return;
		if(root->data==INT16_MIN){
			root->data = data;
			return;
		}
		Node* n = root;
		Node* prev = nullptr;
		while (n != nullptr) {
			prev = n;
			if (data < n->data)
				n = n->left;
			else n = n->right;
		}
		n = new Node(data, prev);
		if ((prev!=nullptr)&&(n->data < prev->data))
			prev->left = n;
		else if (prev!=nullptr) prev->right = n;
	}
	void del(T data) {
		Node* delNode = find(data, root);
		if (delNode == nullptr) return;
		if ((delNode->left == nullptr) && (delNode->right == nullptr)) {
			if (delNode->parent->left == delNode) delNode->parent->left = nullptr;
			else delNode->parent->right = nullptr;
			delete delNode;
			return;
		}
		if (delNode->left == nullptr) {
			if (delNode->parent->left == delNode) delNode->parent->left = delNode->right;
			else delNode->parent->right = delNode->right;
			delNode->right->parent = delNode->parent;
			delete delNode;
			return;
		}
		if (delNode->right == nullptr) {
			if (delNode->parent->left == delNode) delNode->parent->left = delNode->left;
			else delNode->parent->right = delNode->left;
			delNode->left->parent = delNode->parent;
			delete delNode;
			return;
		}
		Node* subNode = delNode->left;
		while (subNode->right != nullptr) subNode = subNode->right;
		delNode->data = subNode->data;
		del(subNode);
		return;
	}
};