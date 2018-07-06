#include "SCCTarjan.h"
#include <chrono>

#define NIL -1

SCCTarjan::SCCTarjan() :SCCStrategy("Tarjan") { }

SCCTarjan::~SCCTarjan() { }

void SCCTarjan::visit(int v, Graph* g, SCCList* strongComponents) {
	disc[v] = index;
	low[v] = index;
	index++;
	stack->push(v);
	stackMember->set(v, true);

	// for each successor of the node
	auto children = g->getNeighbours(v);
	for (auto i = children->begin(); i != children->end(); ++i) {
		int w = *i;

		// If the node hasn't been visited yet we continue the dfs
		if (disc[w] == -1) {
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
		int w = 0;
		StronglyConnectedComponent* component = new StronglyConnectedComponent();
		while (stack->top() != v) {
			w = stack->top();
			component->addNode(w);
			stackMember->set(w, false);
			stack->pop();
		}
		w = stack->top();
		component->addNode(w);

		stackMember->set(w, false);
		stack->pop();

		// Add the strong component just calculated to the list of strong components
		strongComponents->addComponent(component);
	}
}

SCCList* SCCTarjan::getSCC(Graph* g) {
	if (g->getSize() <= 0) {
		return new SCCList();
	}

	this->index = 0;
	this->disc = new int[g->getSize()];
	this->low = new int[g->getSize()];
	this->stackMember = new boost::dynamic_bitset<>(g->getSize());
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


SCCList* SCCTarjan::getSCC(Graph* g, double* time) {
	using namespace std::chrono;

	auto start = high_resolution_clock::now();
	SCCList* l = this->getSCC(g);
	auto end = high_resolution_clock::now();

	duration<double> d = duration_cast<duration<double>>(end - start);
	*time = d.count();

	return l;
}