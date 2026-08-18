//connect n ropes with minimum cost - when u connect 2 ropes, the cost will be sum of those. 
//we always select 2 min val ropes and join. 
//{4,3,2,6} - 2+3=5 c=5 {4,5,6}. 5+(4+5)=14 c=14 {9,6}. 14+(9+6)=29. min_cost=29
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int connect_ropes(vector<int> vec)
{
	//build pq
	priority_queue<int, vector<int>, greater<int>> pq(vec.begin(), vec.end());
	
	int cost = 0;
	
	while(pq.size() > 1)
	{
		int min1 = pq.top();
		pq.pop();
		
		int min2 = pq.top();
		pq.pop();
		
		cost += min1 + min2;
		
		pq.push(min1+min2);
	}
	
	return cost;
}

int main()
{
	vector<int> vec = {4,3,2,6};
	
	cout<<"min cost is "<<connect_ropes(vec);
	
	return 0;
}
