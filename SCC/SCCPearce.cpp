#include "SCCPearce.h"
#include <chrono>

SCCPearce::SCCPearce() :SCCStrategy("Pearce") { }

SCCPearce::~SCCPearce() { }

void SCCPearce::visit(int v, Graph* g, SCCList* strongComponents) {
	bool root = true;
	rindex[v] = index;
	index++;
	
	auto children = g->getNeighbours(v);
	for (auto it = children->begin(); it != children->end(); ++it) {
		int w = *it;
		if (rindex[w] == 0) {
			visit(w, g, strongComponents);
		}
		if (rindex[w] < rindex[v]) {
			rindex[v] = rindex[w];
			root = false;
		}

	}
	delete children;

	// Strongly connected component found
	if (root) {
		index--;
		StronglyConnectedComponent* component = new StronglyConnectedComponent();
		int w = 0;
		while (!stack->empty() && rindex[v] <= rindex[stack->top()]) {
			w = stack->top();
			stack->pop();
			component->addNode(w);
			index--;
		}

		component->addNode(v);
		strongComponents->addComponent(component);
	}
	else {
		stack->push(v);
	}
}

SCCList* SCCPearce::getSCC(Graph* g) {
	if (g->getSize() <= 0) {
		return new SCCList();
	}

	this->index = 1;
	this->rindex = new int[g->getSize()];
	this->stack = new std::stack<int>();
	SCCList* strongComponents = new SCCList();

	for (int i = 0; i < g->getSize(); i++) {
		rindex[i] = 0;
	}

	for (int v = 0; v < g->getSize(); v++) {
		if (rindex[v] == 0) {
			visit(v, g, strongComponents);
		}
		
	}

	delete this->rindex;
	delete this->stack;

	return strongComponents;
}


SCCList* SCCPearce::getSCC(Graph* g, double* time) {
	using namespace std::chrono;

	auto start = high_resolution_clock::now();
	SCCList* l = this->getSCC(g);
	auto end = high_resolution_clock::now();

	duration<double> d = duration_cast<duration<double>>(end - start);
	*time = d.count();

	return l;
}