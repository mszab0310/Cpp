#pragma once
#include "queue.h"
#include "treeNode.h"


class PriorityQueue : public Queue<TreeNode<std::pair<char,double>>*>
{
public:
	void push(TreeNode<std::pair<char, double>>* val) {
		Node<TreeNode<std::pair<char, double>>*>* a = new Node<TreeNode<std::pair<char, double>>*>(val);
		if (this->isEmpty()) {
			this->setFirst(a);
			this->setLast(a);
		}
		else {
			Node<TreeNode<std::pair<char, double>>*>* temp = this->getFirst();
			if (temp->getVal()->getVal().second < val->getVal().second) {
				a->setNext(temp);
				this->setFirst(a);
			}
			else {

				while (temp->getNext() && temp->getNext()->getVal()->getVal().second > val->getVal().second) {
					temp = temp->getNext();
				}
				a->setNext(temp->getNext());
				temp->setNext(a);
			}
			
		}
		this->incCount();
		
	}
};

