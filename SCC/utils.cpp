#include "utils.h"
#include <iostream>

int random(int limit) {
	return rand() % limit;
}

double round(double n, int precision) {
	if (precision <= 0) {
		return n;
	}

	double temp = pow(10, precision);
	return round(n * temp) / temp;
}

Graph* generateGraph(int size, double factor) {
	if (size <= 0) {
		return new Graph(0);
	}

	Graph* g = new Graph(size);
	int nEdges = size * factor;
	for (int i = 0; i < nEdges; i++) {
		int source = random(size);
		int destination = random(size);
		if (source != destination) {
			g->addEdge(source, destination);
		}
	}

	return g;
}

Graph* generateGraph(int size) {
	return generateGraph(size, 1);
}

SCCList* convert(vector<int> v, int nComponents) {
	vector<StronglyConnectedComponent*> groups;
	for (int i = 0; i < nComponents; i++) {
		groups.push_back(new StronglyConnectedComponent());
	}

	for (int current = 0; current < v.size(); current++) {
		int component = v[current];
		groups[component]->addNode(current);
	}

	return new SCCList(groups);
}