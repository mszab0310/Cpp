#pragma once
#include <iostream>
class QuadNode
{
	int color;
	QuadNode* NW, * NE, * SE, * SW;
public:
	QuadNode(int color = 0, QuadNode* NW = nullptr, QuadNode* NE = nullptr, QuadNode* SE = nullptr, QuadNode* SW = nullptr) {
		this->color = color;
		this->NW = NW;
		this->NE = NE;
		this->SE = SE;
		this->SW = SW;
	}

	void setColor(int color) {
		this->color = color;
	}

	int getColor() {
		return this->color;
	}

	void setNW(QuadNode* NW) {
		this->NW = NW;
	}

	void setNE(QuadNode* NE) {
		this->NE = NE;
	}

	void setSE(QuadNode* SE) {
		this->SE = SE;
	}

	void setSW(QuadNode* SW) {
		this->SW = SW;
	}

	QuadNode* getNW() {
		return this->NW;
	}

	QuadNode* getNE() {
		return this->NE;
	}

	QuadNode* getSE() {
		return this->SE;
	}

	QuadNode* getSW() {
		return this->SW;
	}

	void print() {
		std::cout << this->getColor() << " ";
		if (this->NW) {
			std::cout << "( ";
			this->NW->print();
			std::cout << ") ";
		}
		if (this->NE) {
			std::cout << "( ";
			this->NE->print();
			std::cout << ") ";
		}
		if (this->SE) {
			std::cout << "( ";
			this->SE->print();
			std::cout << ") ";
		}
		if (this->SW) {
			std::cout << "( ";
			this->SW->print();
			std::cout << ") ";
		}
	}
};

