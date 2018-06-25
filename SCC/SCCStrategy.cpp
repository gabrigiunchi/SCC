#include "SCCStrategy.h"

SCCStrategy::SCCStrategy(string algorithm) {
	this->algorithm = algorithm;
}

string SCCStrategy::toString() {
	return this->algorithm;
}