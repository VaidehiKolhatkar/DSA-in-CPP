//tiling problem (by recursion) 
//we have 2X1 tiles. Find how many ways are there to fill the 2Xn box with tiles. 
#include<iostream>
using namespace std;

int tiling_prob(int n)
{
	if(n==0 || n==1)
		return 1;
	
	return (tiling_prob(n-1) + tiling_prob(n-2));
}

int main()
{	
	cout<<tiling_prob(4);
	
	return 0;
}
