//fibonacci series by dp approach 
#include<iostream>
#include<vector>
using namespace std;

int fibo(int n, vector<int> &vec)
{
	//base case
	if(n==0 || n==1)
	{
		return n;
	}
	
	if(vec[n] != -1)
	{
		return vec[n];
	}
	
	vec[n] = fibo(n-1,vec) + fibo(n-2,vec);
	
	return vec[n];
}

int main()
{
	int n = 6;
	
	vector<int> vec (n+1, -1);              //n+1 cuz 0 to n 
	
	cout<<fibo(n,vec);
	
	return 0;
}
