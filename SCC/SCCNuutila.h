#pragma once

#include "SCCStrategy.h"
#include <boost/dynamic_bitset.hpp>

/*
	Class which implements the Nuutila's algorithm for finding strongly connected components in a directed graph
*/
class SCCNuutila : public SCCStrategy {
private:
	int time;
	int* disc; // n words
	int* low; // n words
	boost::dynamic_bitset<>* stackMember; // n bits
	stack<int>* stack; 
	
	void visit(int v, Graph* g, SCCList* strongComponents);
public:
	SCCNuutila();
	~SCCNuutila();
	SCCList* getSCC(Graph* g);
	SCCList* getSCC(Graph* g, double* time);
};

