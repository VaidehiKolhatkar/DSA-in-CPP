//clear ith bit - AND with 0 on ith pos. other bitmask bits should be 1.
#include<iostream>
using namespace std;
int main()
{
	int num, i;
	
	cout<<"Enter a number"<<endl;
	cin>>num;
	
	cout<<"Enter position to clear bit"<<endl;
	cin>>i;
	
	int bitmask = ~(1 << i);
	
	cout<<(num & bitmask);	
} 
