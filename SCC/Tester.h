#pragma once
#include "SCCStrategy.h"
#include "BenchmarkManager.h"

/*
	This class provides methods to perform tests on a specific algorithm to collect data about its performance 
	compared to another one (i.e benchmark)
*/
class Tester {
private:
	SCCStrategy* strategy;
	BenchmarkResult checkAlgorithmCorrectness(Graph* g);

public:
	/*
		Constructor which takes as input the algorithm you want to test
	*/
	Tester(SCCStrategy* strategy);
	~Tester();

	BenchmarkResult manualTest(Graph* g);
	BenchmarkManager performeTests(int n, int minSize, int step, double edgeFactor);
	BenchmarkManager performeTests(int n, int minSize, int step);
	BenchmarkManager performeTests(int n, int minSize);

	/*
		Runs thousands of tests to check if there are some memory leaks due to poor pointer management
	*/
	void memoryTest();

	/*
		Tests which use small pre-defined graphs
	*/
	void manualTest();
};

