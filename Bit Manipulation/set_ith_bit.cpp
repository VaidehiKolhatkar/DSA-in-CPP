//set ith bit - setting a bit means set it to 1 if 0, keep 1 if 1. 
#include<iostream>
using namespace std;
int main()
{
	int num, i;
	
	cout<<"Enter a number"<<endl;
	cin>>num;
	
	cout<<"Enter i position"<<endl;
	cin>>i;
	
	int bitmask = 1 << i;
	
	cout<<(num | bitmask);
}
