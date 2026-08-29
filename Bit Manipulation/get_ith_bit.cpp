//get ith bit - (bit numbers start from 0)
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
	
	if((num & bitmask) != 0)
		cout<<i<<"th bit is 1"<<endl;
	else
	    cout<<i<<"th bit is 0"<<endl;
}
