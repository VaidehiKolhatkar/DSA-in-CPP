//selection sort - select smallest value and push it to the left
#include<iostream>
using namespace std;

void print(int arr[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
}

void selection_sort(int arr[], int n)
{	
	for(int i=0; i<n-1; i++)
	{
		int min = i;
		
		for(int j=i+1; j<n; j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;	
			}	
		}
		
		swap(arr[min], arr[i]);
	}
	
	print(arr,n);
}

int main()
{
	int array[] = {5,3,1,2,4};
	int n = 5;
	
	selection_sort(array,n);
	
	return 0;
}
