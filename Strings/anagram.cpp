//anagram with strings
#include<iostream>
#include<string>
using namespace std;

bool isAnagram(string str1, string str2)
{
	if(str1.length() != str2.length())
	{
		return false;
	}
	
	int arr[26] = {0};
	
	for(int i=0; i<str1.length(); i++)
	{
//		int idx = str1[i] - 'a';
		arr[str1[i] - 'a']++;
	}
	
	for(int j=0; j<str2.length(); j++)
	{
//		int idx = str2[j] - 'a';
		
		if(arr[str2[j] - 'a'] == 0)
		{
			return false;
		}
		
		arr[str2[j] - 'a']--;
	}
	
	return true;
}

int main()
{
	string str1 = "anagram";
	string str2 = "naturam"; 
	
	cout<<isAnagram(str1,str2);
	
	return 0;
}
