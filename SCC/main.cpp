#include <iostream>
#include <time.h> 
#include "Tester.h"
#include "SCCTarjan.h"
#include "SCCNuutila.h"
#include "SCCPearce.h"
#include "utils.h"

using namespace std;

void getInput(int* n, int *minSize, int* step) {
	cout << endl << " Do you want to customize the test parameters? (y/n) " << endl << " > ";
	string input;
	cin >> input;

	if (input == "y") {
		cout << " Insert <number of tests> <start graph size> <increment>" << endl << " > ";
		cin >> *n >> *minSize >> *step;
	}

	cout << endl;
}

void menu() {
	string input;
	
	do {
		int n = 100;
		int minSize = 1000;
		int step = 0;

		cout << endl << " 1) Test Tarjan algorithm" << endl
			<< " 2) Test Nuutila algorithm" << endl
			<< " 3) Test Pearce algorithm" << endl
			<< " 4) Test all algorithms" << endl
			<< " 5) Memory test" << endl
			<< endl << " > ";

		cin >> input;

		if (input == "1") {
			getInput(&n, &minSize, &step);
			cout << Tester(new SCCTarjan()).performeTests(n, minSize, step).toString() << endl;
		}
		else if (input == "2") {
			getInput(&n, &minSize, &step);
			cout << Tester(new SCCNuutila()).performeTests(n, minSize, step).toString() << endl;
		}
		else if (input == "3") {
			getInput(&n, &minSize, &step);
			cout << Tester(new SCCPearce()).performeTests(n, minSize, step).toString() << endl;
		}
		else if (input == "4") {
			getInput(&n, &minSize, &step);
			BenchmarkManager resultTarjan = Tester(new SCCTarjan()).performeTests(n, minSize, step);
			BenchmarkManager resultNuutila = Tester(new SCCNuutila()).performeTests(n, minSize, step);
			BenchmarkManager resultPearce = Tester(new SCCPearce()).performeTests(n, minSize, step);
			cout << resultTarjan.toString() << endl
				<< resultNuutila.toString() << endl
				<< resultPearce.toString() << endl;
		}
		else if (input == "5") {
			cout << endl;
			Tester(new SCCNuutila()).memoryTest();
		}

	} while (input != "exit" && input != "quit");
}

int main() {
	// Inizialize seed for the random fuction
	srand(time(NULL));

	menu();

	return 0;
}
