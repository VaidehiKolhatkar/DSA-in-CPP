//buy and sell stocks (arrays)
#include<iostream>
using namespace std;
int main()
{
	int n = 6;
	int prices[n] = {7,1,5,3,6,4};
	
	int best_buy[n];
	best_buy[0] = INT_MAX;
	
	for(int i=1; i<n; i++)
	{
		best_buy[i] = min(best_buy[i-1], prices[i-1]);
	}
	
	int profit[n];
	profit[0] = 0;
	
	for(int i=1; i<n; i++)
	{
		profit[i] = prices[i] - best_buy[i];
	}
	
	cout<<"profit array: ";
	for(int i=0; i<n; i++)
	{
		cout<<profit[i]<<" ";
	}
	cout<<endl;
	
	int max = profit[0];
	for(int i=0; i<n; i++)
	{
		if(profit[i] > max)
		{
			max = profit[i];
		}
	}
	
	cout<<"maximum profit is "<<max;
}
