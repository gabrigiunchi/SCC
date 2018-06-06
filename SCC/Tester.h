#pragma once
#include "SCCStrategy.h"
#include "BenchmarkManager.h"

class Tester {
private:
	SCCStrategy* strategy;
	BenchmarkResult checkAlgorithmCorrectness(Graph* g);
public:
	Tester(SCCStrategy* strategy);
	BenchmarkManager performeTests(int n, int minSize, int step);
	BenchmarkManager performeTests(int n, int minSize);
	void memoryTest();
};

