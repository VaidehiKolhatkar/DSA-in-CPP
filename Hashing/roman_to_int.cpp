//roman to integer
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int roman_to_int(string s)
{
	unordered_map<char, int> map;
	
	map['I'] = 1;
	map['V'] = 5; 
	map['X'] = 10; 
	map['L'] = 50; 
	map['C'] = 100; 
	map['D'] = 500; 
	map['M'] = 1000;  
	
	int answer = 0;
	
	for(int i=0; i<s.size(); i++)
	{
		if(  (i+1) < s.size() && 
			(   (s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')) ||
			    (s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) ||
				(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M'))
			)
		)
		{
			answer += map[s[i+1]] - map[s[i]];
			i++;
		}
		else
		{
			answer += map[s[i]]; 
		}
	}
	
	return answer;
}

int main()
{
	//string s = "MVI";              //56
	string s = "MCMXCIV";              //104
	
	cout<<roman_to_int(s);
	
	return 0;
}
