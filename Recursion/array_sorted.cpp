//check if array is sorted by recursion (ascending)
#include<iostream>
using namespace std;

bool is_sorted(int arr[], int n, int i)
{
	if(i == n-1)
		return true;
	
	if(arr[i] > arr[i+1])
		return false;
		
	return is_sorted(arr, n, i+1);
}

int main()
{
	int array[5] = {1,2,3,5,4};
	int n = 5;
	
	cout<<is_sorted(array,n,0);
	
	return 0;
}
