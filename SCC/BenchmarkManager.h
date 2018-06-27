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
	string algorithm1;
	string algorithm2;
	list<BenchmarkResult> results;
	
public:
	void addResult(BenchmarkResult result);
	double getSuccessRate();
	double getAveragePerformanceDifference();
	double getAverageTime1();
	double getAverageTime2();
	double getAverageTimeDifference();
	string getWinner();
	void clear(); // eliminate the past results
	string toString();
};