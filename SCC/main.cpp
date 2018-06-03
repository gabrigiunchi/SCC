#include <iostream>
#include <time.h> 
#include "test.h"

using namespace std;

int main() {
	// Inizialize seed for the random fuction
	srand(time(NULL));

	//customTest();
	randomTest();
	//memoryTest();

	cout << endl << endl;
	system("pause");
	return 0;
}
