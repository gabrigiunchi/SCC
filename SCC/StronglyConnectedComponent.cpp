#include "StronglyConnectedComponent.h"
#include <sstream>

StronglyConnectedComponent::~StronglyConnectedComponent() { }

StronglyConnectedComponent::StronglyConnectedComponent() { }

void StronglyConnectedComponent::addNode(int node) {
	this->nodes.insert(node);
}

set<int> StronglyConnectedComponent::getNodes() {
	return this->nodes;
}

bool StronglyConnectedComponent::equals(StronglyConnectedComponent* other) {
	return this->nodes == other->getNodes();
}

string StronglyConnectedComponent::toString() {
	stringstream s;
	
	s << "[";
	int i = 1;
	for (auto it = this->nodes.begin(); it != this->nodes.end(); ++it) {
		s << *it;
		if (i != this->nodes.size()) {
			s << ", ";
		}
		i++;
	}
	s << "]";

	return s.str();
}

int StronglyConnectedComponent::size() {
	return this->nodes.size();
}