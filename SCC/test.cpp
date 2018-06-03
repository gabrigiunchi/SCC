#include "BenchmarkManager.h"
#include "utils.h"
#include "SCCStrategy.h"
#include <iostream>

using namespace std;

BenchmarkResult testAlgorithm(Graph* g) {
	// Calculate time with custom algorithm
	clock_t start1;
	double duration1;
	start1 = clock();
	auto v1 = SCCTarjan(g);
	duration1 = (clock() - start1) / (double)CLOCKS_PER_SEC;

	// Calculate time with boost's algorithm
	clock_t start2;
	double duration2;
	start2 = clock();
	auto v2 = SCCBoost(g);
	duration2 = (clock() - start2) / (double)CLOCKS_PER_SEC;

	BenchmarkResult result;
	result.success = equals(v1, v2);
	result.diffTime = duration2 - duration1;

	delete v1;
	delete v2;
	return result;
}

void performTest(int testCases, int size, BenchmarkManager* benchmark) {
	int successCount = 0;

	for (int i = 0; i < testCases; i++) {
		Graph* g = generateGraph(size);
		BenchmarkResult result = testAlgorithm(g);
		successCount += result.success;
		benchmark->addResult(result);
		delete g;
	}
}

void randomTest() {
	int testCases = 10; // number of tests performed for each graph size
	int maxSize = 10000;
	BenchmarkManager* benchmark = new BenchmarkManager();

	// Performs the test with incrementally graph size
	for (int i = 1; i <= maxSize; i++) {
		performTest(testCases, i, benchmark);
		cout << "(size = " << i << "): "
			<< " Success rate:= " << benchmark->getSuccessRate() << "%"
			<< " ; "
			<< "average diff time = " << benchmark->getAverageDiffTime() 
			<< endl;

		benchmark->clear();
	}

	delete benchmark;
}

void test1() {
	Graph* g = new Graph(5);
	g->addEdge(1, 0);
	g->addEdge(0, 2);
	g->addEdge(2, 1);
	g->addEdge(0, 3);
	g->addEdge(3, 4);
	auto v1 = SCCTarjan(g);

	int successCount = 0;
	successCount += contains(v1->at(0), 4);
	successCount += contains(v1->at(1), 3);
	successCount += contains(v1->at(2), 1);
	successCount += contains(v1->at(2), 2);
	successCount += contains(v1->at(2), 0);
	cout << "test1: " << successCount << "/5" << endl;

	delete v1;
	delete g;
}

void test2() {
	Graph* g = new Graph(4);
	g->addEdge(0, 1);
	g->addEdge(1, 2);
	g->addEdge(2, 3);
	auto v1 = SCCTarjan(g);

	int successCount = 0;
	successCount += contains(v1->at(0), 3);
	successCount += contains(v1->at(1), 2);
	successCount += contains(v1->at(2), 1);
	successCount += contains(v1->at(3), 0);
	cout << "test2: " << successCount << "/4" << endl;

	delete v1;
	delete g;
}

void test3() {
	Graph* g = new Graph(7);
	g->addEdge(0, 1);
	g->addEdge(1, 2);
	g->addEdge(2, 0);
	g->addEdge(1, 3);
	g->addEdge(1, 4);
	g->addEdge(1, 6);
	g->addEdge(3, 5);
	g->addEdge(4, 5);
	auto v1 = SCCTarjan(g);

	int successCount = 0;
	successCount += contains(v1->at(0), 5);
	successCount += contains(v1->at(1), 3);
	successCount += contains(v1->at(2), 4);
	successCount += contains(v1->at(3), 6);
	successCount += contains(v1->at(4), 2);
	successCount += contains(v1->at(4), 1);
	successCount += contains(v1->at(4), 0);
	cout << "test3: " << successCount << "/7" << endl;

	delete v1;
	delete g;
}

void test4() {
	Graph* g = new Graph(11);
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
	auto v1 = SCCTarjan(g);

	int successCount = 0;
	successCount += contains(v1->at(0), 8);
	successCount += contains(v1->at(0), 9);
	successCount += contains(v1->at(1), 7);
	successCount += contains(v1->at(2), 5);
	successCount += contains(v1->at(2), 4);
	successCount += contains(v1->at(2), 6);
	successCount += contains(v1->at(3), 3);
	successCount += contains(v1->at(3), 2);
	successCount += contains(v1->at(3), 1);
	successCount += contains(v1->at(3), 0);
	successCount += contains(v1->at(4), 10);
	cout << "test4: " << successCount << "/11" << endl;

	delete v1;
	delete g;
}

void test5() {
	Graph* g = new Graph(5);
	g->addEdge(0, 1);
	g->addEdge(1, 2);
	g->addEdge(2, 3);
	g->addEdge(2, 4);
	g->addEdge(3, 0);
	g->addEdge(4, 2);
	auto v1 = SCCTarjan(g);

	int successCount = 0;
	successCount += contains(v1->at(0), 4);
	successCount += contains(v1->at(0), 3);
	successCount += contains(v1->at(0), 2);
	successCount += contains(v1->at(0), 1);
	successCount += contains(v1->at(0), 0);
	cout << "test5: " << successCount << "/5" << endl;

	delete v1;
	delete g;
}

void customTest() {
	test1();
	test2();
	test3();
	test4();
	test5();
}


void memoryTest() {
	performTest(1000000000, 100, new BenchmarkManager());
}