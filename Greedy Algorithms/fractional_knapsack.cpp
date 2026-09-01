//fractional knapsack
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<float, int> p1, pair<float, int> p2)
{
	return p1.first > p2.first;
}

int frac_knap(vector<int>val, vector<int>w, int cap)
{
	int profit = 0;
	
	vector<pair<float, int>> ratio(val.size(), make_pair(0.0, 0));
	
	for(int i=0;i<val.size(); i++)
	{
		int r = val[i]/w[i];
		
		ratio[i] = make_pair(r, i);
	}
	
	sort(ratio.begin(), ratio.end(), compare);      //[(6,0), (5,2), (4,1)]
	
	for(int i=0; i<ratio.size(); i++)
	{
		if(w[ratio[i].second] <= cap)
		{
			cap = cap - w[ratio[i].second];
			profit = profit + w[ratio[i].second]*ratio[i].first;
		}
		else
		{
			profit = profit + cap*ratio[i].first;
		}
	}
	
	//i=0, cap=40, profit=60
	//i=1, cap=20, profit=60+100=160
	//i=2,         profit=160+80=240
	
	return profit;
}

int main()
{
	vector<int> value = {60, 120, 100};
	vector<int> weight = {10, 30, 20};        
	int capacity = 50;
	
	cout<<"Total profit is "<<frac_knap(value, weight, capacity);
	
	return 0;
}
