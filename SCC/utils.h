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
*	Generate a random graph with the given size
*/
Graph* generateGraph(int size);


SCCList convert(vector<int> v, int nComponents);