//Dijkstra's Algorithm 
//step 1: create edge list. vector of vector . store (neighbor edge, its weight) for every node
//Edge relaxation: dist[v] > dist[u] + dist(u,v) , dist[v] = dist[u] + dist(u,v)
//Priority queue: will store pair(u, dist[u]). PQ will sort based on min dist value, so min heap  
#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Edge{
	public:
		int v;        //neighbor
		int wt;
		
	Edge(int v, int wt)
	{
		this->v = v;
		this->wt = wt;
	}
};

void dijkstras(int src, vector<vector<Edge>> graph, int v)
{
	//create pq, with pairs(dist, v) , min heap
	//priority_queue<pair<int, int>> pq;  - convert this to min heap
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;        //min heap
	
	//create vector with all dist infinity except src->src which will be 0
	vector<int> dist(v, INT_MAX);
	
	pq.push(make_pair(0,src));         //pq
	dist[src] = 0;                     //vector
	
	while(pq.size() > 0)
	{
		int u = pq.top().second;
		pq.pop();
		
		//get all the neighbor and dist of 'u' from the graph
		vector<Edge> edges = graph[u];
		
		for(Edge e : edges)                //e.v and e.wt
		{
			if(dist[e.v] > dist[u] + e.wt)
			{
				dist[e.v] = dist[u] + e.wt;
				pq.push(make_pair(dist[e.v], e.v));
			}
		}
	}
	
	for(int d : dist)
	{
		cout<<d<<" ";
	}
}

int main()
{
	int v = 6;
	vector<vector<Edge>> graph(v);
	
	graph[0].push_back(Edge(1,2));
	graph[0].push_back(Edge(2,4));
	
	graph[1].push_back(Edge(3,7));
	graph[1].push_back(Edge(2,1));
	
	graph[2].push_back(Edge(4,3));
	
	graph[3].push_back(Edge(5,1));
	
	graph[4].push_back(Edge(3,2));
	graph[4].push_back(Edge(5,5));
	
	dijkstras(0, graph, v);
	
	return 0;
}
