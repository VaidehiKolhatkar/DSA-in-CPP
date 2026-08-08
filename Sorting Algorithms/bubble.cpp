//bubble sort - compare adjacent values and swap 
#include<iostream>
using namespace std;

void print(int arr[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
}

void bubble_sort(int arr[], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j+1]);
			}
		}
	}
	
	print(arr,n);
}

int main()
{
	int array[] = {5,2,3,1,4};
	int n = 5;
	
	bubble_sort(array,n);
	
	return 0;
}
