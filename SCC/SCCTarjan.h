#pragma once

#include "SCCStrategy.h"
#include <boost/dynamic_bitset.hpp>

/*
	Class which implements the Tarjan's algorithm for finding strongly connected components in a directed graph
*/
class SCCTarjan : public SCCStrategy {
private:
	int index;
	int* disc; // n words
	int* low; // n words
	boost::dynamic_bitset<>* stackMember; // n bits
	stack<int>* stack; // n words in the worst case
	void visit(int v, Graph* g, SCCList* strongComponents);

public:
	SCCTarjan();
	~SCCTarjan();
	SCCList* getSCC(Graph* g);
	SCCList* getSCC(Graph* g, double* time);
};

