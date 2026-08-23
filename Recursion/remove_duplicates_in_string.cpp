//remove duplicates in a string using recursion
#include<iostream>
#include<string>
using namespace std;

void dup_rem(string str, string ans, int i, int arr[26])
{
	//base case
	if(i == str.size())
	{
		cout<<"Final string is "<<ans;
	}
	
	char ch = str[i];
	int arr_idx = (int)(ch - 'a');
	
	if(arr[arr_idx] == 1)
		dup_rem(str, ans, i+1, arr);
	else
	{
		arr[arr_idx] = 1;
		
		dup_rem(str, ans + ch, i+1, arr);
	}
}

int main()
{
	string str = "ggraapesssss";
	string answer = "";
	int array[26] = {0};
	
	dup_rem(str, answer, 0, array);
	
	return 0;
}
