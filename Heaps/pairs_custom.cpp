//pairs with custom comparator
//pairs - default is max heap with pair.first as sorting parameter
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

struct compare_pair
{
	bool operator ()(pair<string, int> &p1, pair<string, int> &p2)
	{
		return p1.second < p2.second;
	}
};

int main()
{
	priority_queue<pair<string, int>, vector<pair<string, int>>, compare_pair> pq;
	
	pq.push(make_pair("A",80));
	pq.push(make_pair("C",77));
	pq.push(make_pair("B",98));
	
	cout<<pq.top().first<<endl;           //B is printed as B ka rank is highest
	
	return 0;
}
