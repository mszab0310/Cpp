#include "node.h"
#include "graph.h"

void initGraph(Graph& g) {
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(3,5);
	g.addEdge(3,6);
	g.addEdge(3,7);
	g.addEdge(4,8);
	g.addEdge(8,7);
}


std::vector<int> topologicalSort(Graph g) {
	std::vector<int> s;
	Graph T = g;
	while (s.size() != g.getNrVertices()) {
		std::cout << T.toString() << std::endl;
		auto in = T.getInNeighbours();
		for (auto p : in) {
			if (p.second.size() == 0) {
				T.removeVertex(p.first);
				s.push_back(p.first);
			}
		}
	}

	return s;
}


int main() {
	Graph g(9);
	initGraph(g);
	std::vector<int> topo = topologicalSort(g);
	for (auto i : topo) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	return 0;
}