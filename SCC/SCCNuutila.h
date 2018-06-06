#pragma once
#include "SCCStrategy.h"

class SCCNuutila : public SCCStrategy {
private:
	void SCCNuutilaUtil(Graph* g, int parent, int disc[], int low[], stack<int> *stack, boost::dynamic_bitset<>* stackMember,
		SCCList* strongComponents);
public:
	SCCNuutila();
	SCCList getSCC(Graph* g);
};

