#pragma once

#include <set>

using namespace std;

/*
*	Class which defines the concept of a strongly connected component: a set of vertex which are strongly connected to each other.
*/
class StronglyConnectedComponent {
private: 
	set<int> nodes;

public:
	StronglyConnectedComponent();
	StronglyConnectedComponent(set<int> set);
	void addNode(int node);
	set<int>* getNodes();
	bool equals(StronglyConnectedComponent* other);
	string toString();
	int size();
};

