//reverse a string using stack
#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<char> stk;

void rev_str(string str, int i)
{	
	//base case
	if(i == str.size())
	{
		return;
	}
	
	char ch = str[i];
	stk.push(ch);
	rev_str(str,i+1);
}

int main()
{
	string str = "watermelon";
	
	rev_str(str,0);
	
	while(!stk.empty())
	{
		cout<<stk.top()<<" ";
		
		stk.pop();
	}
	
	return 0;
}
