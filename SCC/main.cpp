#include <iostream>
#include <time.h> 
#include "test.h"
#include <unordered_set>
#include "utils.h"
#include "StronglyConnectedComponent.h"
#include "SCCList.h"

using namespace std;

StronglyConnectedComponent generate(int a, int b, int c) {
	StronglyConnectedComponent co;
	
	co.addNode(a);
	co.addNode(b);
	co.addNode(c);

	return co;
}

void foo() {
	SCCList* l1 = new SCCList();
	SCCList* l2 = new SCCList();

	l1->addComponent(generate(1, 2, 3));
	l1->addComponent(generate(4, 5, 6));
	l1->addComponent(generate(7, 8, 9));

	unordered_set<int> s;
	s.insert(8);
	s.insert(7);
	l2->addComponent(StronglyConnectedComponent(s));
	l2->addComponent(generate(1, 3, 2));
	l2->addComponent(generate(4, 5, 6));

	cout << l1->equals(*l2);
}

int main() {
	// Inizialize seed for the random fuction
	srand(time(NULL));

	//customTest();
	//randomTest();
	//memoryTest();

	//foo();

	cout << performTest(1, 100000)->toString();

	cout << endl << endl;
	system("pause");
	return 0;
}
