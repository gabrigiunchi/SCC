#include "SCCList.h"
#include <sstream>
#include <unordered_set>
#include <iostream>
#include <boost/dynamic_bitset.hpp>

using namespace std;

SCCList::~SCCList() {
	delete this->components;
}

SCCList::SCCList() {
	this->components = new vector<StronglyConnectedComponent*>();
}

SCCList::SCCList(vector<StronglyConnectedComponent*>* c) {
	this->components = c;
}

vector<StronglyConnectedComponent*>* SCCList::getComponents() {
	return this->components;
}

void SCCList::addComponent(StronglyConnectedComponent* component) {
	this->components->push_back(component);
}

bool SCCList::equals(SCCList* other) {
	if (this->components->size() != other->getComponents()->size()) {
		return false;
	}

	vector<StronglyConnectedComponent*>* otherList = other->getComponents();
	boost::dynamic_bitset<> visited(this->getComponents()->size());
	bool found = false;

	for (size_t i = 0; i < this->components->size(); i++) {
		found = false;

		// Exploit the fact that often equal components are on the same position in the array
		if (!visited[i] && this->components->at(i)->equals(otherList->at(i))) {
			found = true;
			visited[i] = true;
		}

		else {
			for (size_t k = 0; k < otherList->size(); k++) {
				if (!visited[k] && this->components->at(i)->equals(otherList->at(k))) {
					found = true;
					visited[k] = true;
					break;
				}
			}
		}

		if (!found) {
			return false;
		}
	}

	return true;
}

string SCCList::toString() {
	stringstream s;
	
	for (auto it = this->components->begin(); it != this->components->end(); ++it) {
		s << (*it)->toString() << endl;
	}

	return s.str();
}
