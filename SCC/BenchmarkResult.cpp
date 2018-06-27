#include "BenchmarkResult.h"
#include <sstream>
#include "utils.h"
#include "SCCStrategy.h"

BenchmarkResult::BenchmarkResult(string algorithm, bool success, int graphSize, double customTime, double boostTime) {
	this->testAlgorithm = algorithm;
	this->success = success;
	this->graphSize = graphSize;
	this->time1 = customTime;
	this->time2 = boostTime;
	SCCStrategy* s = getDefaultStrategy();
	this->referenceAlgorithm = s->getName();
	delete s;
}

string BenchmarkResult::getAlgorithm() {
	return this->testAlgorithm;
}

int BenchmarkResult::getGraphSize() {
	return this->graphSize;
}

bool BenchmarkResult::isSuccessfull() {
	return this->success;
}

double BenchmarkResult::getTime1() {
	return this->time1;
}

double BenchmarkResult::getTime2() {
	return this->time2;
}

double BenchmarkResult::getPerformanceDifference() {
	double min = this->time2 < this->time1 ? this->time2 : this->time1;
	double max = this->time2 > this->time1 ? this->time2 : this->time1;

	return min == max ? 0 : (1 - min / max) * 100;
}

double BenchmarkResult::getTimeDifference() {
	double max = std::max(this->time1, this->time2);
	double min = std::min(this->time1, this->time2);
	return max - min;
}

string BenchmarkResult::getWinner() {
	if (this->time1 < this->time2) {
		return this->testAlgorithm;
	}
	else if (this->time2 < this->time1) {
		return this->referenceAlgorithm;
	}

	return "none";
}

string BenchmarkResult::toString() {
	stringstream s;

	s << "{ algorithm: " << this->testAlgorithm
		<< ", graph size: " << this->graphSize
		<< ", success: " << (this->success ? "true" : "false")
		<< ", " << this->testAlgorithm << " time: " << this->time1 << "s"
		<< ", " << this->referenceAlgorithm << " time: " << this->time2 << "s"
		<< ", winner: " << this->getWinner();

	double difference = this->getTimeDifference();
	if (difference != 0) {
		s << ", difference: " << this->getTimeDifference() << "s ("
			<< round(this->getPerformanceDifference(), 1) << "%)";
	}

	s << " }";

	return s.str();
}