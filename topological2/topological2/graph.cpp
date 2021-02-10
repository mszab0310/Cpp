#include "graph.h"
#include <iostream>

Graph::Graph(int nrVertices)
{
	this->nrVertices = nrVertices;

	for (int i = 0; i < nrVertices; i++) {
		this->inNeighbours.insert(std::pair<int,std::set<int>>(i,std::set<int>()));
		this->outNeighbours.insert(std::pair<int,std::set<int>>(i,std::set<int>()));
	}
}

Graph::Graph(const Graph& g)
{
	this->inNeighbours = g.inNeighbours;
	this->outNeighbours = g.outNeighbours;
	this->nrVertices = g.nrVertices;
}

void Graph::addEdge(int source, int dest)
{
		this->inNeighbours[dest].insert(source);
		this->outNeighbours[source].insert(dest);
	
}

std::set<int> Graph::getInNeighbours(int vertex)
{

	return this->inNeighbours[vertex];
}

std::map<int, std::set<int>> Graph::getInNeighbours()
{
	return this->inNeighbours;
}

std::map<int, std::set<int>> Graph::getOutNeighbours()
{
	return this->outNeighbours;
}

std::set<int> Graph::getOutNeighbours(int vertex)
{
	return this->outNeighbours[vertex];
}

std::set<int> Graph::getVertices()
{
	std::set<int> vertices;
	for (auto pair : this->inNeighbours) {
		vertices.insert(pair.first);
	}
	for (auto pair : this->outNeighbours) {
		vertices.insert(pair.first);
	}
	return vertices;
}

int Graph::getNrVertices()
{
	return this->nrVertices;
}

void Graph::removeEdge(int source, int dest)
{
	this->outNeighbours[source].erase(dest);
	this->inNeighbours[dest].erase(source);
}

void Graph::removeVertex(int vertex)
{
	std::set<int> tempIn = this->inNeighbours[vertex];
	std::set<int> tempOut = this->outNeighbours[vertex];
	for (auto v : tempIn) {
		this->removeEdge(v,vertex);
	}

	for (auto v : tempOut) {
		this->removeEdge(vertex,v);
	}

	this->inNeighbours.erase(vertex);
	this->outNeighbours.erase(vertex);
	this->nrVertices--;
}

std::string Graph::toString()
{
	std::string output;
	output += "in :\n";
	for (auto pair : this->inNeighbours) {
		output += std::to_string(pair.first) + " -> [";
		for (auto vertex : pair.second) {
			output += std::to_string(vertex) + ", ";
		}
		output += "]\n";
	}
	output += "out :\n";
	for (auto pair : this->outNeighbours) {
		output += std::to_string(pair.first) + " -> [";
		for (auto vertex : pair.second) {
			output += std::to_string(vertex) + ", ";
		}
		output += "]\n";
	}

	return output;
}
