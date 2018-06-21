#pragma once

#include <string>

using namespace std;

class BenchmarkResult {
private:
	string algorithm;
	int graphSize;
	bool success;
	double customAlgorithmTime;
	double boostAlgorithmTime;
	
public:
	BenchmarkResult(string algorithm, bool success, int graphSize, double customTime, double boostTime);
	string toString();
	string getAlgorithm();
	int getGraphSize();
	bool isSuccessfull();
	double getCustomAlgorithmTime();
	double getBoostAlgorithmTime();
	double getPerformanceDifference();
};

