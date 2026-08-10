//valid anagrams 
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

bool anagrams(string s1, string s2)
{
	unordered_map<char, int> map;
	
	for(int i=0; i<s1.size(); i++)
	{
		if(map.count(s1[i]))
		{
			map[s1[i]]++;
		}
		else
		{
			map[s1[i]] = 1;
		}
	}
	
	for(int i=0; i<s2.size(); i++)
	{
		if(map.count(s2[i]))
		{
			map[s2[i]]--;
			
			if(map[s2[i]]==0)
			{
			    map.erase(s2[i]);	
			}
		}
		else
		{
			return 0;	
		}
	}
	
	if(map.size() == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	string s1 = "race";
	string s2 = "care";
	
	cout<<anagrams(s1, s2);
	
	return 0;
}
