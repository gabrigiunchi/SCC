#pragma once

#include <list>
#include <stack>
#include <boost/graph/adjacency_list.hpp>
#include <boost/dynamic_bitset.hpp>

using namespace std;

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS> graph_t;

/*
*	This class defines a directed graph
*/
class Graph {
private:
	unsigned long size;
	graph_t graph;

public:
	Graph(unsigned long size);
	void addEdge(int source, int destination);

	/*
	*	Returns the adjacent vertices of a specific vertex
	*/
	set<int> getChildren(int node);

	graph_t getGraph();
	int getSize();
	void toString();
};
