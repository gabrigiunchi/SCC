#pragma once

#include <list>
#include "BenchmarkResult.h"

using namespace std;

/*
*	Class which stores the results of different tests and provides information about the performance of the algorithm used,
*	for instance the success rate
*/
class BenchmarkManager {
private:
	list<BenchmarkResult> results;
	bool isBoostWinner;

public:
	void addResult(BenchmarkResult result);
	double getSuccessRate();
	double getAveragePerformanceDifference();
	void clear(); // eliminate the past results
	string toString();
};