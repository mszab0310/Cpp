#pragma once
#include <map>
#include <set>
#include <vector>
#include <string>

class Graph
{
	std::map<int, std::set<int>> inNeighbours; 
	std::map<int, std::set<int>> outNeighbours;
	int nrVertices;
public:
	Graph(int nrVertices = 0); 
	Graph(const Graph& g);
	void addEdge(int source, int dest);
	std::set<int> getInNeighbours(int vertex);
	std::map<int,std::set<int>> getInNeighbours();
	std::map<int,std::set<int>> getOutNeighbours();
	std::set<int> getOutNeighbours(int vertex);
	std::set<int> getVertices();
	int getNrVertices();
	void removeEdge(int source, int dest);
	void removeVertex(int vertex);
	std::string toString();
	
};

