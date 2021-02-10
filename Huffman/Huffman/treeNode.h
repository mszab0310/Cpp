#pragma once
#include <iostream>


template <typename T>
class TreeNode {
	T val;
	TreeNode<T>* left,*right;
public:
	TreeNode() {};
	TreeNode(T val, TreeNode<T>* left = nullptr, TreeNode<T>* right= nullptr) {
		this->val = val;
		this->left = left;
		this->right = right;
	}

	void setLeft(TreeNode<T>* left) {
		this->left = left;
	}

	void setRight(TreeNode<T>* right) {
		this->right = right;
	}

	TreeNode<T>* getLeft() {
		return this->left;
	}

	TreeNode<T>* getRight() {
		return this->right;
	}

	T getVal() {
		return this->val;
	}

	void setVal(int val) {
		this->val = val;
	}

	friend std::ostream& operator<<(std::ostream& os, TreeNode& n) {
		os << n.getVal() << " -> ";
	}
};

