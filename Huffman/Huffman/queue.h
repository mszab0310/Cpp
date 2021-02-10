#pragma once
#include <iostream>

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
protected:
	void setFirst(Node<T>* first) {
		this->first = first;
	}

	void setLast(Node<T>* last) {
		this->last = last;
	}

	Node<T>* getFirst() {
		return this->first;
	}

	void incCount() {
		this->count++;
	}

public:
	Queue(int count = 0, Node<T>* first = nullptr, Node<T>* last = nullptr) {
		this->count = count;
		this->first = first;
		this->last = last;
	}

	bool isEmpty() {
		return (this->first == nullptr);
	}

	int getCount() {
		return this->count;
	}

	T peek() {
		return this->getFirst()->getVal();
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
		this->count++;
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
			this->count--;
			return val;
		}
		else {
			T val = this->first->getVal();
			delete this->first;
			this->first = nullptr;
			this->last = nullptr;
			this->count--;
			return val;
		}
		
	}
};

