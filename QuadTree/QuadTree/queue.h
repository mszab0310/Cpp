#pragma once
#include <iostream>
#define N 3

template <typename T>
class Node {
	T val;
	Node<T>* next;
public:
	Node(T val, Node<T>* next = nullptr) {
		this->val = val;
		this->next = next;
	}
	Node<T>* getNext() {
		return this->next;
	}

	T getVal() {
		return this->val;
	}

	void setNext(Node<T>* next) {
		this->next = next;
	}

	void setVal(int val) {
		this->val = val;
	}

	friend std::ostream& operator<<(std::ostream& os, Node& n) {
		os << n.getVal() << " -> ";
	}
};

template <typename T>
class Queue {
	int count;
	Node<T>* first;
	Node<T>* last;
public:
	Queue(int count = 0, Node<T>* first = nullptr, Node<T>* last = nullptr) {
		this->count = count;
		this->first = first;
		this->last = last;
	}

	bool isEmpty() {
		return (this->first == nullptr);
	}

	bool isFull() {
		return (this->count == N);
	}

	void incCount() {
		this->count++;
	}

	void push(T val) {
		Node<T>* a = new Node<T>(val);
		if (!this->isEmpty()) {
			this->last->setNext(a);
			this->last = a;
		}
		else {
			this->last = a;
			this->first = this->last;
		}
		this->incCount();
	}

	T pop() {
		Node<T>* temp = this->first;
		if (this->first == nullptr) {
			throw  std::exception("Empty queue");
		}
		else if (temp->getNext() != NULL) {
			temp = temp->getNext();
			T val = this->first->getVal();
			delete this->first;
			this->first = temp;
			return val;
		}
		else {
			T val = this->first->getVal();
			delete this->first;
			this->first = nullptr;
			this->last = nullptr;
			return val;
		}
	}
};
