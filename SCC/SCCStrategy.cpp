#include "SCCStrategy.h"
#include "SCCBoost.h"
#include <chrono>

SCCStrategy::SCCStrategy(string algorithm) {
	this->algorithm = algorithm;
}

SCCStrategy::~SCCStrategy() { }

string SCCStrategy::getName() {
	return this->algorithm;
}

SCCStrategy* getDefaultStrategy() {
	return new SCCBoost();
}

SCCList* SCCStrategy::getSCC(Graph* g, double* time) {
	using namespace std::chrono;

	auto start = high_resolution_clock::now();
	SCCList* l = this->getSCC(g);
	auto end = high_resolution_clock::now();

	duration<double> d = duration_cast<duration<double>>(end - start);
	*time = d.count();

	return l;
}