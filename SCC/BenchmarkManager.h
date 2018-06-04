#pragma once

#include <list>

using namespace std;

struct BenchmarkResult {
	int graphSize;
	bool success;
	double customAlgorithmTime;
	double boostAlgorithmTime;
	double diffTime; // Time difference between custom algorithm and boost's algorithm
};

/*
*	Class which stores the results of different tests and provides information about the performance of the algorithm used,
*	for example the success rate
*/
class BenchmarkManager {
private:
	list<BenchmarkResult> results;

public:
	void addResult(BenchmarkResult result);
	double getSuccessRate();
	double getAverageDiffTime();
	void clear(); // eliminate the past results
	string toString();
};