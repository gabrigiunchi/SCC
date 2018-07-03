#include "SCCPearceIterative.h"
#include <chrono>

SCCPearceIterative::SCCPearceIterative(): SCCStrategy("Pearce Iterative") { }

SCCPearceIterative::~SCCPearceIterative() { }

void SCCPearceIterative::visit(int v, Graph* g, SCCList* scc) {
	this->beginVisiting(v);
	while (!vS->empty()) {
		this->visitLoop(g, scc);
	}
}

void SCCPearceIterative::visitLoop(Graph* g, SCCList* scc) {
	int v = vS->top();
	int i = iS->top();
	auto children = g->getChildren(v);

	// Traverse the vertex's children
	while (i <= children->size()) {
		if (i > 0) {
			finishEdge(v, i - 1, children->at(i - 1));
		}
		if (i < children->size() && beginEdge(v, i, children->at(i))) {
			return;
		}
		i++;
	}
	delete children;

	finishVisiting(v, scc);
}

void SCCPearceIterative::beginVisiting(int v) {
	// First time we visit the node
	vS->push(v);
	iS->push(0);
	root->set(v, true);
	rindex[v] = index;
	index++;
}

void SCCPearceIterative::finishVisiting(int v, SCCList* scc) {
	vS->pop();
	iS->pop();
	bool a = (*root)[v];

	// Found a strongly connected component
	if ((*root)[v] == true) {
		index--;

		int w = 0;
		StronglyConnectedComponent* component = new StronglyConnectedComponent();
		
		while (!S->empty() && rindex[v] <= rindex[S->top()]) {
			w = S->top();
			S->pop();
			component->addNode(w);
			index--;
		}
		component->addNode(v);
		scc->addComponent(component);
	}
	else {
		S->push(v);
	}
}

bool SCCPearceIterative::beginEdge(int v, int k, int w) {
	if (rindex[w] == 0) {
		iS->pop();
		iS->push(k + 1);
		beginVisiting(w);
		return true;
	}
	else {
		return false;
	}
}

void SCCPearceIterative::finishEdge(int v, int k, int w) {
	if (rindex[w] < rindex[v]) {
		rindex[v] = rindex[w];
		root->set(v, false);
	}
}


SCCList* SCCPearceIterative::getSCC(Graph* g) {
	this->rindex = new int[g->getSize()];
	this->index = 1;
	this->root = new boost::dynamic_bitset<>(g->getSize());
	this->vS = new stack<int>();
	this->iS = new stack<int>();
	this->S = new stack<int>();
	SCCList* scc = new SCCList();

	// Initialize rindex
	for (int i = 0; i < g->getSize(); i++) {
		rindex[i] = 0;
	}

	for (int v = 0; v < g->getSize(); v++) {
		if (rindex[v] == 0) {
			this->visit(v, g, scc);
		}
	}

	delete this->root;
	delete this->S;
	delete this->rindex;
	delete this->vS;
	delete this->iS;

	return scc;
}

SCCList* SCCPearceIterative::getSCC(Graph* g, double* time) {
	using namespace std::chrono;

	auto start = high_resolution_clock::now();
	SCCList* l = this->getSCC(g);
	auto end = high_resolution_clock::now();

	duration<double> d = duration_cast<duration<double>>(end - start);
	*time = d.count();

	return l;
}
