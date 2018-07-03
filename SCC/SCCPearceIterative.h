#pragma once

#include "SCCStrategy.h"
#include <boost/dynamic_bitset.hpp>

class SCCPearceIterative : public SCCStrategy {
private:
	int c;
	int* rindex;
	int index;
	boost::dynamic_bitset<>* root;
	stack<int>* vS;
	stack<int>* iS;
	stack<int>* S;

	void visit(int v, Graph* g, SCCList* scc);
	void visitLoop(Graph* g, SCCList* scc);
	void beginVisiting(int v);
	void finishVisiting(int v, SCCList* scc);
	bool beginEdge(int v, int k, int w);
	void finishEdge(int v, int k, int w);
public:
	SCCPearceIterative();
	~SCCPearceIterative();
	SCCList* getSCC(Graph* g, double* time);
	SCCList* getSCC(Graph* g);
};

