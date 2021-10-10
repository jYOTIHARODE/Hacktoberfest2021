// Bipartite Graph
// there is no edge between two vetex in same set
// one vertex of one set can map to any no. of vertex in another set, and vice versa also true
// Time Complexity = O(V+E)
#include<bits/stdc++.h>
using namespace std;

// 2 coloring method - BFS
bool is_bipartite(vector< vector<int> > &graph, int src, int n)
{
	vector<int > color(n, -1);// -1 means not colored
	color[src]=0;
	queue<int > q;
	q.push(src);
	
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		
		for(int i=0;i<graph[x].size();i++)
		{
			if(x==graph[x][i])// is self loop, then not bipartite
			return false;
			if(color[graph[x][i]]==-1)// if not colored already, color it with 2nd color and push to queue
			{
				color[graph[x][i]] = 1 - color[x];
				q.push(graph[x][i]);
			}
			else if(color[x]==color[graph[x][i]])
			return false;
		}
	}
	return true;
}

int main() 
{
	int n = 6;
	vector<vector<int > > graph(n);// undirected graph
	
	// graph with even cycle length (6), thus Bipartite
	graph[0].push_back(1);
	graph[1].push_back(0);
	graph[1].push_back(2);
	graph[2].push_back(1);
	graph[2].push_back(3);
	graph[3].push_back(2);
	graph[3].push_back(4);
	graph[4].push_back(3);
	graph[4].push_back(5);
	graph[5].push_back(4);
	graph[5].push_back(0);
	graph[0].push_back(5);
	
	
	// 2 coloring method  - BFS method
	// if the graph is colored in two color(0, 1) with no two adjacent vertex with same color, then Bipartite else not
	// for disconnected graph, just to DFS accordingly till all vertex get colored, and all the diconnected component must be bipartite
	if(is_bipartite(graph1, 0, n))
	cout<<"Bipartite\n";
	else
	cout<<"Not Bipartite\n";
		
	return 0;
}
