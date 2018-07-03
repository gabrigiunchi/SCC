#include "SCCNuutila.h"
#include <chrono>

#define NIL -1

SCCNuutila::SCCNuutila() :SCCStrategy("Nuutila") { }

SCCNuutila::~SCCNuutila() { }

void SCCNuutila::visit(int v, Graph* g, SCCList* strongComponents) {
	disc[v] = time;
	low[v] = time;
	time++;
	stackMember->set(v, true);

	// for each successor of the node
	auto children = g->getChildren(v);
	for (auto i = children->begin(); i != children->end(); ++i) {
		int w = *i;

		// If the node hasn't been visited yet we continue the dfs
		if (disc[w] == NIL) {
			visit(w, g, strongComponents);

			// Call back from dfs (when it backtracks)
			low[v] = min(low[v], low[w]);
		}

		// If the current node is on the stack we update its low-link value
		else if ((*stackMember)[w] == true) {
			low[v] = min(low[v], disc[w]);
		}
	}
	delete children;

	// If parent is the root node of our group then we have found a strong component
	if (low[v] == disc[v]) {
		// Collect the node which are in the strong component
		StronglyConnectedComponent* group = new StronglyConnectedComponent();
		while (!stack->empty() && disc[stack->top()] > disc[v]) {
			int node = stack->top();
			group->addNode(node);
			stackMember->set(node, false);
			stack->pop();
		}
		group->addNode(v);
		stackMember->set(v, false);

		// Add the strong component just calculated to the list of strong components
		strongComponents->addComponent(group);
	}
	else {
		stack->push(v);
		stackMember->set(v, true);
	}
}

SCCList* SCCNuutila::getSCC(Graph* g) {
	if (g->getSize() <= 0) {
		return new SCCList();
	}

	this->time = 0;
	this->disc = new int[g->getSize()]; // n words
	this->low = new int[g->getSize()]; // n words
	this->stackMember = new boost::dynamic_bitset<>(g->getSize()); // n bits
	this->stack = new std::stack<int>();
	SCCList* strongComponents = new SCCList();

	// Initialize disc and low (stackMember is already initialized)
	for (int i = 0; i < g->getSize(); i++) {
		disc[i] = NIL;
		low[i] = NIL;
	}

	// For every node we call the recursive function visit
	for (int v = 0; v < g->getSize(); v++) {
		if (disc[v] == NIL) {
			visit(v, g, strongComponents);
		}
	}

	delete this->disc;
	delete this->low;
	delete this->stackMember;
	delete this->stack;

	return strongComponents;
}


SCCList* SCCNuutila::getSCC(Graph* g, double* time) {
	using namespace std::chrono;

	auto start = high_resolution_clock::now();
	SCCList* l = this->getSCC(g);
	auto end = high_resolution_clock::now();

	duration<double> d = duration_cast<duration<double>>(end - start);
	*time = d.count();

	return l;
}