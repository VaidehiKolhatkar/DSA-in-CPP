//pairs - default is max heap with pair.first as sorting parameter
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int main()
{
	priority_queue<pair<string, int>> pq;
	
	pq.push(make_pair("A",80));
	pq.push(make_pair("C",77));
	pq.push(make_pair("B",98));
	
	cout<<pq.top().first<<endl;           //C is printed
	
	pq.pop();
	cout<<pq.top().second;         //C is popped. So, B's second = 98 is printed
	
	return 0;
}
