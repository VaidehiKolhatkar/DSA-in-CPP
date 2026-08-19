//undirected weighted - adjacency list
//list of pairs (neighnor, weight_value)
#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
	int v;                 //no. of vertices
	list<pair<int,int>>* l;          //list of int, but it points to first idx so a pointer
	
	public:
		Graph(int v)
		{
			this->v = v;
			l = new list<pair<int,int>> [v];
		}
		
	void add_edge(int u, int v)
	{
		l[u].push_back(v);
		l[v].push_back(u);               //cuz it is undirected
	}
	
	void print()
	{
		for(int u=0; u<v; u++)
		{
			list<int> neighbors = l[u];
			cout<<u<<" : ";
			
			for(int v : neighbors)
				cout<<v<<" ";
				
			cout<<endl;
		}
	}
};

int main()
{
	Graph g(5);
	
	g.add_edge(0,1);
	g.add_edge(1,2);
	g.add_edge(1,3);
	g.add_edge(2,3);
	g.add_edge(2,4);
	
	g.print();
	
	return 0;
}
