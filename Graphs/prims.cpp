//Prim's Algorithm - to find MST (minimum spanning tree)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Edge{
	public:
		int v;
		int wt;
		
		Edge(int v, int wt)
		{
			this->v = v;
			this->wt = wt;
		}
};

void prims(int src, vector<vector<Edge>> graph, int V)
{
	vector<bool> mst_set(V,0);
	int cost = 0;
	
	//priority_queue<pair<int,int>> pq;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	
	//mst_set[src] = 1;
	pq.push(make_pair(0,src));
	
	while(pq.size() > 0)
	{
		int u = pq.top().second;
		int wt = pq.top().first;
		
		pq.pop();
		
		if(!mst_set[u])
		{
			mst_set[u] = 1;
			cost += wt;
			
			vector<Edge> edges = graph[u];
			
			for(Edge e : edges)
			{
				pq.push(make_pair(e.wt,e.v));
			}
		}
	}
	
	cout<<"minimum spanning tree cost is "<<cost;
}

int main()
{
	int V = 4;
	vector<vector<Edge>> graph(V);
	
	graph[0].push_back(Edge(1,10));
	graph[0].push_back(Edge(2,15));
	graph[0].push_back(Edge(3,30));
	
	graph[1].push_back(Edge(0,10));
	graph[1].push_back(Edge(3,40));
	
	graph[2].push_back(Edge(0,15));
	graph[2].push_back(Edge(3,50));
	
	graph[3].push_back(Edge(0,30));
	graph[3].push_back(Edge(1,40));
	graph[3].push_back(Edge(2,50));
	
	prims(0, graph, V);
	
	return 0;
}
