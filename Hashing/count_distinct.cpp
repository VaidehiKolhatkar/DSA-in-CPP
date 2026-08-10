//count distinct - since set stores only unique values, use sets directly
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int count_distinct(vector<int> nums)
{
	unordered_set<int> set;
	
	for(int i=0; i<nums.size(); i++)
	{
		set.insert(nums[i]);
	}
	
	return set.size();
}

int main()
{
	vector<int> nums = {4,2,3,7,6,1,2,7,2,6,5};     //7
	
	cout<<count_distinct(nums);
	
	return 0; 	
}
