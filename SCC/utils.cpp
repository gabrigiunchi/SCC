#include "utils.h"
#include <iostream>

bool equals(set<int>* l1, set<int>* l2) {
	if (l1->size() != l2->size()) {
		return false;
	}

	auto it1 = l1->begin();
	auto it2 = l2->begin();

	while (it1 != l1->end()) {
		int e1 = *it1;
		int e2 = *it2;

		if (e1 != e2) {
			return false;
		}

		it1++;
		it2++;
	}

	return true;
}

bool equals(vector<set<int>>* v1, vector<set<int>>* v2) {
	/*if (v1.size() != v2.size()) {
	return false;
	}

	for (int i = 0; i < v1.size(); i++) {
	if (!equals(v1[i], v2[i])) {
	return false;
	}
	}

	return true;*/
	return v1->size() == v2->size();
}

bool contains(set<int> s, int element) {
	return s.find(element) != s.end();
}

int random(int limit) {
	return rand() % limit;
}

Graph* generateGraph(int size) {
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

void toString(vector<set<int>>* v) {
	using namespace std;

	for (int i = 0; i < v->size(); i++) {
		set<int> s = v->at(i);
		for (auto it = s.begin(); it != s.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
}