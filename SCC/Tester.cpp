#include "Tester.h"
#include <iostream>
#include "utils.h"
#include "SCCBoost.h"
#include "SCCTarjan.h"

Tester::Tester(SCCStrategy* strategy) {
	this->strategy = strategy;
}

Tester::~Tester() {
	delete this->strategy;
}

BenchmarkResult Tester::checkAlgorithmCorrectness(Graph* g) {
	// Calculate time with custom algorithm
	double t1 = 0;
	SCCList* l1 = this->strategy->getSCC(g, &t1);

	// Calculate time with boost's algorithm
	double t2 = 0;
	SCCList* l2 = SCCBoost().getSCC(g, &t2);

	bool success = l2->equals(l1);
	BenchmarkResult result(this->strategy->toString(), success, g->getSize(), t1, t2);

	delete l1;
	delete l2;
	return result;
}

BenchmarkManager Tester::performeTests(int n, int minSize, int step, double factor) {
	BenchmarkManager benchmark;

	int size = minSize;
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

BenchmarkManager Tester::performeTests(int n, int minSize, int step) {
	return this->performeTests(n, minSize, step, 1);
}

BenchmarkManager Tester::performeTests(int n, int minSize) {
	return this->performeTests(n, minSize, 1);
}

void Tester::memoryTest() {
	this->performeTests(10000, 100, 0, 1);
}

void Tester::manualTest() {
	Graph* g = new Graph(5);
	g->addEdge(1, 0);
	g->addEdge(0, 2);
	g->addEdge(2, 1);
	g->addEdge(0, 3);
	g->addEdge(3, 4);
	SCCList* l = this->strategy->getSCC(g);
	cout << l->toString() << endl;
	delete l;
	delete g;

	g = new Graph(4);
	g->addEdge(0, 1);
	g->addEdge(1, 2);
	g->addEdge(2, 3);
	l = this->strategy->getSCC(g);
	cout << l->toString() << endl;
	delete l;
	delete g;

	g = new Graph(7);
	g->addEdge(0, 1);
	g->addEdge(1, 2);
	g->addEdge(2, 0);
	g->addEdge(1, 3);
	g->addEdge(1, 4);
	g->addEdge(1, 6);
	g->addEdge(3, 5);
	g->addEdge(4, 5);
	l = this->strategy->getSCC(g);
	cout << l->toString() << endl;
	delete l;
	delete g;

	g = new Graph(11);
	g->addEdge(0, 1); 
	g->addEdge(0, 3);
	g->addEdge(1, 2);
	g->addEdge(1, 4);
	g->addEdge(2, 0); 
	g->addEdge(2, 6);
	g->addEdge(3, 2);
	g->addEdge(4, 5); 
	g->addEdge(4, 6);
	g->addEdge(5, 6); 
	g->addEdge(5, 7);
	g->addEdge(5, 8);
	g->addEdge(5, 9);
	g->addEdge(6, 4);
	g->addEdge(7, 9);
	g->addEdge(8, 9);
	g->addEdge(9, 8);
	l = this->strategy->getSCC(g);
	cout << l->toString() << endl;
	delete l;
	delete g;

	g = new Graph(5);
	g->addEdge(0, 1);
	g->addEdge(1, 2);
	g->addEdge(2, 3);
	g->addEdge(2, 4);
	g->addEdge(3, 0);
	g->addEdge(4, 2);
	l = this->strategy->getSCC(g);
	cout << l->toString() << endl;
	delete l;
	delete g;

	system("pause");
}
