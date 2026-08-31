//Sparse Arrays 
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> matching_strings(vector<string> str_list, vector<string> q)
{
	unordered_map<string,int> freq;
	vector<int> result;
	
	for(int i=0; i<str_list.size(); i++)
	{
		freq[str_list[i]]++;
	}
	
	for(int i=0; i<q.size(); i++)
	{
		result.push_back(freq[q[i]]);
	}
	
	return result;
}

int main()
{
	vector<string> string_list = {"ab","ab","abc"};
	vector<string> queries = {"ab","abc","bc"};
	
	vector<int> result = matching_strings(string_list, queries);

	for(int i=0; i<result.size(); i++)
	{
    	cout<<result[i]<<" ";
	}
	
	return 0;
}

