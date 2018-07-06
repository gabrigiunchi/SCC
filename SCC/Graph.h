#pragma once

#include <boost/graph/adjacency_list.hpp>
#include <vector>

using namespace std;

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS> graph_t;

/*
	Decorator class for a directed graph implemented with the boost library.
	The purpose of this class is to make easier the operations usually perfomed in a graph
	(add a vertex, get neighbour of a vertex etc...)
*/
class Graph {
private:
	int size;
	graph_t graph;

public:
	Graph(int size);
	~Graph();
	void addEdge(int source, int destination);

	/*
		Returns the adjacent vertices of a specific vertex
	*/
	vector<int>* getNeighbours(int node);

	graph_t getGraph();
	int getSize();
	string toString();
};
