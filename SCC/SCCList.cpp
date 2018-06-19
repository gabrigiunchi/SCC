#include "SCCList.h"
#include <sstream>

vector<StronglyConnectedComponent> SCCList::getComponents() {
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

	vector<StronglyConnectedComponent> otherList = other.getComponents();
	bool found = false;
	for (int i = 0; i < this->components.size(); i++) {
		found = false;

		for (int k = 0; k < otherList.size(); k++) {
			if (this->components[i].equals(otherList[k])) {
				found = true;
				break;
			}
		}

		if (!found) {
			return false;
		}
	}

	return true;
	//return this->components.size() == other.getComponents().size();
}

string SCCList::toString() {
	stringstream s;
	
	for (auto it = this->components.begin(); it != this->components.end(); ++it) {
		s << it->toString() << endl;
	}

	return s.str();
}
