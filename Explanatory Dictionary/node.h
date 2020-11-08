#pragma once
#include <iostream>
//templated class for creation of list with a key and value vector field for multiple possible values
template < typename K, typename V>
class Node {
	std::vector<V> val;
	K key;
	Node<K, V>* next;
public:
	Node(K key, Node<K, V>* next = nullptr) {
		this->key = key;
		this->next = next;
	}
	Node<K, V>* getNext() {
		return this->next;
	}

	std::vector<V> getVal() {
		return this->val;
	}

	void setNext(Node<K, V>* next) {
		this->next = next;
	}

	void addVal(V val) {
		this->val.push_back(val);
	}

	K getKey() {
		return this->key;
	}

	void setKey(K key) {
		this->key = key;
	}
};