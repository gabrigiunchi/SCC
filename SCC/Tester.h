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
	SCCStrategy* referenceStrategy; // the correct algorithm used as reference for the benchmark
	BenchmarkResult checkAlgorithmCorrectness(Graph* g);

public:
	/*
		Constructor which takes as input the algorithm you want to test
	*/
	Tester(SCCStrategy* strategy);
	~Tester();

	BenchmarkResult manualTest(Graph* g);
	BenchmarkManager performeTests(int n, int size, int step, double edgeFactor);
	
	/*
		Runs thousands of tests to check if there are some memory leaks due to poor pointer management
	*/
	void memoryTest();
};

