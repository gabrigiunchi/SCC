#pragma once
#include "SCCStrategy.h"
#include "BenchmarkManager.h"

class Tester {
private:
	SCCStrategy* strategy;
	BenchmarkResult checkAlgorithmCorrectness(Graph* g);
public:
	Tester(SCCStrategy* strategy);
	~Tester();
	BenchmarkManager performeTests(int n, int minSize, int step, double edgeFactor);
	BenchmarkManager performeTests(int n, int minSize, int step);
	BenchmarkManager performeTests(int n, int minSize);
	void memoryTest();
	void manualTest();
};

