#include <boost/graph/adjacency_list.hpp>
#include <boost/dynamic_bitset.hpp>
#include <iostream>
#include "Graph.h"

using namespace boost;

Graph::Graph(unsigned long size) {
	this->size = size;
	this->graph = graph_t(size);
}

graph_t Graph::getGraph() {
	return this->graph;
}

int Graph::getSize() {
	return this->size;
}

void Graph::addEdge(int source, int destination) {
	add_edge(source, destination, this->graph);
}

set<int> Graph::getChildren(int node) {
	graph_t::out_edge_iterator current, end;
	set<int> res;

	for (tie(current, end) = out_edges(node, graph); current != end; ++current) {
		auto target = boost::target(*current, graph);
		res.insert(target);
	}

	return res;
}

void Graph::toString() {
	for (int i = 0; i < this->size; i++) {
		auto children = this->getChildren(i);
		int k = 1;
		
		cout << i << ": [";
		for (auto it = children.begin(); it != children.end(); ++it) {
			std::cout << *it;
			if (k != children.size()) {
				std::cout << ", ";
			}
			k++;
		}
		std::cout << "]" << std::endl;
	}
}