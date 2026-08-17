//Heap Sort 
//call heapify for all the nodes except leaf nodes. 0 to n/2-1 covers all nodes we want (run a reverse loop)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void heapify(int i, vector<int> &vec, int n)
{
	int maxI = i;
	
	int l = 2*i + 1;
	int r = 2*i + 2;
	
	if(l < n && vec[l] > vec[i])
	{
		maxI = l;
	}
	if(r < n && vec[r] > vec[i])
	{
		maxI = r;
	}
	
	if(maxI != i)
	{
		swap(vec[i], vec[maxI]);
		heapify(maxI, vec, n);
	}
	
	
}

void heap_sort(vector<int> &vec)
{
	//step 1 : build maxHeap
	int n = vec.size();
	
	//call heapify
	for(int i=n/2-1; i>=0; i--)
	{
		heapify(i,vec,n);
	}
	
	//step 2 : sort 
	
	for(int i=n-1; i>=0; i--)
	{
		swap(vec[i],vec[0]);                   //largest ele is at root in maxH so place it at the end ciz its ascending
		heapify(0,vec,i);
	}
}

int main()
{
	vector<int> vec = {5,4,1,3,2};
	
	heap_sort(vec);
	
	for(int i=0; i<vec.size(); i++)
	{
		cout<<vec[i]<<" ";
	}
	
	cout<<endl;
	
	return 0;
}
