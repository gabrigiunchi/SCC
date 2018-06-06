#include "SCCList.h"
#include <sstream>

list<StronglyConnectedComponent> SCCList::getComponents() {
	return this->components;
}

void SCCList::addComponent(StronglyConnectedComponent component) {
	this->components.push_back(component);
}

bool SCCList::equals(SCCList other) {
	if (this->components.size() == 0 && other.getComponents().size() == 0) {
		return true;
	}

	if (this->components.size() != other.getComponents().size()) {
		return false;
	}

	list<StronglyConnectedComponent> otherList = other.getComponents();
	for (auto it1 = this->components.begin(); it1 != this->components.end(); ++it1) {
		bool found = false;

		for (auto it2 = otherList.begin(); it2 != otherList.end(); ++it2) {
			if (it1->equals(*it2)) {
				found = true;
				break;
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
		s << it->toString() << endl;
	}

	return s.str();
}
