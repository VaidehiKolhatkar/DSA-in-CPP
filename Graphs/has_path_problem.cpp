//has path problem - tell if any path exists between source and destination
//solving using dfs 
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
			list<int> neighbors = l[u];
			cout<<u<<" : ";
			
			for(int v : neighbors)
				cout<<v<<" ";
		}
	}
	
	void DFS(int u, vector<bool> &visited)
	{
		visited[u] = true;
		cout<<u<<" ";
		
		list<int> neighbors = l[u];
		
		for(int v : neighbors)
		{
			if(!visited[v])
			{
				DFS(v, visited);	
			}
		}
	}
	
	bool has_path(int src, int dest, vector<bool> &visited)
	{
		if(src == dest)
		{
			return true;
		}
		
		visited[src] = true;
		
		list<int> neighbors = l[src];
		
		for(int v : neighbors)
		{
			if(!visited[v])
			{
				if( has_path(v, dest, visited) )
				{
					return true;	
				}	
			}
		}
		
		return false;
	}
};

int main()
{
	Graph g(7);
	
	g.add_edge(0,1);
	g.add_edge(0,2);
	g.add_edge(1,3);
	g.add_edge(2,4);
	g.add_edge(3,4);
	g.add_edge(3,5);
	g.add_edge(4,5);
	g.add_edge(5,6);
	
	vector<bool> vec (7, false);
	
	g.DFS(0, vec);
	
	cout<<endl;
	
	vector<bool> vec1 (7, false);
	
	bool x = g.has_path(0,5,vec1);
	cout<<x;
	
	return 0;
}
