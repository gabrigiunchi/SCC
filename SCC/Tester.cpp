#include "Tester.h"
#include <iostream>
#include "utils.h"

Tester::Tester(SCCStrategy* strategy) {
	this->strategy = strategy;
	this->referenceStrategy = getDefaultStrategy();
}

Tester::~Tester() {
	delete this->strategy;
	delete this->referenceStrategy;
}

BenchmarkResult Tester::checkCorrectness(Graph* g) {
	double t1 = 0;
	double t2 = 0;
	SCCList* l1 = this->strategy->getSCC(g, &t1);
	SCCList* l2 = this->referenceStrategy->getSCC(g, &t2);
	
	bool success = l2->equals(l1);
	BenchmarkResult result(this->strategy->getName(), success, g->getSize(), t1, t2);

	delete l1;
	delete l2;
	return result;
}

BenchmarkManager Tester::randomTests(int n, int size, int step, double density) {
	BenchmarkManager benchmark(this->strategy->getName());

	for (int i = 1; i <= n; i++) {
		Graph* g = generateGraph(size, density);
		BenchmarkResult result = this->checkCorrectness(g);
		cout << i << "/" << n << ": " << result.toString() << endl;
		benchmark.addResult(result);
		delete g;
		size += step;
	}

	return benchmark;
}

BenchmarkResult Tester::manualTest(Graph* g) {
	return this->checkCorrectness(g);
}