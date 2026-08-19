//directed unweighted - adjacency list
#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
	int v;          //no. of vertices
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
	g.add_edge(0,2);
	g.add_edge(2,3);
	
	g.print();
	
	return 0;
}
