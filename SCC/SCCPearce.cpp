#include "SCCPearce.h"

SCCPearce::SCCPearce() :SCCStrategy("Pearce") { }

SCCList SCCPearce::getSCC(Graph* g) {
	if (g->getSize() <= 0) {
		return SCCList();
	}

	return SCCList();
}