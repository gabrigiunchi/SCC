#include "Tester.h"
#include <iostream>
#include "utils.h"

Tester::Tester(SCCStrategy* strategy) {
	this->strategy = strategy;
}

BenchmarkResult Tester::checkAlgorithmCorrectness(Graph* g) {
	// Calculate time with custom algorithm
	clock_t start1;
	double duration1;
	start1 = clock();
	SCCList l1 = this->strategy->getSCC(g);
	duration1 = (clock() - start1) / (double)CLOCKS_PER_SEC;

	// Calculate time with boost's algorithm
	clock_t start2;
	double duration2;
	start2 = clock();
	int nComponents = 0;
	vector<int> v2 = SCCBoost(g, &nComponents);
	duration2 = (clock() - start2) / (double)CLOCKS_PER_SEC;
	SCCList l2 = convert(v2, nComponents);

	BenchmarkResult result(this->strategy->toString(), l1.equals(l2), g->getSize(), duration1, duration2);
	return result;
}

BenchmarkManager Tester::performeTests(int n, int minSize, int step) {
	BenchmarkManager benchmark;

	int size = minSize;
	for (int i = 0; i < n; i++) {
		Graph* g = generateGraph(size);
		BenchmarkResult result = this->checkAlgorithmCorrectness(g);
		cout << result.toString() << endl;
		flush(cout);
		benchmark.addResult(result);
		delete g;
		size += step;
	}

	return benchmark;
}

BenchmarkManager Tester::performeTests(int n, int minSize) {
	return this->performeTests(n, minSize, 1);
}

void Tester::memoryTest() {
	int n = 1000000;
	int size = 100;

	for (int i = 1; i <= n; i++) {
		Graph* g = generateGraph(size);
		this->checkAlgorithmCorrectness(g);
		cout << "test " << i << endl;
		delete g;
	}
}