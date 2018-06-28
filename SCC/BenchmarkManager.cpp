#include "BenchmarkManager.h"
#include <sstream>
#include "utils.h"
#include "SCCStrategy.h"

BenchmarkManager::BenchmarkManager(string algorithm) {
	this->testAlgorithm = algorithm;
	SCCStrategy* s = getDefaultStrategy();
	this->referenceAlgorithm = s->getName();
	delete s;
}

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

double BenchmarkManager::getAverageTime1() {
	double total = 0;
	for (auto it = this->results.begin(); it != this->results.end(); it++) {
		total += it->getTime1();
	}

	return total / (double)this->results.size();
}

double BenchmarkManager::getAverageTime2() {
	double total = 0;
	for (auto it = this->results.begin(); it != this->results.end(); it++) {
		total += it->getTime2();
	}

	return total / (double)this->results.size();
}

double BenchmarkManager::getAverageTimeDifference() {
	double total = 0;

	for (auto it = this->results.begin(); it != this->results.end(); it++) {
		total += it->getTimeDifference();
	}

	return total / (double)this->results.size();
}

double BenchmarkManager::getAveragePerformanceDifference() {
	double time1 = 0;
	double time2 = 0;

	for (auto it = this->results.begin(); it != this->results.end(); ++it) {
		time1 += it->getTime1();
		time2 += it->getTime2();
	}

	double min = std::min(time1, time2);
	double max = std::max(time1, time2);

	return min == max ? 0 : (1 - min / max) * 100;
}

string BenchmarkManager::getWinner() {
	double t1 = this->getAverageTime1();
	double t2 = this->getAverageTime2();

	if (t1 < t2) {
		return this->testAlgorithm;
	}
	else if (t2 < t1) {
		return this->referenceAlgorithm;
	}

	return "none";
}

string BenchmarkManager::toString() {
	stringstream s;

	s << "{ "
		<< "number of tests: " << this->results.size()
		<< ", success rate: " << this->getSuccessRate() << "%"
		<< ", average " << this->testAlgorithm << " time: " << this->getAverageTime1() << "s"
		<< ", average " << this->referenceAlgorithm << " time: " << this->getAverageTime2() << "s"
		<< ", winner: " << this->getWinner();

	double difference = this->getAverageTimeDifference();
	if (difference != 0) {
		s << ", difference: " << this->getAverageTimeDifference() << "s ("
			<< round(this->getAveragePerformanceDifference(), 1) << "%)";
	}

	s << " }";
		
	return s.str();
}