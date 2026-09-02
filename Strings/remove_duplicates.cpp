//remove duplicates from string
#include<iostream>
#include<string>
using namespace std;

void remove_dups(string str)
{	
	int arr[26] = {0};
	
	for(int i=0; i<str.length(); i++)
	{
		if(arr[str[i] - 'a'] == 0)
		{
			cout<<str[i];
			arr[str[i] - 'a']++;	
		}
	}
}

int main()
{
	string str = "banana";
	
	cout<<str<<endl;
	
	remove_dups(str);
	
	return 0;
}
