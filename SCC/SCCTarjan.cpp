#include "SCCTarjan.h"
#include <chrono>

#define NIL -1

SCCTarjan::SCCTarjan() :SCCStrategy("Tarjan") { }

SCCTarjan::~SCCTarjan() { }

void SCCTarjan::visit(Graph* g, int v, int* time, int disc[], int low[], stack<int> *stack, boost::dynamic_bitset<>* stackMember,
	SCCList* strongComponents) {
	
	disc[v] = *time;
	low[v] = *time;
	(*time)++;
	stack->push(v);
	stackMember->set(v, true);

	// for each successor of the node
	auto children = g->getChildren(v);
	for (auto i = children->begin(); i != children->end(); ++i) {
		int child = *i;

		// If the node hasn't been visited yet we continue the dfs
		if (disc[child] == -1) {
			visit(g, child, time, disc, low, stack, stackMember, strongComponents);

			// Call back from dfs (when it backtracks)
			low[v] = min(low[v], low[child]);
		}

		// If the current node is on the stack we update its low-link value
		else if ((*stackMember)[child] == true) {
			low[v] = min(low[v], disc[child]);
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

	int time = 0;
	int *disc = new int[g->getSize()];
	int *low = new int[g->getSize()];
	boost::dynamic_bitset<> *stackMember = new boost::dynamic_bitset<>(g->getSize());
	stack<int> *stack = new std::stack<int>();
	SCCList* strongComponents = new SCCList();

	// Initialize disc and low (stackMember is already initialized)
	for (int i = 0; i < g->getSize(); i++) {
		disc[i] = NIL;
		low[i] = NIL;
	}

	// For every node we call the recursive function visit
	for (int i = 0; i < g->getSize(); i++) {
		if (disc[i] == NIL) {
			visit(g, i, &time, disc, low, stack, stackMember, strongComponents);
		}
	}

	delete disc;
	delete low;
	delete stackMember;
	delete stack;

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