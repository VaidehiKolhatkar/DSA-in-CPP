//climbing stairs - count ways to reach the nth stair : person can jump 1 or 2 strs
//memoisation
#include<iostream>
#include<vector>
using namespace std;

int climb_str(int n,vector<int> vec)
{
	if(n==0 || n==1)
	{
		return 1;
	}
	
	if(vec[n] != -1)
	{
		return vec[n];
	}
	
	vec[n] = climb_str(n-1,vec) + climb_str(n-2,vec);
	
	return vec[n];
}

int main()
{
	int n = 5;
	
	vector<int> vec (n+1, -1);    
	
	cout<<climb_str(n,vec);
	
	return 0;
}
