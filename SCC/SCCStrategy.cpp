#include <boost/graph/strong_components.hpp>
#include "SCCStrategy.h"

SCCStrategy::SCCStrategy(string algorithm) {
	this->algorithm = algorithm;
}

string SCCStrategy::toString() {
	return this->algorithm;
}

vector<int> SCCBoost(Graph* g, int* nComponents) {
	if (g->getSize() == 0) {
		return vector<int>();
	}

	vector<int> scc(g->getSize());
	graph_t graph = g->getGraph();
	*nComponents = strong_components(graph, boost::make_iterator_property_map(scc.begin(), get(boost::vertex_index, graph), scc[0]));

	return scc;
}

