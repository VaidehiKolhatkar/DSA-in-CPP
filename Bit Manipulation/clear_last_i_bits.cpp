//clear last i bits of a number : ~0 is -1. -1 = 11111111. So, -1<<i is bitmask
#include<iostream>
using namespace std;

int clear_last_bits(int n, int i)
{
	int bitmask = ~0 << i;
	
	return (n & bitmask);
}

int main()
{
	int num, i;
	
	cout<<"Enter the number"<<endl;
	cin>>num;
	
	cout<<"Enter how many last positions"<<endl;
	cin>>i;	
	
	int answer = clear_last_bits(num,i);
	
	cout<<"answer = "<<answer;
} 
