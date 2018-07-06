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
	SCCStrategy* referenceStrategy; // the algorithm used as reference for the benchmark
	BenchmarkResult checkCorrectness(Graph* g);

public:
	/*
		Constructor which takes as input the algorithm you want to test
	*/
	Tester(SCCStrategy* strategy);
	~Tester();

	/*
		Single test with the given graph. Prints the result and also the strongly connected components
	*/
	BenchmarkResult manualTest(Graph* g);

	/*
		Performs tests with random graphs
	*/
	BenchmarkManager randomTests(int n, int size, int step, double edgeFactor);
};

