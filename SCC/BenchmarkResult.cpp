#include "BenchmarkResult.h"
#include <sstream>

BenchmarkResult::BenchmarkResult(string algorithm, bool success, int graphSize, double customTime, double boostTime) {
	this->algorithm = algorithm;
	this->success = success;
	this->graphSize = graphSize;
	this->customAlgorithmTime = customTime;
	this->boostAlgorithmTime = boostTime;
	this->diffTime = this->customAlgorithmTime - this->boostAlgorithmTime;
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
	return this->diffTime;
}

string BenchmarkResult::toString() {
	stringstream s;

	s << "{ algorithm: " << this->algorithm
		<< ", graph size: " << this->graphSize
		<< ", success: " << (this->success ? "true" : "false")
		<< ", " << this->algorithm << " time: " << this->customAlgorithmTime
		<< ", Boost time: " << this->boostAlgorithmTime
		<< ", difference: " << this->diffTime
		<< " }";

	return s.str();
}