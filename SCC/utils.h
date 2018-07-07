#include <vector>
#include <set>
#include "Graph.h"
#include "SCCList.h"

using namespace std;

/*
	Returns a random number between 0 and (limit - 1)
*/
int random(int limit);

/*
	Round a number up to the given number of decimal places
*/
double round(double n, int precision);

/*	
	Generates a random graph with the given size
*/
Graph* generateGraph(int size);

/*
	Generates a random graph with the given size and density (edges per vertex)
*/
Graph* generateGraph(int size, double density);

/*
	Takes as input the result of the boost's function for calculating SCCs and converts it into a istance of SCCList
*/
SCCList* convert(vector<int> v, int nComponents);