#pragma once
#include "SCCStrategy.h"

class SCCBoost : public SCCStrategy {
private:
	vector<int>* util(graph_t* g, int size, int* nComponents, double* time);
	vector<int>* util(graph_t* g, int size, int* nComponents);
public:
	SCCBoost();
	~SCCBoost();
	SCCList* getSCC(Graph* g);
	SCCList* getSCC(Graph* g, double* time);
};

