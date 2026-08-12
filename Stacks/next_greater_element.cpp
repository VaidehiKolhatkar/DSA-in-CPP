//Next Greater Element using stacks
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void next_greater(vector<int> arr, vector<int> ans)
{
	stack<int> s;
	
	int idx = arr.size() - 1;
	ans[idx] = -1;
	s.push(arr[idx]);
	
	for(idx; idx>=0; idx--)
	{
		while(!s.empty() && arr[idx] >= s.top())
		{
			s.pop();
		}
		
		if(s.empty())
		{
			ans[idx] = -1;
		}
		else
		{
			ans[idx] = s.top();
		}
			s.push(arr[idx]);
	}
	
	for(int i=0; i<ans.size(); i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	vector<int> array = {6,8,0,1,3};
	vector<int> answer = {0,0,0,0,0};
	
	next_greater(array,answer);
	
	return 0;
}
