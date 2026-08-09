//unordered set - insert, size, find, erase
//stored unique keys only
#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

int main()
{
	unordered_set<int> set;
	
	//insert
	set.insert(1);
	set.insert(3);
	set.insert(6);
	set.insert(7);
	set.insert(1);
	
	//size
	cout<<"size is "<<set.size()<<endl;
	
	//search
	int key = 9;
	if(set.find(key) != set.end())                   //important syntax
	{
		cout<<key<<" exists"<<endl;
	}
	else
	{
		cout<<key<<" doesn't exists"<<endl;
	}
	
	//erase
	set.erase(1);
	
//	cout<<endl;
//	cout<<"after removing"<<endl;
	
	return 0;
}
