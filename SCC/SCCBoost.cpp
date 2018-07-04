#include "SCCBoost.h"
#include <boost/graph/strong_components.hpp>
#include "utils.h"
#include <chrono>

SCCBoost::SCCBoost() : SCCStrategy("Boost") { }

SCCBoost::~SCCBoost() { }

vector<int> SCCBoost::getSCC(Graph* g, int* nComponents, double* time) {
	using namespace std::chrono;

	vector<int> scc(g->getSize());
	graph_t G = g->getGraph();
	auto propMap = boost::make_iterator_property_map(scc.begin(), get(boost::vertex_index, G), scc[0]);

	auto start = high_resolution_clock::now();
	*nComponents = strong_components(G, propMap);
	auto end = high_resolution_clock::now();

	duration<double> d = duration_cast<duration<double>>(end - start);
	*time = d.count();

	return scc;
}

vector<int> SCCBoost::getSCC(Graph* g, int* nComponents) {
	double t = 0;
	return this->getSCC(g, nComponents, &t);
}

SCCList* SCCBoost::getSCC(Graph* g) {
	double time = 0;
	return this->getSCC(g, &time);
}

SCCList* SCCBoost::getSCC(Graph* g, double* time) {
	int nComponents = 0;
	vector<int> scc = this->getSCC(g, &nComponents, time);
	SCCList* l = convert(scc, nComponents);
	return l;
}