#pragma once
#include <vector>
#include <set>
#include "Graph.h"
#include <stack>
#include "SCCList.h"

class SCCStrategy {
protected:
	string algorithm;
public:
	SCCStrategy(string algorithm);
	// Finds the strongly connected components of the graph
	virtual SCCList getSCC(Graph* g) = 0;
	string toString();
};


/*
*	Finds the strongly connected components of the graph using the boost library's algorithm.
*/
vector<int> SCCBoost(Graph* g, int* nComponents);