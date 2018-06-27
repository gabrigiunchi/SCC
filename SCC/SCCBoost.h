#pragma once
#include "SCCStrategy.h"

/*
	Class which uses the boost library to calculate strongly connected components in a directed graph
*/
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

