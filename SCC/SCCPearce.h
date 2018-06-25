#pragma once
#include "SCCStrategy.h"

class SCCPearce : public SCCStrategy {
private:
	void visit(Graph* g, int v, int rindex[], stack<int>* stack, boost::dynamic_bitset<>* inComponent, 
		boost::dynamic_bitset<>* visited, SCCList* strongComponents);
public:
	SCCPearce();
	SCCList* getSCC(Graph* g);
	SCCList* getSCC(Graph* g, double* time);
};

