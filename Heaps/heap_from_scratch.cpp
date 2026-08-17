//heap from scratch
//for parent index i, left child = 2*i+1 , right child = 2*i+2
//for child index i, parent is (i-1)/2
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void heapify(int i, vector<int> vec)   // i is parent index
{
	if(i >= vec.size())    //empty heap
	{
		return;
	}
	
	int l = 2*i + 1;
	int r = 2*i + 2;
	
	int maxI = i;
	
	if(l < vec.size() && vec[l] > maxI)      //if l is valid or exists && its greater than max index
	{
		maxI = l;
	}
	
	if(r < vec.size() && vec[r] > maxI)
	{
		maxI = r;
	}
	
	swap(vec[i],vec[maxI]);
	
	if(maxI != i)     //swapping with some child (actual swap correctly), then call heapify for that child also 
	{
		heapify(maxI,vec);
	}
}

class Heap
{
	vector<int> heap;
	
	public:
		void push(int val)
		{
			//insert the value
			heap.push_back(val);
			
			//fix the heap
			int child_idx =  heap.size() - 1;
			int par_idx = (child_idx - 1) /2;
			
			while(par_idx >= 0 && heap[par_idx] < heap[child_idx])
			{
				swap(heap[par_idx], heap[child_idx]);
				
				child_idx = par_idx;
				par_idx = (child_idx - 1) /2;
			}	
		}
		
		void pop()
		{
			//swap 1st and last val
			swap(heap[0],heap[heap.size()-1]);
			
			//delete last index value
		    heap.pop_back();
		    
		    //fix the heap with heapify
		    //call the heapify for the root
		    heapify(0, heap);
		}
		
		int top()
		{
			return heap[0];	
		}	
		
		bool empty()
		{
			return heap.size() == 0;
		}
};

int main()
{
	Heap heap;
	
	heap.push(40);
	heap.push(50);
	heap.push(100);
	
	cout<<"top is "<<heap.top()<<endl;
	
	heap.pop();
	
	cout<<"top is "<<heap.top();
	
	return 0;
}
