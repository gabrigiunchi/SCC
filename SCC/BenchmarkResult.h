#pragma once

#include <string>

using namespace std;

/*
	Class which stores the result of single test such as whether it was successfull, the time took by the algorithm you want to test,
	the time took by the reference algorithm etc..
*/
class BenchmarkResult {
private:
	string testAlgorithm; // algorithm you want to test
	string referenceAlgorithm; // algorithm used as reference to perform the benchmark
	int graphSize;
	bool success;
	double time1;
	double time2;
	
public:
	BenchmarkResult(string algorithm, bool success, int graphSize, double t1, double t2);
	~BenchmarkResult();
	string toString();
	string getAlgorithm();
	int getGraphSize();

	/*
		Returns true if the result of the algorithm under test was correct (i.e equal to the one returned by the reference algorithm)
	*/
	bool isSuccessfull();

	/*
		Returns the time took by the algorithm under test to finish the task
	*/
	double getTime1();

	/*
		Returns the time took by the reference algorithm to finish the task
	*/
	double getTime2();

	/*
		Returns the performance difference between the two algorithms calculated as a percentage.
		The percentage doesn't give information about which algorithm performed better, use the method getWinner to 
		obtain that information
	*/
	double getPerformanceDifference();

	/*
		Returns the time difference between the two algorithms.
		The value is positive if the reference algorithm performed better than the one under test, negative otherwise
	*/
	double getTimeDifference();

	string getWinner();
};

