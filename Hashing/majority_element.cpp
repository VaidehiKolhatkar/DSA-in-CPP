//majority element using maps - print elements which appear more than n/3, n is the size of array/vec
#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

void maj_elt(vector<int> nums)
{
	unordered_map<int, int> map;
	
	for(int i=0; i<nums.size(); i++)
	{
		if(map.count(nums[i]))         //if ele already exists in map
		{
			map[nums[i]]++;
		}
		else
		{
			map[nums[i]] = 1;
		}
	}
	
	for(pair<int, int> p : map)
	{
		if(p.second > nums.size()/3)
		{
			cout<<p.first<<" ";
		}
	}
}

int main()
{
	vector<int> nums = {1,3,2,5,1,3,1,5,1};
	
	maj_elt(nums);
	
	return 0;
}
