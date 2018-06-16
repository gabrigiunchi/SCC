#include <vector>
#include <set>
#include "Graph.h"
#include "SCCList.h"

using namespace std;

/*
*	Random number between 0 and (limit - 1)
*/
int random(int limit);

/*
*	Generates a random graph with the given size
*/
Graph* generateGraph(int size);

// Takes as input the result of the boost's function for calculating SCCs and converts it into a istance of SCCList
SCCList convert(vector<int> v, int nComponents);