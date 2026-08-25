//Activity Selection - greedy approach
//given that end time array is already in sorted form
#include<iostream>
#include<vector>
using namespace std;

int max_activs(vector<int> start, vector<int> end)
{
	int count = 1;                   //always pick 1st activity
	int curr_end_time = end[0];
	
	for(int i=1; i<start.size(); i++)
	{
		if(start[i] >= curr_end_time)
		{ 
			count++;
			curr_end_time = end[i];	
		}
	}
	
	return count;
}

int main()
{
	vector<int> start = {1,3,0,5,8,5};
	vector<int> end = {2,4,6,7,9,9};
	
	cout<<max_activs(start,end);
	
	return 0;
}
