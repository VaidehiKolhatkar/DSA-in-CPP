//count set bits : similar to sum of digits. In binary, sum of digits is the total set bits
#include<iostream>
using namespace std;
int main()
{
	int num;
	
	cout<<"Enter a number"<<endl;
	cin>>num;
	
	int count=0;
	
	while(num>0)
	{
		int last_digit = num&1;
		count+= last_digit;
		
		num = num>>1;
	}
	
	cout<<count<<endl;
}
