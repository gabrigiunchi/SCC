#include <iostream>
#include <time.h> 
#include <stdlib.h>
#include "Tester.h"
#include "SCCTarjan.h"
#include "SCCNuutila.h"
#include "SCCPearce.h"
#include "utils.h"

using namespace std;

void getInput(int* minSize, int *maxSize, int* step) {
	cout << " Insert <min graph size> <max graph size> <increment>" << endl << " > ";
	cin >> *minSize >> *maxSize >> *step;

	// Handle invalid input
	if (*minSize < 0) *minSize = 0;
	if (*maxSize < 0) *maxSize = 0;
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
	int minSize = 1000;
	int maxSize = 10000;
	int step = 1000;
	int n = step != 0 ? (maxSize - minSize) / step + 1 : 0; // Set number of tests accordingly to parameters
	string input;
	
	do {
		cout << endl << " 1) Test Tarjan algorithm" << endl
			<< " 2) Test Nuutila algorithm" << endl
			<< " 3) Test Pearce algorithm" << endl
			<< " 4) Test all algorithms" << endl
			<< " 5) Memory test" << endl
			<< " 6) Set parameters (current: minSize=" << minSize << ", maxSize=" << maxSize << ", step=" << step << ")"
			<< endl << " > ";

		cin >> input;
		int code = parseInt(input[0]); // Parse the first character of the string

		cout << endl;
		switch (code) {
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
				getInput(&minSize, &maxSize, &step);
				n = step != 0 ? (maxSize - minSize) / step + 1 : 0; // Update number of tests
				break;
			}
			default: break;
		}
	} while (input != "exit" && input != "quit");
}

int main(int argc, char* argv[]) {
	// Inizialize seed for the random fuction
	srand(time(NULL));

	menu();

	return 0;
}
