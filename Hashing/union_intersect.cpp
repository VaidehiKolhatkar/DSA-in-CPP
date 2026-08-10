//union and intersection
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

void Union(vector<int> v1, vector<int> v2)
{
	unordered_set<int> set;
	
	for(int i=0; i<v1.size(); i++)
	{
		set.insert(v1[i]);
	}
	for(int i=0; i<v2.size(); i++)
	{
		set.insert(v2[i]);
	}
	
	cout<<"union is [";
	for(int s : set)
	{
		cout<<s<<",";
	}
	cout<<"]"<<endl;
}

void Intersect(vector<int> v1, vector<int> v2)
{
	unordered_set<int> set;
	
	for(int i=0; i<v1.size(); i++)
	{
		set.insert(v1[i]);
	}	
	
	cout<<"intersection is [";
	for(int i=0; i<v2.size(); i++)
	{
		if(set.find(v2[i]) != set.end())
		{
			cout<<v2[i]<<",";
			set.erase(v2[i]);
		}
	}
	cout<<"]"<<endl;
}

int main()
{
	vector<int> v1 = {7,3,9};
	vector<int> v2 = {6,3,9,2,9,4};
	
	Union(v1, v2);
	
	Intersect(v1, v2);
	
	return 0;
}
