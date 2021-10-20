// C++ program to clon a directed acyclic graph.
#include <bits/stdc++.h>
using namespace std;

// Class to create a new graph node
class Node
{
	public:
		int key;
		vector<Node *> adj;
		
		// key is the value of the node
		// adj will be holding a dynamic
		// list of all Node type neighboring
		// nodes
		Node(int key)
		{
			this->key = key;
		}
};

// Function to print a graph,
// depth-wise, recursively
void printGraph(Node *startNode,
				vector<bool> &visited)
{
	
	// Visit only those nodes who have any
	// neighboring nodes to be traversed
	if (!startNode->adj.empty())
	{
		
		// Loop through the neighboring nodes
		// of this node. If source node not already
		// visited, print edge from source to
		// neighboring nodes. After visiting all
		// neighbors of source node, mark its visited
		// flag to true
		for(auto i : startNode->adj)
		{
			if (!visited[startNode->key])
			{
				cout << "edge " << startNode
					<< "-" << i
					<< ":" << startNode->key
					<< "-" << i->key
					<< endl;
				if (!visited[i->key])
				{
					printGraph(i, visited);
					visited[i->key] = true;
				}
			}
		}
	}
}

// Function to clone a graph. To do this, we
// start reading the original graph depth-wise,
// recursively. If we encounter an unvisited
// node in original graph, we initialize a
// new instance of Node for cloned graph with
// key of original node
Node *cloneGraph(Node *oldSource,
				Node *newSource,
				vector<bool> &visited)
{
	Node *clone = NULL;
	
	if (!visited[oldSource->key] &&
		!oldSource->adj.empty())
	{
		for(auto old : oldSource->adj)
		{
			
			// Below check is for backtracking, so new
			// nodes don't get initialized everytime
			if (clone == NULL ||
			(clone != NULL &&
			clone->key != old->key))
				clone = new Node(old->key);
				
			newSource->adj.push_back(clone);
			cloneGraph(old, clone, visited);
			
			// Once, all neighbors for that particular node
			// are created in cloned graph, code backtracks
			// and exits from that node, mark the node as
			// visited in original graph, and traverse the
			// next unvisited
			visited[old->key] = true;
		}
	}
	return newSource;
}

// Driver Code
int main()
{
	Node *n0 = new Node(0);
	Node *n1 = new Node(1);
	Node *n2 = new Node(2);
	Node *n3 = new Node(3);
	Node *n4 = new Node(4);
	
	n0->adj.push_back(n1);
	n0->adj.push_back(n2);
	n1->adj.push_back(n2);
	n1->adj.push_back(n3);
	n1->adj.push_back(n4);
	n2->adj.push_back(n3);
	n3->adj.push_back(n4);
	
	// Flag to check if a node is already visited.
	// Stops indefinite looping during recursion
	vector<bool> visited(5, false);
	cout << "Graph Before Cloning:-\n";
	printGraph(n0, visited);
	visited = { false, false, false, false, false };
	
	cout << "\nGraph Before Starts:-\n";
	Node *clonedGraphHead = cloneGraph(
		n0, new Node(n0->key), visited);
	cout << "Cloning Process Completes.\n";
	
	visited = { false, false, false, false, false };
	cout << "\nGraph After Cloning:-\n";
	printGraph(clonedGraphHead, visited);
	
	return 0;
}

// This code is contributed by sanjeev2552
