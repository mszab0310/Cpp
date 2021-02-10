#include <iostream>

template <typename T>
class Node
{
	T val;
	Node* next;
public:
	Node(T val, Node* next = nullptr) {
		this->val = val;
		this->next = next;
	}

	T getVal() {
		return val;
	}

	void setVal(T val) {
		this->val = val;
	}

	Node* getNext() {
		return this->next;
	}

	void setNext() {
		this->next = next;
	}

	friend std::ostream& operator<<(std::ostream& os, const Node<T>& list) {
		os << list.val << " ";
		return os;
	}

};
