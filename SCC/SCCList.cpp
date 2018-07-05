#include "SCCList.h"
#include <sstream>
#include <boost/dynamic_bitset.hpp>

SCCList::~SCCList() {
	for (auto it = this->components.begin(); it != this->components.end(); ++it) {
		delete *it;
	}
}

SCCList::SCCList() { }

SCCList::SCCList(vector<StronglyConnectedComponent*> c) {
	this->components = c;
}

vector<StronglyConnectedComponent*> SCCList::getComponents() {
	return this->components;
}

void SCCList::addComponent(StronglyConnectedComponent* component) {
	this->components.push_back(component);
}

bool SCCList::equals(SCCList* other) {
	vector<StronglyConnectedComponent*> otherList = other->getComponents();
	
	if (this->components.size() != otherList.size()) {
		return false;
	}

	boost::dynamic_bitset<> visited(this->getComponents().size()); // stores the index of the elements already matched
	bool found = false;

	for (size_t i = 0; i < this->components.size(); i++) {
		found = false;

		// Exploit the fact that often equal components are on the same position in the array
		if (!visited[i] && this->components[i]->equals(otherList[i])) {
			found = true;
			visited[i] = true;
		}
		else {
			for (size_t k = 0; k < otherList.size(); k++) {
				if (!visited[k] && this->components[i]->equals(otherList[k])) {
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
	
	for (auto it = this->components.begin(); it != this->components.end(); ++it) {
		s << (*it)->toString() << endl;
	}

	return s.str();
}
