#include <vector>
#include <set>
#include "Graph.h"

/*
*	Finds the strongly connected components of the graph using the Tarjan algorithm.
*	Returns a matrix whose rows are the components and the columns are the nodes in a specific component
*/
vector<set<int>>* SCCTarjan(Graph* g);
void SCCTarjanUtil(Graph* g, int parent, int disc[], int low[], stack<int> *stack, 
	boost::dynamic_bitset<>* stackMember, vector<set<int>>* strongComponents);


/*
*	Execute the boost library's algorithm for finding strong connected components and return a
*	matrix which contains the components
*/
vector<set<int>>* SCCBoost(Graph* g);