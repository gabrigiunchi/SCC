#include <boost/graph/strong_components.hpp>
#include "SCCStrategy.h"

#define NIL -1

void SCCTarjanUtil(Graph* g, int parent, int disc[], int low[], stack<int> *stack, boost::dynamic_bitset<>* stackMember, 
		vector<set<int>>* strongComponents) {
	static int time = 0;

	disc[parent] = time;
	low[parent] = time;
	time++;
	stack->push(parent);
	stackMember->set(parent, true);

	// for each successor of the node
	auto children = g->getChildren(parent);
	for (auto i = children.begin(); i != children.end(); ++i) {
		int child = *i;

		// If the node hasn't been visited yet we continue the dfs
		if (disc[child] == -1) {
			SCCTarjanUtil(g, child, disc, low, stack, stackMember, strongComponents);

			// Call back from dfs (when it backtracks)
			low[parent] = min(low[parent], low[child]);
		}

		// If the current node is on the stack we update its low-link value
		else if ((*stackMember)[child] == true) {
			low[parent] = min(low[parent], disc[child]);
		}
	}

	int node = 0;

	// If parent is the root node of our group then we have found a strong component
	if (low[parent] == disc[parent]) {
		// Collect the node which are in the strong component
		set<int> group;
		while (stack->top() != parent) {
			node = stack->top();
			group.insert(node);
			stackMember->set(node, false);
			stack->pop();
		}
		node = stack->top();
		group.insert(node);

		stackMember->set(node, false);
		stack->pop();

		// Add the strong component just calculated to the list of strong components
		strongComponents->push_back(group);
	}
}

vector<set<int>>* SCCTarjan(Graph* g) {
	int *disc = new int[g->getSize()];
	int *low = new int[g->getSize()];
	boost::dynamic_bitset<> *stackMember = new boost::dynamic_bitset<>(g->getSize());
	stack<int> *stack = new std::stack<int>();
	vector<set<int>>* strongComponents = new vector<set<int>>();

	// Initialize disc and low (stackMember is already initialized)
	for (int i = 0; i < g->getSize(); i++) {
		disc[i] = NIL;
		low[i] = NIL;
	}

	// For every node we call the utility function SCCUtil
	for (int i = 0; i < g->getSize(); i++) {
		if (disc[i] == NIL) {
			SCCTarjanUtil(g, i, disc, low, stack, stackMember, strongComponents);
		}
	}

	// frees the memory
	delete disc;
	delete low;
	delete stackMember;
	delete stack;

	return strongComponents;
}

vector<set<int>>* SCCBoost(Graph* g) {
	vector<int> scc(g->getSize());
	graph_t graph = g->getGraph();
	int num = strong_components(graph, boost::make_iterator_property_map(scc.begin(), get(boost::vertex_index, graph), scc[0]));
	vector<set<int>>* groups = new vector<set<int>>(num);

	for (int current = 0; current < scc.size(); current++) {
		int component = scc[current];
		groups->at(component).insert(current);
	}

	return groups;
}