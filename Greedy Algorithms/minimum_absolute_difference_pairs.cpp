//Minimum Absolute Difference Pairs
//4187, 2365
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> v1 = {4,1,8,7};
	vector<int> v2 = {2,3,6,5};
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	int min_abs_dif = 0;
	
	for(int i=0; i<v1.size(); i++)
	{
		min_abs_dif += abs(v1[i] - v2[i]);
	}
	
	cout<<"the minimum absolute difference is "<<min_abs_dif;
	
	return 0;
}
