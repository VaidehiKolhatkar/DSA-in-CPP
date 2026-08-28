//0/1 Knapsack - Recursion
#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int cap, int n)
{
	//base case
	if(cap==0 || n==0)
	{
		return 0;
	}
	
	int item_wt = wt[n-1];
	int item_val = val[n-1];
	
	if(item_wt <= cap)                           //wt of an item is less than capacity of sack
	{
		//include
		int ans1 = knapsack(wt, val, cap - item_wt, n-1) + item_val;
		
		//exclude
		int ans2 = knapsack(wt, val, cap, n-1);
		
		return max(ans1, ans2);              //whichever gives max profit
	}
	else                                         ////wt of an item is greater than capacity of sack
	{
		//exclude
		return knapsack(wt, val, cap, n-1);
	}
}

int main()
{
	int cap = 7;
	int n = 5;
	
	vector<int> wt = {2,5,1,3,4};
	vector<int> val = {15,14,10,45,30};
	
	cout<<knapsack(wt, val, cap, n);
	
	return 0;
}
