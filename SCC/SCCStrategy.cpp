#include "SCCStrategy.h"
#include "SCCBoost.h"

SCCStrategy::SCCStrategy(string algorithm) {
	this->algorithm = algorithm;
}

SCCStrategy::~SCCStrategy() { }

string SCCStrategy::getName() {
	return this->algorithm;
}

SCCStrategy* getDefaultStrategy() {
	return new SCCBoost();
}