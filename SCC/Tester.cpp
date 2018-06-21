#include "Tester.h"
#include <iostream>
#include "utils.h"
#include <iostream>

using namespace std;

Tester::Tester(SCCStrategy* strategy) {
	this->strategy = strategy;
}

Tester::~Tester() {
	delete this->strategy;
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

	BenchmarkResult result(this->strategy->toString(), l1.equals(&l2), g->getSize(), duration1, duration2);
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
	this->performeTests(100, 1000, 0);
}

void Tester::manualTest() {
	Graph* g = new Graph(5);
	g->addEdge(1, 0);
	g->addEdge(0, 2);
	g->addEdge(2, 1);
	g->addEdge(0, 3);
	g->addEdge(3, 4);
	cout << this->strategy->getSCC(g).toString() << endl;
	delete g;

	g = new Graph(4);
	g->addEdge(0, 1);
	g->addEdge(1, 2);
	g->addEdge(2, 3);
	cout << this->strategy->getSCC(g).toString() << endl;
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
	cout << this->strategy->getSCC(g).toString() << endl;
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
	cout << this->strategy->getSCC(g).toString() << endl;
	delete g;

	g = new Graph(5);
	g->addEdge(0, 1);
	g->addEdge(1, 2);
	g->addEdge(2, 3);
	g->addEdge(2, 4);
	g->addEdge(3, 0);
	g->addEdge(4, 2);
	cout << this->strategy->getSCC(g).toString() << endl;
	delete g;

	system("pause");
}
