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
	~SCCStrategy();
	virtual SCCList* getSCC(Graph* g) = 0;
	virtual SCCList* getSCC(Graph* g, double* time) = 0;
	string toString();
};