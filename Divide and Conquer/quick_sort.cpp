//Quick Sort - divide and conquer
#include<iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
	int i = s-1;
	int pivot = arr[e];
	int j = s;
	
	for(j=s; j<e; j++)
	{
		if(arr[j] <= pivot)
		{
			i++; 
			swap(arr[i], arr[j]);
		}
	}
	
	//to place pivot element at its correct position
	i++;
	swap(arr[i], arr[e]);
	
	return i;                           //return pivot index position
}

void quick_sort(int arr[], int s, int e)
{
	//base case
	if(s >= e)
	{
		return;
	}
	
	int pivot_idx = partition(arr, s, e);
	
	quick_sort(arr, s, pivot_idx-1);
	quick_sort(arr, pivot_idx + 1, e);
}



void print(int arr[])
{
	for(int a=0; a<7; a++)
	{
		cout<<arr[a]<<" ";
	}
}


int main()
{
	int array[7] = {5,1,6,2,7,4,3};
	
	quick_sort(array,0,6);
	
	print(array);
	
	return 0;
}
