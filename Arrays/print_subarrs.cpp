//printing subarrays - subarrays are continuous parts - subsequesce is in order but not necessarily continuous 
#include<iostream>
using namespace std;

void print_subarrays(int *arr, int n)
{
	for(int start=0; start<n; start++)
	{
		for(int end=start; end<n; end++)
		{
			for(int i=start; i<=end; i++)
			{
				cout<<arr[i];
			}
			cout<<",";
		}
		cout<<endl;
	}
}

int main()
{
	int array[] = {1,2,3,4,5};
	
	int n = sizeof(array) / sizeof(int);
	
	print_subarrays(array,n);
}

