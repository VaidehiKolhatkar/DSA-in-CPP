//last occurence (in array) using recurssion
#include<iostream>
using namespace std;

int last_occ(int arr[], int n, int i, int ele)
{	
	if(i == -1)
		return -1;
	
	if(arr[i] == ele)
		return i;
		
	return last_occ(arr, n, i-1, ele);
}

int main()
{
	int array[6] = {1,2,3,3,3,4};
	int n = 6;
	
	cout<<last_occ(array, n, n-1, 3);
	
	return 0;
}
