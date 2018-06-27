#pragma once
#include "SCCStrategy.h"

/*
	Class which implements the Tarjan's algorithm for finding strongly connected components in a directed graph
*/
class SCCTarjan : public SCCStrategy {
private:
	void visit(Graph* g, int parent, int disc[], int low[], stack<int> *stack, 
		boost::dynamic_bitset<>* stackMember, SCCList* strongComponents);

public:
	SCCTarjan();
	~SCCTarjan();
	SCCList* getSCC(Graph* g);
	SCCList* getSCC(Graph* g, double* time);
};

