#pragma once

#include <boost/graph/adjacency_list.hpp>
#include <boost/dynamic_bitset.hpp>
#include <unordered_set>

using namespace std;

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS> graph_t;

/*
*	Decorator class for a directed graph implemented with the boost library.
*	The purpose of this class is to make easier the operations usually perfomed a graph
*	(add a vertex, get children of a vertex etc...)
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
	std::unordered_set<int> getChildren(int node);

	graph_t* getGraph();
	int getSize();
	string toString();
};
