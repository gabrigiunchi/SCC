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

double BenchmarkManager::getAveragePerformanceDifference() {
	double customTime = 0;
	double boostTime = 0;

	for (auto it = this->results.begin(); it != this->results.end(); ++it) {
		customTime += it->getCustomAlgorithmTime();
		boostTime += it->getBoostAlgorithmTime();
	}

	double min = customTime < boostTime ? customTime : boostTime;
	double max = customTime > boostTime ? customTime : boostTime;

	this->isBoostWinner = boostTime < customTime;

	return (1 - min / max) * 100;
}

void BenchmarkManager::clear() {
	this->results.clear();
}

string BenchmarkManager::toString() {
	stringstream s;
	double diff = round(this->getAveragePerformanceDifference());

	s << "{ "
		<< "number of tests: " << this->results.size()
		<< ", success rate: " << this->getSuccessRate() << "%"
		<< ", difference: " << diff << "% "
		<< (this->isBoostWinner ? "slower" : "faster")
		<< " }";

	return s.str();
}