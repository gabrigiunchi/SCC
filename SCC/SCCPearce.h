#pragma once

#include "SCCStrategy.h"
#include <boost/dynamic_bitset.hpp>

/*
	Class which implements the Pearce's algorithm for finding strongly connected components in a directed graph
*/
class SCCPearce : public SCCStrategy {
private:
	void visit(Graph* g, int v, int* index, int rindex[], stack<int>* stack, SCCList* strongComponents);
public:
	SCCPearce();
	SCCList* getSCC(Graph* g);
	SCCList* getSCC(Graph* g, double* time);
};

