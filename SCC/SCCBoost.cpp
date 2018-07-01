#include "SCCBoost.h"
#include <boost/graph/strong_components.hpp>
#include "utils.h"
#include <chrono>

SCCBoost::SCCBoost() : SCCStrategy("Boost") { }

SCCBoost::~SCCBoost() { }

vector<int>* SCCBoost::util(graph_t* g, int size, int* nComponents, double* time) {
	using namespace std::chrono;

	vector<int>* scc = new vector<int>(size, 0);
	graph_t temp = *g;

	auto start = high_resolution_clock::now();
	*nComponents = strong_components(temp, boost::make_iterator_property_map(scc->begin(), get(boost::vertex_index, temp), scc->at(0)));
	auto end = high_resolution_clock::now();

	duration<double> d = duration_cast<duration<double>>(end - start);
	*time = d.count();

	return scc;
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