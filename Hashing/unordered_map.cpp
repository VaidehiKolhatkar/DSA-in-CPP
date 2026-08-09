//unordered maps - insert using array[index] syntax, count (acts as search), erase
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main()
{
	unordered_map<string, int> map;
	
	//insert
	map["Apple"] = 12;
	map["Watermelon"] = 2;
	map["Muskmelon"] = 4;
	map["Grapes"] = 80;
	map["Strawberry"] = 24;
	
	//print
	for(pair<string,int> fruits : map)
	{
		cout<<fruits.first<<","<<fruits.second<<endl;
	}
	
	//search - if key exists, then count will be 1. Otherwise, 0
	string key = "Apple";
	if(map.count(key))
	{
		cout<<key<<" exists"<<endl;
	}
	else
	{
		cout<<key<<" doesn't exists"<<endl;
	}
	
	//erase
	map.erase("Apple");
	
	cout<<"after removing"<<endl;
	for(pair<string,int> fruits : map)
	{
		cout<<fruits.first<<","<<fruits.second<<endl;
	}
	
	return 0;
}
