#include <iostream>
#include <time.h> 
#include <stdlib.h>
#include "Tester.h"
#include "SCCTarjan.h"
#include "SCCNuutila.h"
#include "SCCPearce.h"
#include "SCCBoost.h"
#include "SCCPearceIterative.h"
#include "utils.h"

#define DEFAULT_N_TESTS 5
#define DEFAULT_SIZE 1000
#define DEFAULT_EDGE_FACTOR 10
#define DEFAULT_INCREMENT 0

using namespace std;

void showInformation() {
	cout << endl
		<< "TEST PARAMETERS" << endl
		<< "<number of tests>" << endl
		<< "<increment> after each test the graph size is increased with this value"
		<< endl << endl << "GRAPH PROPERTIES" << endl
		<< "<graph size> number of vertices in the graph" << endl
		<< "<edge factor> factor used to calculate how many edges are to be inserted in the graph (number_of_edges = graph_size * edge_factor)" 
		<< endl;
}

void manualTest() {
	int algorithm = -1;
	int graphSize = 0;
	int edges = 0;
	string input;
	
	// Choose the algorithm
	while (algorithm < 0 || algorithm > 4) {
		cout << endl << "Which algorithm do you want to test?" << endl << endl
			<< "0) Go back" << endl
			<< "1) Tarjan" << endl
			<< "2) Nuutila" << endl
			<< "3) Pearce" << endl
			<< "4) Iterative Pearce" << endl
			<< endl << " > ";

		cin >> input;
		algorithm = stoi(input);
	}

	if (algorithm == 0) {
		return;
	}
	
	// Graph properties (size and number of edges)
	cout << endl << "Insert <graph size> <number of edges>: ";
	cin >> graphSize >> edges;
	if (graphSize <= 0 || edges < 0) {
		return;
	}
	
	// Get the edges as user input
	Graph* g = new Graph(graphSize);
	int source = -1;
	int destination = -1;
	cout << endl;
	for (int i = 1; i <= edges; i++) {
		cout << i << "/" << edges << " Insert <source> <destination>: ";
		cin >> source >> destination;
		if (source != destination && source >= 0) {
			g->addEdge(source, destination);
		}
	}

	// Run the test
	cout << endl << "Run the test (y/n)? ";
	cin >> input;
	if (input == "y") {
		SCCStrategy* strategy;
		switch (algorithm) {
			case 1: strategy = new SCCTarjan(); break;
			case 2: strategy = new SCCNuutila(); break;
			case 3: strategy = new SCCPearce(); break;
			case 4: strategy = new SCCPearceIterative(); break;
			default: strategy = new SCCTarjan(); break;
		}
		cout << endl;
		auto l1 = strategy->getSCC(g);
		cout << "Strongly connected components:" << endl << l1->toString() << endl;
		cout << Tester(strategy).manualTest(g).toString() << endl;
		delete l1;
	}

	delete g;
}

void menu() {
	int code = 0;
	int minSize = DEFAULT_SIZE;
	int step = DEFAULT_INCREMENT;
	int n = DEFAULT_N_TESTS;
	double factor = DEFAULT_EDGE_FACTOR;
	string input;
	bool exit = false;
	
	do {
		// Show the menu
		cout << endl
			<< "0) Exit" << endl
			<< "1) Test Tarjan algorithm" << endl
			<< "2) Test Nuutila algorithm" << endl
			<< "3) Test Pearce algorithm" << endl
			<< "4) Test Iterative Pearce algorithm" << endl
			<< "5) Test all algorithms" << endl
			<< "6) Manual test" << endl
			<< "7) Set test parameters (current: number of tests=" << n << ", step=" << step << ")"
				<< endl
			<< "8) Set graph properties (current: size=" << minSize << ", edge factor=" << factor << ")" << endl
			<< "9) What are 'test parameters' and 'graph properties'?" << endl
			<< "10) Memory test (use with debugger)" << endl
			<< endl << "> ";


		// User input
		cin >> input;
		code = stoi(input);
		cout << endl;

		switch (code) {
			case 0: exit = true; break;
			case 1: cout << Tester(new SCCTarjan()).performeTests(n, minSize, step, factor).toString() << endl; break;
			case 2: cout << Tester(new SCCNuutila()).performeTests(n, minSize, step, factor).toString() << endl; break;
			case 3: cout << Tester(new SCCPearce()).performeTests(n, minSize, step, factor).toString() << endl; break;
			case 4: cout << Tester(new SCCPearceIterative()).performeTests(n, minSize, step, factor).toString() << endl; break;
			case 5: {
				BenchmarkManager resultTarjan = Tester(new SCCTarjan()).performeTests(n, minSize, step, factor);
				BenchmarkManager resultNuutila = Tester(new SCCNuutila()).performeTests(n, minSize, step, factor);
				BenchmarkManager resultPearce = Tester(new SCCPearce()).performeTests(n, minSize, step, factor);
				cout << "Tarjan: " << resultTarjan.toString() << endl
					<< "Nuutila: " << resultNuutila.toString() << endl
					<< "Pearce: " << resultPearce.toString() << endl;
				break;
			}
			case 6: manualTest(); break;
			case 7: {
				cout << "Insert <number of tests> <increment>: ";
				cin >> n >> step;
				if (n < 0) n = DEFAULT_N_TESTS;
				if (step < 0) step = DEFAULT_INCREMENT;
				break;
			}
			case 8: {
				cout << "Insert <size> <edge factor>: ";
				cin >> minSize >> factor;
				if (minSize < 0) minSize = DEFAULT_SIZE;
				if (factor <= 0) factor = DEFAULT_EDGE_FACTOR;
				break;
			}
			case 9: showInformation(); break;
			case 10: Tester(new SCCPearceIterative()).memoryTest(); break;
			default: break;
		}
	} while (!exit);
}

int main(int argc, char* argv[]) {
	// Inizialize seed for the random fuction
	srand(time(NULL));

	menu();

	return 0;
}
