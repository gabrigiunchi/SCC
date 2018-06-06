#include <iostream>
#include <time.h> 
#include "Tester.h"
#include "SCCTarjan.h"
#include "SCCNuutila.h"
#include "SCCPearce.h"

using namespace std;

void menu() {
	string input;
	int n = 10000;
	int minSize = 1000;
	int step = 100;

	do {
		cout << endl << " 1) Test Tarjan algorithm" << endl
			<< " 2) Test Nuutila algorithm" << endl
			<< " 3) Test Pearce algorithm" << endl
			<< " 4) Test all algorithms" << endl
			<< " 5) Memory test" << endl
			<< endl << " > ";

		cin >> input;

		if (input == "1") {
			cout << endl;
			cout << Tester(new SCCTarjan()).performeTests(n, minSize, step).toString() << endl;
		}
		else if (input == "2") {
			cout << endl;
			cout << Tester(new SCCNuutila()).performeTests(n, minSize, step).toString() << endl;
		}
		else if (input == "3") {
			cout << endl;
			cout << Tester(new SCCPearce()).performeTests(n, minSize, step).toString() << endl;
		}
		else if (input == "4") {
			BenchmarkManager resultTarjan = Tester(new SCCTarjan()).performeTests(n, minSize, step);
			BenchmarkManager resultNuutila = Tester(new SCCNuutila()).performeTests(n, minSize, step);
			BenchmarkManager resultPearce = Tester(new SCCPearce()).performeTests(n, minSize, step);
			cout << resultTarjan.toString() << endl
				<< resultNuutila.toString() << endl
				<< resultPearce.toString() << endl;
		}
		else if (input == "5") {
			Tester(new SCCTarjan()).memoryTest();
		}

	} while (input != "exit" && input != "quit");
}


int main() {
	// Inizialize seed for the random fuction
	srand(time(NULL));

	menu();
	
	return 0;
}
