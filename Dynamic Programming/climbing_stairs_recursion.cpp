//climbing stairs - count ways to reach the nth stair : person can jump 1 or 2 strs
//recursion
#include<iostream>
using namespace std;

int climb_str(int n)
{
	if(n==0 || n==1)
	{
		return 1;
	}
	
	return climb_str(n-1) + climb_str(n-2);
}

int main()
{
	int n = 5;
	
	cout<<climb_str(n);
	
	return 0;
}
