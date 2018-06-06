#include "utils.h"
#include <iostream>


int random(int limit) {
	return rand() % limit;
}

Graph* generateGraph(int size) {
	if (size <= 0) {
		return new Graph(0);
	}

	Graph* g = new Graph(size);
	int nEdges = random(size * 2);
	for (int i = 0; i < nEdges; i++) {
		int source = random(size);
		int destination = random(size);
		if (source != destination) {
			g->addEdge(source, destination);
		}
	}

	return g;
}

SCCList convert(vector<int> v, int nComponents) {
	vector<unordered_set<int>> groups(nComponents);

	for (int current = 0; current < v.size(); current++) {
		int component = v[current];
		groups[component].insert(current);
	}

	SCCList res;
	for (int i = 0; i < groups.size(); i++) {
		res.addComponent(StronglyConnectedComponent(groups[i]));
	}

	return res;
}