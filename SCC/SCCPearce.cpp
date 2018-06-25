#include "SCCPearce.h"

SCCPearce::SCCPearce() :SCCStrategy("Pearce") { }

void SCCPearce::visit(Graph* g, int v, int rindex[], stack<int>* stack, boost::dynamic_bitset<>* inComponent,
	boost::dynamic_bitset<>* visited, SCCList* strongComponents) {

	static int index = 0;
	visited->set(v, true);
	bool root = true;
	inComponent->set(v, false);
	rindex[v] = index;
	index++;
	
	auto children = g->getChildren(v);
	for (auto it = children.begin(); it != children.end(); ++it) {
		int w = *it;
		if (!(*visited)[w]) {
			this->visit(g, w, rindex, stack, inComponent, visited, strongComponents);
		}

		if (!(*inComponent)[w] && rindex[w] < rindex[v]) {
			rindex[v] = rindex[w];
			root = false;
		}
	}

	if (root) {
		inComponent->set(v, true);
		StronglyConnectedComponent component;
		while (!stack->empty() && rindex[v] <= rindex[stack->top()]) {
			int w = stack->top();
			stack->pop();
			inComponent->set(w, true);
			component.addNode(w);
		}
		component.addNode(v);
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

	int *rindex = new int[g->getSize()];
	boost::dynamic_bitset<>* visited = new boost::dynamic_bitset<>(g->getSize());
	boost::dynamic_bitset<>* inComponent = new boost::dynamic_bitset<>(g->getSize());
	stack<int> *stack = new std::stack<int>();
	SCCList* strongComponents = new SCCList();

	for (int i = 0; i < g->getSize(); i++) {
		if (!(*visited)[i]) {
			this->visit(g, i, rindex, stack, inComponent, visited, strongComponents);
		}
	}

	return strongComponents;
}

SCCList* SCCPearce::getSCC(Graph* g, double* time) {
	clock_t start = clock();
	SCCList* l = this->getSCC(g);
	*time = (clock() - start) / (double)CLOCKS_PER_SEC;
	return l;
}