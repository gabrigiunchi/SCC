#include <vector>
#include <set>
#include "Graph.h"

using namespace std;

bool equals(vector<set<int>>* v1, vector<set<int>>* v2);
bool equals(set<int>* s1, set<int>* s2);
bool contains(set<int> s, int element);

/*
*	Random number between 0 and (limit - 1)
*/
int random(int limit);

/*
*	Generate a random graph with the given size
*/
Graph* generateGraph(int size);

void toString(vector<set<int>>* v);