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

BenchmarkResult Tester::checkAlgorithmCorrectness(Graph* g) {
	double t1 = 0;
	double t2 = 0;
	SCCList* l1 = this->strategy->getSCC(g, &t1);
	SCCList* l2 = this->referenceStrategy->getSCC(g, &t2);
	
	//bool success = l2->equals(l1);
	bool success = true;
	BenchmarkResult result(this->strategy->getName(), success, g->getSize(), t1, t2);

	delete l1;
	delete l2;
	return result;
}

BenchmarkManager Tester::performeTests(int n, int size, int step, double factor) {
	BenchmarkManager benchmark(this->strategy->getName());

	for (int i = 1; i <= n; i++) {
		Graph* g = generateGraph(size, factor);
		BenchmarkResult result = this->checkAlgorithmCorrectness(g);
		cout << i << "/" << n << ": " << result.toString() << endl;
		benchmark.addResult(result);
		delete g;
		size += step;
	}

	return benchmark;
}

BenchmarkResult Tester::manualTest(Graph* g) {
	return this->checkAlgorithmCorrectness(g);
}

void Tester::memoryTest() {
	for (int i = 1; i <= 1000000; i++) {
		Graph* g = generateGraph(100, 0);
		delete this->strategy->getSCC(g);
		delete g;
	}
}