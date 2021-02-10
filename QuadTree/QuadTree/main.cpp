#include "quadNode.h"
#include "queue.h"
#include <iostream>
#define RED 1
#define GREEN 3
#define BLUE 5 
#define YELLOW 4
#define MAGENTA 6
#define CYAN 8
#define WHITE 9

int defColor(int x, int y, int size,int matirx[4][4]) {
	int color = 0;
	int r = 0, g = 0, b = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matirx[i + y][j + x] == RED) {
				r = RED;
			}
			if (matirx[i + y][j + x] == GREEN) {
				g = GREEN;
			}
			if (matirx[i + y][j + x] == BLUE) {
				b = BLUE;
			}
		}
	}
	color = r + g + b;
	return color;
}


QuadNode* quadTree(int x, int y, int size,int matrix[4][4]) {
	int subD = size / 2;
	QuadNode* part = new QuadNode();
	part->setColor(defColor(x, y, size,matrix));
	switch (part->getColor())
	{
	case 1: // whole red
	case 3: //whole green
	case 5: //whole blue
		//handle all the above cases in one take
		part->setNW(nullptr);
		part->setNE(nullptr);
		part->setSE(nullptr);
		part->setSW(nullptr);
		break;
	default: //for any other color we do the same, subdivide
		part->setNW(quadTree(x,y,size/2,matrix));
		part->setNE(quadTree(x+subD, y, size / 2, matrix));
		part->setSE(quadTree(x+subD, y+subD, size / 2, matrix));
		part->setSW(quadTree(x, y+subD, size / 2, matrix));
	}
	return part;
}

void breadthFirst(QuadNode* original) {
	Queue<QuadNode*> q;
	QuadNode* tree = original;
	if (tree) {
		do {
			std::cout << tree->getColor() << " ";
			if (tree->getNW()) {
				q.push(tree->getNW());
			}
			if (tree->getNE()) {
				q.push(tree->getNE());
			}
			if (tree->getSE()) {
				q.push(tree->getSE());
			}
			if (tree->getSW()) {
				q.push(tree->getSW());
			}
			tree = q.pop();

		} while (!q.isEmpty());
	}
	std::cout << tree->getColor() << " ";
}


int main() {
	int matrix[4][4] = { {1,1,3,3},
						 {1,1,5,3},
						 {5,3,5,1},   
						 {5,1,3,5} };   //assume 1 = red, 3= green, 5 = blue
										// mixtures of them make
								/*  1 + 3 = 4 yellow
								*   1 + 5 = 6 magenta
								*	 3 + 5 = 8 cyan		
								*	1 + 3 + 5 = 9 white
								*/
	int size = 4; //size of matrix
	QuadNode* qTree = quadTree(0, 0, size, matrix);
	breadthFirst(qTree);
	std::cout << std::endl;
	qTree->print();
	return 0;
} 