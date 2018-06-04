#pragma once

#include <list>
#include "StronglyConnectedComponent.h"

using namespace std;

/*
*	Class which defines a list of strongly connected components.
*/
class SCCList {
private:
	list<StronglyConnectedComponent> components;

public:
	void addComponent(StronglyConnectedComponent component);
	bool equals(SCCList other);
	list<StronglyConnectedComponent> getComponents();
	string toString();
};

