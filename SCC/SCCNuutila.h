#pragma once
#include "SCCStrategy.h"

class SCCNuutila : public SCCStrategy {
public:
	SCCNuutila();
	SCCList getSCC(Graph* g);
};

