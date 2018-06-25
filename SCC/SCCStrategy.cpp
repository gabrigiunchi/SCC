#include "SCCStrategy.h"

SCCStrategy::SCCStrategy(string algorithm) {
	this->algorithm = algorithm;
}

SCCStrategy::~SCCStrategy() { }

string SCCStrategy::toString() {
	return this->algorithm;
}