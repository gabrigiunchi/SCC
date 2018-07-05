#pragma once

#include <vector>
#include "StronglyConnectedComponent.h"

using namespace std;

/*
	Class which defines a list of strongly connected components
*/
class SCCList {
private:
	vector<StronglyConnectedComponent*> components;

public:
	SCCList();
	~SCCList();
	SCCList(vector<StronglyConnectedComponent*> c);
	void addComponent(StronglyConnectedComponent* component);
	bool equals(SCCList* other);
	vector<StronglyConnectedComponent*> getComponents();
	string toString();
};

