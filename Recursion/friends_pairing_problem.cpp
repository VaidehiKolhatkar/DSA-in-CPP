//Friends Pairing Problem
//Find total ways in which n friends can be paired up. Each friend can only be paired once.

#include<iostream>
using namespace std;

int friends_pair(int n)
{
	if(n==1 || n==2)
		return n;
		
	return friends_pair(n-1) + friends_pair(n-2) * (n-1);
}

int main()
{
	cout<<"total ways : "<<friends_pair(4);
	
	return 0;
}
