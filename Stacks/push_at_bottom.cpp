//push at the bottom of stack (recursion)
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

int main()
{
	stack<int> s;
	
	s.push(1);
	s.push(2);
	s.push(3);
	
	push_at_bot(s,4);
	
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		
		s.pop();
	}
	
	return 0;
}
