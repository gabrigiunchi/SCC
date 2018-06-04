#pragma once

#include <unordered_set>

using namespace std;

/*
*	Class which defines the concept of a strongly connected component: a set of vertex which are strongly connected to each other.
*/
class StronglyConnectedComponent {
private: 
	unordered_set<int> nodes;

public:
	StronglyConnectedComponent();
	StronglyConnectedComponent(unordered_set<int> set);
	void addNode(int node);
	unordered_set<int> getNodes();
	bool equals(StronglyConnectedComponent other);
	string toString();
};

