//print x to the power n with O(log n) time complexity. 
// 2^10 = 2^5 * 2^5 ----- n is even
// 2^11 = 2 * 2^5 * 2^5 ----- n is odd
#include<iostream>
using namespace std;

int pow(int x, int n)
{
	if(n==1)
		return x;
	
	if(n%2 == 0)
		return pow(x, n/2) * pow(x, n/2);
	
	else
		return x * pow(x, n/2) * pow(x, n/2);	
	
}

int main()
{
	cout<<pow(2,10);
	
	return 0;
}
