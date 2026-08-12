//valid parethesis
// ( { [ pairs
#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<char> s;
bool valid_par(string str)
{
		for(int i=0; i<str.size(); i++)
		{
					if(str[i] == '(' || str[i] == '[' || str[i] == '{')
					{
						s.push(str[i]);
					}
					else
					{
						if(s.empty())
						{
							return false;
						}
						
						if((str[i] == ')' && s.top() == '(') ||
               				(str[i] == ']' && s.top() == '[') ||
               				(str[i] == '}' && s.top() == '{'))
						{
							s.pop();
						}
						else
						{
							return false;
						}
					}
		}
		
			if(s.empty())
			{
				return true;
			}
}

int main()
{
	string seq = "{[()]}";
	
	if(valid_par(seq))
	{
		cout<<"valid parenthesis!";
	}
	else
	{
		cout<<"invalid parenthesis!";
	}
	
	return 0;
}
