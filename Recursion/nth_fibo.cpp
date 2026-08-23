//print nth fibonacci number. if n=5, ans=3
#include<iostream>
using namespace std;

int Fibo(int n)
{
	if(n==0)
		return 0;
	
	if(n==1)
		return 1;
	
	return ( Fibo(n-1) + Fibo(n-2) );
}

int main()
{
	cout<<Fibo(9);
	
	return 0;
}
