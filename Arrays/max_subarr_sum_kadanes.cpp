//Max Subarray Sum - Kadane's Algorithm
#include<iostream>
using namespace std;

int Kadanes(int *arr, int n)
{
	int max_sum = INT_MIN;
	
	int curr_sum = 0;
	
	for(int i=0; i<n; i++)
	{
		curr_sum += arr[i];
		
		max_sum = max(max_sum, curr_sum);
		
		if(max_sum < 0)
		{
			curr_sum = 0;	
		} 
	}
	
	cout<<"the maximum subarray sum is "<<max_sum;
}

int main()
{
	int array[] = {-5,-4,-3,-2,-1};
	
	int n = sizeof(array) / sizeof(int);
	
	Kadanes(array, n);
}
