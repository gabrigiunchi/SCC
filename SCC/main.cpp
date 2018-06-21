#include <iostream>
#include <time.h> 
#include <stdlib.h>
#include "Tester.h"
#include "SCCTarjan.h"
#include "SCCNuutila.h"
#include "SCCPearce.h"
#include "utils.h"

using namespace std;

void getInput(int* n, int *minSize, int* step) {
	cout << " Do you want to customize the test parameters? (y/n) " << endl << " > ";
	string input;
	cin >> input;

	if (input == "y") {
		cout << " Insert <number of tests> <start graph size> <increment>" << endl << " > ";
		cin >> *n >> *minSize >> *step;
	}

	cout << endl;
}

void menu(int minSize, int step, int maxSize) {
	string input;
	
	do {
		int n = (maxSize - minSize) / step + 1;

		cout << endl << " 1) Test Tarjan algorithm" << endl
			<< " 2) Test Nuutila algorithm" << endl
			<< " 3) Test Pearce algorithm" << endl
			<< " 4) Test all algorithms" << endl
			<< " 5) Memory test" << endl
			<< endl << " > ";

		cin >> input;

		if (input == "1") {
			cout << endl;
			//getInput(&n, &minSize, &step);
			cout << Tester(new SCCTarjan()).performeTests(n, minSize, step).toString() << endl;
		}
		else if (input == "2") {
			cout << endl;
			//getInput(&n, &minSize, &step);
			cout << Tester(new SCCNuutila()).performeTests(n, minSize, step).toString() << endl;
		}
		else if (input == "3") {
			cout << endl;
			//getInput(&n, &minSize, &step);
			cout << Tester(new SCCPearce()).performeTests(n, minSize, step).toString() << endl;
		}
		else if (input == "4") {
			cout << endl;
			//getInput(&n, &minSize, &step);
			BenchmarkManager resultTarjan = Tester(new SCCTarjan()).performeTests(n, minSize, step);
			BenchmarkManager resultNuutila = Tester(new SCCNuutila()).performeTests(n, minSize, step);
			BenchmarkManager resultPearce = Tester(new SCCPearce()).performeTests(n, minSize, step);
			cout << " Tarjan: " << resultTarjan.toString() << endl
				<< " Nuutila: " << resultNuutila.toString() << endl
				<< " Pearce: " << resultPearce.toString() << endl;
		}
		else if (input == "5") {
			cout << endl;
			Tester(new SCCNuutila()).memoryTest();
		}

	} while (input != "exit" && input != "quit");
}

int main(int argc, char* argv[]) {
	// Inizialize seed for the random fuction
	srand(time(NULL));

	int minSize = 1000;
	int step = 1000;
	int maxSize = 10000;

	if (argc >= 2) minSize = atoi(argv[1]);
	if (argc >= 3) step = atoi(argv[2]);
	if (argc > 3) maxSize = atoi(argv[3]);

	menu(minSize, step, maxSize);

	return 0;
}
