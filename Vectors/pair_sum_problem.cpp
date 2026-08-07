//pair sum - 2 pointer approach
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> vec = {2,7,11,15};
	
	for(int i=0; i<vec.size(); i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;
	
	int target;
	cout<<"Enter the target sum"<<endl;
	cin>>target;
	
	int start = 0;
	int end = vec.size() - 1;
	
	int curr_sum;
	
	while(start < end)
	{
		curr_sum = vec[start] + vec[end];
		
		if(curr_sum == target)
		{
			cout<<"the pair is "<<vec[start]<<","<<vec[end]<<endl;
			cout<<"at index "<<start<<","<<end<<endl;
			
			break;
		}
		else if(curr_sum < target)
		{
			start++;
		}
		else
		{
			end--;
		}
	}
}
