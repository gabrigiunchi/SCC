#include "BenchmarkManager.h"
#include <sstream>

void BenchmarkManager::addResult(BenchmarkResult result) {
	this->results.push_back(result);
}

double BenchmarkManager::getSuccessRate() {
	int successCount = 0;
	for (auto it = this->results.begin(); it != this->results.end(); ++it) {
		successCount += (*it).isSuccessfull();
	}
	return ((double)successCount / (double)this->results.size()) * (double)100;
}

double BenchmarkManager::getAverageDiffTime() {
	double total = 0;
	for (auto it = this->results.begin(); it != this->results.end(); ++it) {
		total += (*it).getDiffTime();
	}

	return total / (double)this->results.size();
}

void BenchmarkManager::clear() {
	this->results.clear();
}

string BenchmarkManager::toString() {
	stringstream s;
	s << "{ Success rate: " << this->getSuccessRate() << "%"
		<< ", average difference: " << this->getAverageDiffTime() << "s"
		<< " }";

	return s.str();
}