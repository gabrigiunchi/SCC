#pragma once
#include "SCCStrategy.h"

class SCCTarjan : public SCCStrategy {
private:
	void visit(Graph* g, int parent, int disc[], int low[], stack<int> *stack, 
		boost::dynamic_bitset<>* stackMember, SCCList* strongComponents);

public:
	SCCTarjan();
	SCCList getSCC(Graph* g);
};

