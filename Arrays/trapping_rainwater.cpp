//trapping rainwater - arrays 
#include<iostream>
using namespace std;
int main()
{
	int n=7;
	int heights[n] = {4,2,0,6,3,2,5};
	
	int left_max[n], right_max[n];
	
	left_max[0] = heights[0];
	right_max[n-1] = heights[n-1];
	
	for(int i=1; i<n; i++)
	{
		left_max[i] = max(left_max[i-1], heights[i-1]);		
	}
	
	for(int i=n-2; i>=0; i--)
	{
		right_max[i] = max(right_max[i+1], heights[i+1]);		
	}
	
	int water_trapped = 0;
	
	for(int i=0; i<n; i++)
	{
		int water = min(left_max[i], right_max[i]) - heights[i];
		
		if(water > 0)
		{
			water_trapped += water; 
		}
	}
	
	cout<<"total water trapped is "<<water_trapped;
}

