//build min heap for ranks
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Student
{
	public:
		string name;
		int rank;
		
		Student(string name, int rank)
		{
			this->name = name;
			this->rank = rank;
		}
		
		bool operator < (const Student &obj) const
		{
			return this->rank > obj.rank;
		}
};

int main()
{
	priority_queue<Student> pq;
	
	pq.push(Student{"rm",1});
	pq.push(Student{"jin",4});
	pq.push(Student{"suga",5});
	
	while(!pq.empty())
	{
		cout<<pq.top().rank<<" : "<<pq.top().name<<endl;
		pq.pop();
	}
	
	return 0;
} 
