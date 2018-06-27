#include <iostream>
#include <time.h> 
#include <stdlib.h>
#include "Tester.h"
#include "SCCTarjan.h"
#include "SCCNuutila.h"
#include "SCCPearce.h"
#include "SCCBoost.h"
#include "utils.h"

#define DEFAULT_N_TESTS 10
#define DEFAULT_SIZE 100
#define DEFAULT_EDGE_FACTOR 1
#define DEFAULT_INCREMENT 0

using namespace std;

void showInformation() {
	
}

int parseInt(char digit) {
	// Handle invalid input
	if (digit < '0' && digit > '9') {
		return 0;
	}

	return digit - '0';
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
		cout << endl
			<< " 0) Exit" << endl
			<< " 1) Test Tarjan algorithm" << endl
			<< " 2) Test Nuutila algorithm" << endl
			<< " 3) Test Pearce algorithm" << endl
			<< " 4) Test all algorithms" << endl
			<< " 5) Memory test" << endl
			<< " 6) Set test parameters (current: number of tests=" << n << ", step=" << step << ")"
				<< endl
			<< " 7) Set graph properties (current: size=" << minSize << ", edge factor=" << factor << ")" << endl
			<< " 8) What are 'test parameters' and 'graph properties'?" << endl
			<< endl << " > ";

		cin >> input;
		code = parseInt(input[0]); // Parse the first character of the string

		cout << endl;
		switch (code) {
			case 0: exit = true; break;
			case 1: cout << Tester(new SCCTarjan()).performeTests(n, minSize, step, factor).toString() << endl; break;
			case 2: cout << Tester(new SCCNuutila()).performeTests(n, minSize, step, factor).toString() << endl; break;
			case 3: cout << Tester(new SCCPearce()).performeTests(n, minSize, step, factor).toString() << endl; break;
			case 4: {
				BenchmarkManager resultTarjan = Tester(new SCCTarjan()).performeTests(n, minSize, step, factor);
				BenchmarkManager resultNuutila = Tester(new SCCNuutila()).performeTests(n, minSize, step, factor);
				BenchmarkManager resultPearce = Tester(new SCCPearce()).performeTests(n, minSize, step, factor);
				cout << " Tarjan: " << resultTarjan.toString() << endl
					<< " Nuutila: " << resultNuutila.toString() << endl
					<< " Pearce: " << resultPearce.toString() << endl;
				break;
			}
			case 5: Tester(new SCCPearce()).memoryTest(); break;
			case 6: {
				cout << " Insert <number of tests> <increment>" << endl << " > ";
				cin >> n >> step;
				if (n < 0) n = DEFAULT_N_TESTS;
				if (step < 0) step = DEFAULT_INCREMENT;
				break;
			}
			case 7: {
				cout << " Insert <size> <edge factor>" << endl << " > ";
				cin >> minSize >> factor;
				if (minSize < 0) minSize = DEFAULT_SIZE;
				if (factor <= 0) factor = DEFAULT_EDGE_FACTOR;
				break;
			}
			case 8: showInformation(); break;
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
