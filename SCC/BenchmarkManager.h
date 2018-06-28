#pragma once

#include <list>
#include "BenchmarkResult.h"

using namespace std;

/*
	Class which stores the results of different tests and provides information about the performance of the algorithm used,
	for instance the success rate.
*/
class BenchmarkManager {
private:
	string testAlgorithm; // algorithm you want to test
	string referenceAlgorithm; // algorithm used as reference to perform the benchmark
	list<BenchmarkResult> results;
	
public:
	BenchmarkManager(string algorithm);
	void addResult(BenchmarkResult result);
	double getSuccessRate();

	/*
		Returns the average performance difference between the two algorithms calculated as a percentage.
		The percentage doesn't give information about which algorithm performed better, use the method getWinner to 
		obtain that information
	*/
	double getAveragePerformanceDifference();

	/*
		Returns the average time difference between the two algorithms calculated as a simple mathematical average.
		The value is positive if the reference algorithm performed better than the one under test, negative otherwise
	*/
	double getAverageTimeDifference();

	/*
		Returns the average time took by the algorithm under test to finish the task
	*/
	double getAverageTime1(); 

	/*
		Returns the average time took by the reference algorithm to finish the task
	*/
	double getAverageTime2();

	/*
		Returns the name of the algorithm who took less time to perform the test
	*/
	string getWinner();

	string toString();
};