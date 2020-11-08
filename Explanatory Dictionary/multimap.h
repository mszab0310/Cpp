#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include "node.h"
#define HASHSIZE 1000

//templated class for the creation of a list based multimap
template <typename K, typename V>
class Multimap
{
	//standard library hashing function
	std::hash<K> hashFunction;

	std::vector<Node<K, V>*> elements;
	//fits hashvalue in the [0,Hashsize] range
	int hash(K key) {
		return hashFunction(key) % HASHSIZE;
	}

public:

	Multimap() {
		//initializes multimaps node vector to null
		this->elements.reserve(HASHSIZE);
		for (int i = 0; i < HASHSIZE; i++) {
			this->elements.push_back(nullptr);
		}
	};

	//method to add elements to the multimap
	void set(K key, V value) {
		int hashVal = hash(key);
		//if the position hasnt been used before in the multimap,set the position to the new node containing the key+value pair
		if (this->elements[hashVal] == nullptr) {
			Node<K, V>* node = new Node<K, V>(key);
			node->addVal(value);
			this->elements[hashVal] = node;
		}
		else {
			//if we have a collision,check wether we reach the end of list or we have matching keys
			Node<K, V>* temp = this->elements[hashVal];
			while (temp->getNext() != nullptr && temp->getKey() != key) {
				temp = temp->getNext();
			}
			//if we have matching keys, add value to the  nodes value vector, no need to create a new node with the same key
			if (temp->getKey() == key) {
				temp->addVal(value);
			}
			else {
				//if we reached end of list, append new node with the data to the existing list
				Node<K, V>* node = new Node<K, V>(key);
				node->addVal(value);
				temp->setNext(node);
			}

		}
	}

	//method to return values for a specific key
	std::vector<V> getValues(K key) {
		int hashVal = hash(key);
		Node<K, V>* temp = this->elements[hashVal];
		//check if we find the key in the multimap, or we reach end of list at the calculated position
		while (temp != nullptr && temp->getKey() != key) {
			temp = temp->getNext();
		}
		//if we reach end of list, the multimap does not contain the key, we return an emtpy vector
		if (!temp) {
			return std::vector<V>();
		}
		//we return the values
		return temp->getVal();
	}


};

