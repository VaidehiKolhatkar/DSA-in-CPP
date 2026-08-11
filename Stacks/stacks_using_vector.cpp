//stacks using vector
#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class T>              //variable data type
class Stacks {
	vector<T> vec;
	
	public:
		void push(T val)
		{
			vec.push_back(val);
		}
		void pop()
		{
			if(is_empty())
			{
				cout<<"stack is empty"<<endl;
				return;
			}
			
			vec.pop_back();
		}
		T top()
		{
			int last_idx = vec.size() - 1;
			
//			if(is_empty())
//			{
//				cout<<"stack is empty"<<endl;
//				return -1;
//			}
			
			return vec[last_idx];
		}
		bool is_empty()
		{
			return vec.size() == 0;
		}
//		void print()
//		{
//			for(int i=0; i<vec.size(); i++)
//			{
//				cout<<vec[i]<<" ";
//			}
//				cout<<endl;
//		}
};

int main()
{
	Stacks<char> s;
	
	s.push('a');
	s.push('b');
	s.push('c');
	s.push('d');
	
	while(!s.is_empty())
	{
		cout<<s.top()<<" ";
		
		s.pop();
	}
	
	return 0;
}
