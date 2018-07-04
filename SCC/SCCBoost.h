#pragma once

#include "SCCStrategy.h"

/*
	Class which uses the boost library to calculate strongly connected components in a directed graph
*/
class SCCBoost : public SCCStrategy {
private:
	vector<int> getSCC(Graph* g, int* nComponents);
	vector<int> getSCC(Graph* g, int* nComponents, double* time);
public:
	SCCBoost();
	~SCCBoost();
	SCCList* getSCC(Graph* g);
	SCCList* getSCC(Graph* g, double* time);
};

