//Bipaetite Graph - using bfs
//assign 2 colors to 2 sets
//neighbor will always be given diff color from u
//if neighbor is visited and has same color as u, then its not bipartite
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
		l[u].push_back(v);
		l[v].push_back(u);               
	}
	
	void print()
	{
		for(int u=0; u<v; u++)              //u is curr node
		{
			list<int> neighbors = l[u];
			cout<<u<<" : ";
			
			for(int v : neighbors)
				cout<<v<<" ";
				
			cout<<endl;
		}
	}
	
	bool bipartite()
	{
		queue<int> q;
		vector<bool> visited(v,false);
		vector<int> color(v,-1); 
		
		q.push(0);
		visited[0] = true;
		color[0] = 0;
		
		while(q.size() > 0)
		{
			int u = q.front();         //current node
			q.pop();
			//cout<<u<<" ";
			
			//add u's neighbors into queue
			list<int> neighbors = l[u];
			for(int v : neighbors)
			{
				if(!visited[v])
				{
					visited[v] = true;
					q.push(v);
					color[v] = !color[u];
				}
				else if(color[v] == color[u])
				{
					return false;                    //its NOT bipartite
				}
			}                        
		}
		
					return true;                            //its bipartite  
		
		cout<<endl;
	}
};

int main()
{
	Graph g(5);
	
	//bipartite
//	g.add_edge(0,1);
//	g.add_edge(1,2);
//	g.add_edge(2,3);
//	g.add_edge(3,0);
	
	//not a bipartite
	g.add_edge(0,1);
	g.add_edge(0,2);
	g.add_edge(1,3);
	g.add_edge(2,4);
	g.add_edge(3,4);

	
	cout<<g.bipartite();
	
	return 0;
}
