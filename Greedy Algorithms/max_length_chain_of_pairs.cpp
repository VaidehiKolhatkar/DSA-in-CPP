//Max Length Chain Of Pairs
//(5,24) 1
//(39,60) 
//(5,28) 
//(27,40) 2
//(50,90) 3
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2)
{
	return p1.second < p2.second;	
}

int max_length_chain(vector<pair<int,int>> p)
{
	sort(p.begin(), p.end(), compare);
	
	int count = 1;                   //selecting 1st pair by default
	int curr_end = p[0].second;
	
	
	for(int i=1; i<p.size(); i++)
	{
		if(p[i].first >= curr_end)
		{
			count++;
			curr_end = p[i].second;	
		}	 
	}
	
	return count;
}

int main()
{
	vector<pair<int,int>> p(5, make_pair(0,0));
	
	//storing values
	p[0] = make_pair(5,24); 
	p[1] = make_pair(39,60); 
	p[2] = make_pair(5,28);  
	p[3] = make_pair(27,40); 
	p[4] = make_pair(50,90); 
	
	cout<<max_length_chain(p);
	
	return 0;
}
