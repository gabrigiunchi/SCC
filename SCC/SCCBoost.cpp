#include "SCCBoost.h"
#include <boost/graph/strong_components.hpp>
#include "utils.h"

SCCBoost::SCCBoost() : SCCStrategy("Boost") { }

SCCBoost::~SCCBoost() { }

vector<int>* SCCBoost::util(graph_t* g, int size, int* nComponents, double* time) {
	vector<int> scc(size);
	graph_t temp = *g;
	clock_t start = clock();
	*nComponents = strong_components(temp, boost::make_iterator_property_map(scc.begin(), get(boost::vertex_index, temp), scc[0]));
	*time = (clock() - start) / (double)CLOCKS_PER_SEC;
	return new vector<int>(scc.begin(), scc.end());
}

vector<int>* SCCBoost::util(graph_t* g, int size, int* nComponents) {
	double t = 0;
	return this->util(g, size, nComponents, &t);
}

SCCList* SCCBoost::getSCC(Graph* g) {
	double time = 0;
	return this->getSCC(g, &time);
}

SCCList* SCCBoost::getSCC(Graph* g, double* time) {
	int nComponents = 0;
	vector<int>* scc = this->util(g->getGraph(), g->getSize(), &nComponents, time);

	SCCList* l = convert(scc, nComponents);
	delete scc;
	return l;
}