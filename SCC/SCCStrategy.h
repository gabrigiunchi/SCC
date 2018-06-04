#include <vector>
#include <set>
#include "Graph.h"
#include <stack>
#include "SCCList.h"

/*
*	Finds the strongly connected components of the graph using the Tarjan algorithm.
*	Returns a matrix whose rows are the components and the columns are the nodes in a specific component
*/
SCCList SCCTarjan(Graph* g);
void SCCTarjanUtil(Graph* g, int parent, int disc[], int low[], stack<int> *stack, 
	boost::dynamic_bitset<>* stackMember, SCCList* strongComponents);


/*
*	Finds the strongly connected components of the graph using the boost library's algorithm.
*/
vector<int> SCCBoost(Graph* g, int* nComponents);