//Kahn's Algorithm
//NOTE : A DAG has atleast 1 vertex with in-degree 0 and atleat 1 vertex with out-degree 0
//so starting vertex in a topological order would be the one with indegree 0

//1. Add node with indegree 0 in the queue
//2. Once you pop it from queue, for all its neighbors, indegree--
//3. Once indeg becomes 0 for any node, it goes in the queue and so on.
#include<iostream>
#include<vector>
#include<list>
#include<queue>
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
		l[u].push_back(v);	            //directed
	} 
	
	void indegree(vector<int> &vec)
	{
		for(int u=0; u<v; u++)
		{
			list<int> n = l[u];
			
			for(int v : n)
			{
				vec[v]++;
			}
		}
	}
	
	void kan()
	{
		vector<int> indeg (v,0);          //to store in-degrees
		indegree(indeg);
		
		queue<int> q;
		
		for(int i=0; i<v; i++)
		{
			if(indeg[i] == 0)            //nodes with in-deg 0 added to queue
			{
				q.push(i);
			}
		}
		
		while(q.size() > 0)
		{
			int u = q.front();
			q.pop();
			cout<<u<<" ";
			
			list<int> n = l[u];
			
			for(int v : n)
			{
				indeg[v]--;
				
				if(indeg[v] == 0)
					q.push(v);
			}
		}
	}
};

int main()
{
	Graph g(6);
	
	g.add_edge(2,3);
	g.add_edge(3,1);
	g.add_edge(4,0);
	g.add_edge(4,1);
	g.add_edge(5,2);
	g.add_edge(5,0);
	
	g.kan();
	
	return 0;
}

