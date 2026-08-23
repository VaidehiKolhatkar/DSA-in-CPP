//print x to the power n (with O(n) time complexity)
#include<iostream>
using namespace std;

int pow(int x, int n)
{
	if(n == 1)
		return x;
		
	return x * pow(x, n-1);
}

int main()
{
	cout<<pow(2,10);
	
	return 0;
}
