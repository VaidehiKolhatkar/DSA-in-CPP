//update ith bit according to given value
#include<iostream>
using namespace std;

int update_bit(int n, int i, int v)
{
	//clear ith bit
	int bitmask = ~(1 << i);
	
	n = n & bitmask;
	
	return (n | (v<<i));
}

int main()
{
	int num, i, val;
	
	cout<<"Enter the number"<<endl;
	cin>>num;
	
	cout<<"Enter the position"<<endl;
	cin>>i;
	
	cout<<"Enter the value"<<endl;
	cin>>val;
	
	int result = update_bit(num, i, val);
	
	cout<<"answer = "<<result;
}
