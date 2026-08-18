//using priority queue
//operator overloading is used to tell queue about comparison
//build max heap
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Student
{
	public:
		string name;
		int marks;
		
		Student(string n, int m)
		{
			name = n;
			marks = m;
		}
		
		//op overloading
		bool operator < (const Student &obj) const
		{
			return this->marks < obj.marks;
		}
};

int main()
{
	priority_queue<Student> pq;
	
	pq.push(Student{"axar", 85});
	pq.push(Student{"bumrah", 95});
	pq.push(Student{"chahal", 90});
	
	while(!pq.empty())
	{
		cout<<pq.top().name<<" scored "<<pq.top().marks<<endl;
		pq.pop();
	}
	
	
	return 0;
}
