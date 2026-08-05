//Max Subarray Sum - Brute Force 
#include<iostream>
using namespace std;
int max_subarr_sum(int *arr, int n)
{
	int max_sum = INT_MIN;
	
	for(int start=0; start<n; start++)
	{
		for(int end=start; end<n; end++)
		{
			int sum=0;
			
			for(int i=start; i<=end; i++)
			{
				sum = sum + arr[i];
			}
			max_sum = max(max_sum, sum);
		}
	}
	cout<<"the maximum subarray sum is "<<max_sum;
}

int main()
{
	int array[] = {-1,-2,-3,-4,-5};
	
	int n = sizeof(array) / sizeof(int);
	
	max_subarr_sum(array,n);
}

