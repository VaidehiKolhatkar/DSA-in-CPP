//first occurence (in array) using recurssion
#include<iostream>
using namespace std;

int first_occ(int arr[], int n, int i, int ele)
{
	if(i == n)
		return -1;
		
	if(arr[i] == ele)
		return i;
		
	return first_occ(arr, n, i+1, ele);
}

int main()
{
	int array[6] = {1,2,2,2,3,4};
	int n = 6;
	
	cout<<first_occ(array, n, 0, 3);
	
	return 0;
}
