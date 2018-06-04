#include "Graph.h"
#include "BenchmarkManager.h"

// test with predefined graphs
void customTest();
void test1();
void test2();
void test3();
void test4();
void test5();

/*
*	Utility function which check if the custom algorithm behaves as good as the boost library's algorithm.
*	Return an instance of BenchmarkResult which contains the result of the test
*/
BenchmarkResult testAlgorithm(Graph* g);

/*
* Executes n test cases and returns the number of successfull tests.
* Every test is performed with a randomly generated graph whose size is the parameter <size>
*/
BenchmarkManager* performTest(int testCases, int size);

// Performs multiple tests with random graphs and different graph size
void randomTest();

// used to analyze the memory usage of the application.
void memoryTest();
