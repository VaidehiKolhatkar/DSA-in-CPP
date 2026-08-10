//Iternary from tickets problem
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;

void iternary(unordered_map<string, string> tickets)
{
	string start = "";
	unordered_set<string> to;       //from-to values
	
	for(pair<string, string> ticket : tickets)
	{
		to.insert(ticket.second);
	}
	
	for(pair<string, string> ticket: tickets)
	{
		if(to.find(ticket.first) == to.end())
		{
			start = ticket.first;
		}
	}
	
	//print the route
	cout<<start<<" -> ";
	while(tickets.count(start))
	{
		cout<<tickets[start]<<" -> ";
		start = tickets[start];
	}
	cout<<endl;
	cout<<"destination is reached";
}

int main()
{
	unordered_map<string, string> map;
	
	map["Chennai"] = "Benglore";
	map["Mumbai"] = "Delhi";
	map["Goa"] = "Chennai";
	map["Delhi"] = "Goa";
	
	iternary(map);
	
	return 0;
}
