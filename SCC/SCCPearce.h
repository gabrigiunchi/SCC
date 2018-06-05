#pragma once
#include "SCCStrategy.h"
class SCCPearce : public SCCStrategy {
public:
	SCCPearce();
	SCCList getSCC(Graph* g);
};

