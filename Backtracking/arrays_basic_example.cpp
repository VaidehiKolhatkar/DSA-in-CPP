//backtracking on arrays - basic example of recursion
#include<iostream>
using namespace std;

void print(int arr[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
		cout<<endl;
}

void change_array(int arr[], int n, int i)
{
	if(i == n)
	{
		print(arr,n);
		return;
	}
	
	arr[i] = i+1;
	change_array(arr,n,i+1);
	
	arr[i] = arr[i] - 2;
}

int main()
{
	int array[5] = {0};
	int n = 5;
	
	change_array(array,n,0);
	
	print(array,n);
	
	return 0;
}
