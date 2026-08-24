//print all subsets of a given string
#include<iostream>
#include<string>
using namespace std;

void string_subsets(string str, string subset)
{
	//base case
	if(str.size() == 0)
	{
		cout<<subset<<"  ";
		return;
	}
	
	char ch = str[0];
	
	string_subsets(str.substr(1,str.size()-1), subset + ch);       //yes choice
	
	string_subsets(str.substr(1,str.size()-1), subset);           //no choice
}

int main()
{
	string str = "abcd";
	string subset = "";
	
	string_subsets(str,subset);
	
	return 0;
}
