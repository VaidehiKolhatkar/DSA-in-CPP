////array reverse without extra memory
#include<iostream>
using namespace std;
int main()
{
	int array[] = {4,9,1,3,2,0,6,4};
	
	int n = sizeof(array) / sizeof(int);
	
	cout<<"array is ";
	for(int i=0; i<n; i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;

	int *start = array;
	int *end = start + (n-1);
	
	while(start<end)
	{
		swap(*start,*end);
		
		start++;
		end--;
	}
	
	cout<<"reversed array is ";
	for(int i=0; i<n; i++)
	{
		cout<<array[i]<<" ";
	}
}
