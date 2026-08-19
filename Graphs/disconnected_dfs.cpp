//disconnected dfs
#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
	int v;
	list<int>* l;
	
	public:
		Graph(int v)
		{
			this->v = v;
			l = new list<int> [v];
		}
		
	void add_edge(int u, int v)
	{
		l[u].push_back(v);
		l[v].push_back(u);
	}
	
	void print()
	{
		for(int u=0; u<v; u++)
		{
			list<int> n = l[u];
			cout<<u<<" : ";
			
			for(int v : n)
				cout<<v<<" ";
		}
	}
	
	void DFS(int u, vector<bool> &visited)
	{
		visited[u] = true;
		cout<<u<<" ";
		
		list<int> n = l[u];
		
		for(int v : n)
		{
			if(!visited[v])
			{
				DFS(v, visited);
			}
		}
		
		for(int i=0; i<v; i++)
		{
			if(!visited[i])
			{
				DFS(i, visited);
			}
		}
	}
	
	void DFS_disc()
	{
		vector<bool> visited(v, false);
		
		for(int i=0; i<v; i++)
		{
			if(!visited[i])
			{
				DFS(i, visited);
			}
		}
	}
};

int main()
{
	Graph g(10);
	
	g.add_edge(1,6);
	g.add_edge(6,4);
	g.add_edge(4,9);
	g.add_edge(4,3);
	g.add_edge(3,8);
	g.add_edge(3,7);
	g.add_edge(0,2);
	g.add_edge(2,5);
	
	vector<bool> vec (7, false);
	
	g.DFS_disc();
	
	return 0;
}
