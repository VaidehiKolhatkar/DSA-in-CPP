//reverse a stack. RULES - only use recursion, cannot use any other data structures
#include<iostream>
#include<stack>
using namespace std;

void push_at_bot(stack<int> &stack, int val)
{
	//base case
	if(stack.empty())
	{
		stack.push(val);
		return;
	}
	
	int top = stack.top();
	stack.pop();
	
	//recursion
	push_at_bot(stack,val);        //stack ki size 1 se kam
	
	//backtrack (adding all top ele which we had popped)
	stack.push(top);
}

void reverse(stack<int> &s)
{
	//base case
	if(s.empty())
	{
		return;
	}
	
	int temp = s.top();
	s.pop();
	reverse(s);
	push_at_bot(s,temp);
}

int main()
{
	stack<int> s;
	
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	
	reverse(s);
	
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		
		s.pop();
	}
	
	return 0;
}
