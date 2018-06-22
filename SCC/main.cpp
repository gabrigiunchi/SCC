#include <iostream>
#include <time.h> 
#include <stdlib.h>
#include "Tester.h"
#include "SCCTarjan.h"
#include "SCCNuutila.h"
#include "SCCPearce.h"
#include "utils.h"

#define DEFAULT_N_TESTS 10

using namespace std;

void getInput(int* n, int* minSize, int* step) {
	cout << " Insert <number of tests> <start graph size> <increment>" << endl << " > ";
	cin >> *n >> *minSize >> *step;

	// Handle invalid input
	if (*minSize < 0) *minSize = 0;
	if (*n < 0) *n = DEFAULT_N_TESTS;
	if (*step < 0) *step = 0;
}

int parseInt(char digit) {
	// Handle invalid input
	if (digit < '0' && digit > '9') {
		return 0;
	}

	return digit - '0';
}

void menu() {
	int minSize = 100;
	int step = 0;
	int n = DEFAULT_N_TESTS;
	string input;
	bool exit = false;

	do {
		cout << endl 
			<< " 0) Exit" << endl
			<< " 1) Test Tarjan algorithm" << endl
			<< " 2) Test Nuutila algorithm" << endl
			<< " 3) Test Pearce algorithm" << endl
			<< " 4) Test all algorithms" << endl
			<< " 5) Memory test" << endl
			<< " 6) Set parameters (current: number of tests=" << n << ", start graph size=" << minSize << ", step=" << step << ")"
			<< endl << endl << " > ";

		cin >> input;
		int code = parseInt(input[0]); // Parse the first character of the string

		cout << endl;
		switch (code) {
			case 0: exit = true; break;
			case 1: cout << Tester(new SCCTarjan()).performeTests(n, minSize, step).toString() << endl; break;
			case 2: cout << Tester(new SCCNuutila()).performeTests(n, minSize, step).toString() << endl; break;
			case 3: cout << Tester(new SCCPearce()).performeTests(n, minSize, step).toString() << endl; break;
			case 4: {
				BenchmarkManager resultTarjan = Tester(new SCCTarjan()).performeTests(n, minSize, step);
				BenchmarkManager resultNuutila = Tester(new SCCNuutila()).performeTests(n, minSize, step);
				BenchmarkManager resultPearce = Tester(new SCCPearce()).performeTests(n, minSize, step);
				cout << " Tarjan: " << resultTarjan.toString() << endl
					<< " Nuutila: " << resultNuutila.toString() << endl
					<< " Pearce: " << resultPearce.toString() << endl;
				break;
			}
			case 5: Tester(new SCCPearce()).memoryTest(); break;
			case 6: {
				getInput(&n, &minSize, &step);
				break;
			}
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
