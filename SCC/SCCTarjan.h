#pragma once

#include "SCCStrategy.h"
#include <boost/dynamic_bitset.hpp>

/*
	Class which implements the Tarjan's algorithm for finding strongly connected components in a directed graph
*/
class SCCTarjan : public SCCStrategy {
private:
	void visit(Graph* g, int v, int* time, int disc[], int low[], stack<int> *stack, 
		boost::dynamic_bitset<>* stackMember, SCCList* strongComponents);

public:
	SCCTarjan();
	~SCCTarjan();
	SCCList* getSCC(Graph* g);
};

