#include "queue.h"
#include <vector>
#include <fstream>

class Point {
public:
	int x, y;
	Point(int _x, int _y) :x(_x), y(_y) {};
	Point() {};
	friend std::ostream& operator<<(std::ostream& os, Point& p) {
		os <<"("<< p.x << ","<<p.y << ")";
	}
};

std::vector<std::vector<int>> readMatrixFromFile(std::string source, int fill = 0) {
	std::ifstream file(source);
	if (!file.is_open()) {
		std::cout << "ERROROROROROROROr" << std::endl;
		exit(1);
	}
	int n, m;

	file >> n >> m;
	std::vector<std::vector<int>> mat;
	for (int i = 0; i < n; i++) {
		mat.push_back(std::vector<int>());
		for (int j = 0; j < m; j++) {
			mat[i].push_back(fill);
		}
	}
	int x, y;
	while (file >> x >> y) {
		mat[x][y] = -1;
	}

	return mat;
}

void display(std::vector<std::vector<int>> mat) {
	for (std::vector<int> row : mat) {
		for (int i : row) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
}

std::vector<std::vector<int>> createFrame(std::vector<std::vector<int>> mat) {
	std::vector<std::vector<int>> newMat;
	int n = mat[0].size();
	newMat.push_back(std::vector<int>());
	//add new row
	for (int i = 0; i < n + 2; i++) {
		newMat[0].push_back(-1);
	}

	for (int i = 0; i < mat.size(); i++) {
		newMat.push_back(std::vector<int>());
		newMat[i + 1].push_back(-1);
		for (int j = 0; j < mat[i].size(); j++) {
			newMat[i + 1].push_back(mat[i][j]);
		}
		newMat[i + 1].push_back(-1);
	}
	newMat.push_back(std::vector<int>());
	//add new row
	for (int i = 0; i < n + 2; i++) {
		newMat[n + 1].push_back(-1);
	}

	return newMat;
}

void displayQueue(Queue<Point> q) {
	Node<Point>* temp = q.;
	if (this->isEmpty()) {
		std::cout << "Empty queue" << std::endl;
		return;
	}
	while (temp != NULL) {
		std::cout << *temp << " ";
		temp = temp->getNext();
	}
	std::cout << std::endl;
}

void lee(std::vector<std::vector<int>> mat, Point start, Point dest) {
	std::vector<int> dx = { -1 ,0,1,0 }, dy = { 0,-1,0,1 };
	Queue<Point> queue;
	queue.push(start);
	mat[start.x][start.y] = 0;
	std::cout << start.x << " " << start.y;

	while (!queue.isEmpty())
	{
		queue.display();
		Point current = queue.pop();
		for (int i = 0; i < 4; i++) {
			Point neighbour(start.x + dx[i], start.y + dy[i]);
			switch (mat[neighbour.x][neighbour.y])
			{
			case -2: {
				mat[neighbour.x][neighbour.y] = mat[current.x][current.y] + 1;
				queue.push(neighbour);
				break;
			}			
			default:
				break;
			}
		}
	}


}


int main() {
	std::vector<std::vector<int>> mat = readMatrixFromFile("lee.txt", -2);
	display(mat);
	std::cout << std::endl;
	auto matWithFrame = createFrame(mat);
	lee(matWithFrame, Point(4, 1), Point(9,9));
	display(matWithFrame);
	return 0;
}