//climbing stairs - count ways to reach the nth stair : person can jump 1 or 2 strs
//tabulation
#include<iostream>
#include<vector>
using namespace std;

int climb_str(int n)
{
	vector<int> vec (n+1, -1);
	
	vec[0] = 1;
	vec[1] = 1;
	
	for(int i=2; i<=n; i++)
	{
		vec[i] = vec[i-1] + vec[i-2];
	}
	
	return vec[n];
}

int main()
{
	int n = 5;
	
	cout<<climb_str(n);
	
	return 0;
}
