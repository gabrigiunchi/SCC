#include "SCCPearce.h"
#include <chrono>

SCCPearce::SCCPearce() :SCCStrategy("Pearce") { }

void SCCPearce::visit(Graph* g, int v, int* index, int rindex[], stack<int>* stack, SCCList* strongComponents) {
	bool root = true;
	rindex[v] = *index;
	(*index)++;
	
	auto children = g->getChildren(v);
	for (auto it = children->begin(); it != children->end(); ++it) {
		int c = *it;
		if (rindex[c] == 0) {
			visit(g, c, index, rindex, stack, strongComponents);
		}
		if (rindex[c] < rindex[v]) {
			rindex[v] = rindex[c];
			root = false;
		}

	}
	delete children;

	if (root) {
		(*index)--;
		StronglyConnectedComponent* component = new StronglyConnectedComponent();
		while (!stack->empty() && rindex[v] <= rindex[stack->top()]) {
			int w = stack->top();
			stack->pop();
			component->addNode(w);
			(*index)--;
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

	int index = 1;
	int* rindex = new int[g->getSize()];
	stack<int> *stack = new std::stack<int>();
	SCCList* strongComponents = new SCCList();

	for (int i = 0; i < g->getSize(); i++) {
		rindex[i] = 0;
	}

	for (int i = 0; i < g->getSize(); i++) {
		if (rindex[i] == 0) {
			visit(g, i, &index, rindex, stack, strongComponents);
		}
		
	}

	delete rindex;
	delete stack;

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