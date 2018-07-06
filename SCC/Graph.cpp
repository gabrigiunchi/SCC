#include <boost/graph/adjacency_list.hpp>
#include "Graph.h"
#include <sstream>

using namespace boost;

Graph::Graph(int size) {
	this->size = size;
	this->graph = graph_t(size);
}

Graph::~Graph() { }

graph_t Graph::getGraph() {
	return this->graph;
}

int Graph::getSize() {
	return this->size;
}

void Graph::addEdge(int source, int destination) {
	add_edge(source, destination, this->graph);
}

std::vector<int>* Graph::getNeighbours(int node) {
	graph_t::out_edge_iterator current, end;
	std::vector<int>* res = new std::vector<int>();

	for (tie(current, end) = out_edges(node, graph); current != end; ++current) {
		auto target = boost::target(*current, graph);
		res->push_back(target);
	}

	return res;
}

string Graph::toString() {
	stringstream s;
	for (int i = 0; i < this->size; i++) {
		auto neighbours = this->getNeighbours(i);
		int k = 1;
		
		s << i << ": [";
		for (auto it = neighbours->begin(); it != neighbours->end(); ++it) {
			s << *it;
			if (k != neighbours->size()) {
				s << ", ";
			}
			k++;
		}
		s << "]" << std::endl;

		delete neighbours;
	}

	return s.str();
}