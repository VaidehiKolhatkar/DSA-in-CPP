//heaps basics 
//Heap is Complete Binary Tress (CBT) 
//CBT is BT in which all levels are filled from left to right always
//heap is implemented using priority queue in cpp
#include<iostream>
#include<queue>
using namespace std;
int main()
{
	//priority_queue<int> pq;        //ascending
	priority_queue<int, vector<int>, greater<int>> pq;     //descending
	
	pq.push(7);
	pq.push(4);
	pq.push(10);
	pq.push(5);
	pq.push(9);
	
	while(!pq.empty())
	{
		cout<<"top : "<<pq.top()<<endl;
		pq.pop();
	}
	
	return 0;
}

