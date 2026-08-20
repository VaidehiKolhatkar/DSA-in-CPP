//cycle detection - undirected 
//main condition - if neigh is visited but its not u's parent(cuz parent will be obv visited cuz we reached u thr. its par)
//so main condition is if(neighbor!=par)
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

	//cycle detection dfs
	bool cycle(int u, vector<bool> &visited, int par)
	{
		visited[u] = true;
		//cout<<u<<" ";
		
		list<int> neighbors = l[u];
		
		for(int v : neighbors)
		{
			if(!visited[v])
			{
				if( cycle(v, visited, u) )            //if neighbor finds a cycle
					return true;
			}
			else if(v != par)                         //neighbor is parent
				return true;                          //cycle exists
		}		
			return false;                             //no cycle
	}
};

int main()
{
	Graph g(5);
	
	g.add_edge(0,1);
	g.add_edge(0,2);
	g.add_edge(0,3);
	g.add_edge(1,2);
	g.add_edge(3,4);
	
	vector<bool> vec (5, false);
	
	cout<<g.cycle(0,vec,-1);
	
	return 0;
}
