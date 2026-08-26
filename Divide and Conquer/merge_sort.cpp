//Merge Sort - divide and conquer
#include<iostream>
#include<vector>
using namespace std;

void Merge(int arr[], int s, int mid, int e)
{
	int i = s;
	int j = mid+1;
	
	vector<int> temp;
	
	while(i<=mid && j<=e)
	{
		if(arr[i] <= arr[j])
		{
			temp.push_back(arr[i++]);    //i++ to add ith element and then increment it in same step
		}
		else
			temp.push_back(arr[j++]);    //j++ to add jth element and then increment it in same step
	}
	
	while(i<=mid)
		temp.push_back(arr[i++]);
		
	while(j<=e)
		temp.push_back(arr[j++]);
		
	
	
		
	//copy from vector to array
	for(int k=s, x=0; k<=e; k++)
	{
		arr[k] = temp[x++];
	}
}

void print(int arr[])
{
	for(int a=0; a<7; a++)
	{
		cout<<arr[a]<<" ";
	}
}

void merge_sort(int arr[], int s, int e)
{
	//base case
	if(s >= e)
		return;
	
	int mid = (s + e) /2;
	
	merge_sort(arr, s, mid);
	merge_sort(arr, mid+1, e);
	
	Merge(arr,s,mid,e);
}

int main()
{
	int array[7] = {5,1,6,2,7,4,3};
	
	merge_sort(array, 0, 6);
	print(array);
	
	return 0;	
}
