#pragma once
#include <vector>
#include <set>
#include "Graph.h"
#include <stack>
#include "SCCList.h"

/*
	Abstract class used to implement the Strategy pattern, in this case the strategy represents the algorithm used to
	calculate the strongly connected components in a directed graph. 
*/
class SCCStrategy {
protected:
	string algorithm;

public:
	SCCStrategy(string algorithm);
	~SCCStrategy();

	/*
		Calculate the strongly connected components of the given graph
	*/
	virtual SCCList* getSCC(Graph* g) = 0;

	/*
		Calculate the strongly connected components of the given graph and measure the time took to perform the task
	*/
	virtual SCCList* getSCC(Graph* g, double* time) = 0;

	string getName();
};

SCCStrategy* getDefaultStrategy();