#include "BenchmarkResult.h"
#include <sstream>

BenchmarkResult::BenchmarkResult(string algorithm, bool success, int graphSize, double customTime, double boostTime) {
	this->algorithm = algorithm;
	this->success = success;
	this->graphSize = graphSize;
	this->customAlgorithmTime = customTime;
	this->boostAlgorithmTime = boostTime;
}

string BenchmarkResult::getAlgorithm() {
	return this->algorithm;
}

int BenchmarkResult::getGraphSize() {
	return this->graphSize;
}

bool BenchmarkResult::isSuccessfull() {
	return this->success;
}

double BenchmarkResult::getCustomAlgorithmTime() {
	return this->customAlgorithmTime;
}

double BenchmarkResult::getBoostAlgorithmTime() {
	return this->boostAlgorithmTime;
}

double BenchmarkResult::getDiffTime() {
	return this->customAlgorithmTime - this->boostAlgorithmTime;
}

double BenchmarkResult::getPerformanceDifference() {
	double min = this->boostAlgorithmTime < this->customAlgorithmTime ? this->boostAlgorithmTime : this->customAlgorithmTime;
	double max = this->boostAlgorithmTime > this->customAlgorithmTime ? this->boostAlgorithmTime : this->customAlgorithmTime;
	return (1 - min / max) * 100;
}

string BenchmarkResult::toString() {
	stringstream s;

	s << "{ algorithm: " << this->algorithm
		<< ", graph size: " << this->graphSize
		<< ", success: " << (this->success ? "true" : "false")
		<< ", " << this->algorithm << " time: " << this->customAlgorithmTime << "s"
		<< ", Boost time: " << this->boostAlgorithmTime
		<< ", difference: " << round(this->getPerformanceDifference()) << "% "
		<< (this->customAlgorithmTime < this->boostAlgorithmTime ? "faster" : "slower")
		<< " }";

	return s.str();
}