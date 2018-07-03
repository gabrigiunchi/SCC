#pragma once

#include "SCCStrategy.h"
#include <boost/dynamic_bitset.hpp>

/*
	Class which implements the Pearce's algorithm for finding strongly connected components in a directed graph
*/
class SCCPearce : public SCCStrategy {
private:
	int index;
	int* rindex; // n words
	stack<int>* stack;
	void visit(int v, Graph* g, SCCList* strongComponents);
public:
	SCCPearce();
	~SCCPearce();
	SCCList* getSCC(Graph* g);
	SCCList* getSCC(Graph* g, double* time);
};

