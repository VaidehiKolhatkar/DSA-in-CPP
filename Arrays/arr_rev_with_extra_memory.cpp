//array reverse with extra memory
#include<iostream>
using namespace std;
int main()
{
	int array[5] = {2,4,1,3,9};
	
	cout<<"array elements are ";
	for(int i=0; i<5; i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	
	int copy[5];
	
	for(int i=0; i<5; i++)
	{
		int j = 5-i-1;
		
		copy[j] = array[i];
	}
	
	cout<<"reversed array is ";
	for(int i=0; i<5; i++)
	{
		cout<<copy[i]<<" ";
	}
}
