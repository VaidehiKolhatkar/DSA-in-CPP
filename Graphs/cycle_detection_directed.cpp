//cycle detection - directed
//condition is - if u's neighbor exists in its path
//create another bool vector to store info if node is in recursive path
//IMPORTANT - visited vec and recr path vector are 2 different things
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
		l[u].push_back(v);	            //directed
	} 

	//cycle detection dfs
	bool cycle(int u, int par, vector<bool> &visited, vector<bool> &recr_path)
	{
		visited[u] = true;
		recr_path[u] = true;
		//cout<<u<<" ";
		
		list<int> neighbors = l[u];
		
		for(int v : neighbors)
		{
			if(!visited[v])
			{
				if( cycle(v, u, visited, recr_path) )             //if neighbor finds a cycle
					return true;
			}
			else if(recr_path[v] == true)                         //neighbor is in its recr path
				return true;                           			  //cycle exists
		}		
			recr_path[u] = false;
		
			return false;                             			  //no cycle
	}
};

int main()
{
	Graph g(5);
	
	g.add_edge(1,0);
	g.add_edge(0,2);
	g.add_edge(2,3);
	g.add_edge(3,0);
	
	vector<bool> vec (5, false);
	vector<bool> recr_path (5, false);
	
	cout<<g.cycle(0,-1,vec,recr_path);
	
	return 0;
}
