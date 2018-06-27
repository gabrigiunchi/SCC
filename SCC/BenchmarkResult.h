#pragma once

#include <string>

using namespace std;

class BenchmarkResult {
private:
	string algorithm1;
	string algorithm2;
	int graphSize;
	bool success;
	double time1;
	double time2;
	
public:
	BenchmarkResult(string algorithm1, string algorithm2, bool success, int graphSize, double customTime, double boostTime);
	string toString();
	string getAlgorithm1();
	string getAlgorithm2();
	int getGraphSize();
	bool isSuccessfull();
	double getTime1();
	double getTime2();
	double getPerformanceDifference();
	double getTimeDifference();
	string getWinner();
};

