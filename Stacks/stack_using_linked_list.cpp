//stacks using linked list
#include<iostream>
#include<list>
#include<string>
using namespace std;

template<class T>
class Stacks {
	list<T> ll;
	
	public:
		void push(T val)
		{
			ll.push_front(val);
		}
		void pop()
		{
			if(is_empty())
			{
				cout<<"list is empty"<<endl;
				return;
			}
			ll.pop_front();
		}
		T top()
		{
			return ll.front();
		}
		bool is_empty()
		{
			return ll.size() == 0;
		}
};

int main()
{
	Stacks<int> s;
	
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	
	while(!s.is_empty())
	{
		cout<<s.top()<<" ";
		
		s.pop();
	}
	
	return 0;
}
