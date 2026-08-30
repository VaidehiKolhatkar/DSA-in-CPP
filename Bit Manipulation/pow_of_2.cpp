//check for power of 2 - power of 2 numbers have only 1 set bit. Num-1 have all bits set. AND of num and num-1 is 0 if its pow of 2
#include<iostream>
using namespace std;

void pow_of_two(int n)
{
	if((n & (n-1)) == 0)
	{
		cout<<"power of 2";
	}
	else
	{
		cout<<"not a power of 2";
	}
}

int main()
{
	int num;
	
	cout<<"Enter a number"<<endl;
	cin>>num;
	
	pow_of_two(num);
}
