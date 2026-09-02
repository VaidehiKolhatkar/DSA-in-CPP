//count frequency of characters
#include<iostream>
#include<string>
using namespace std;

void count_freq(string str)
{
	int arr[26] = {0};
	
	for(int i=0; i<str.length(); i++)
	{
		arr[str[i] - 'a']++;
	}
	
	for(int j=0; j<26; j++)
	{
		if(arr[j] > 0)
		{
			char ch = j + 'a';
			cout<<ch<<" : "<<arr[j]<<endl;
		}
	}
}

int main()
{
	string str = "socorro";
	
	count_freq(str);
	
	return 0;
}
