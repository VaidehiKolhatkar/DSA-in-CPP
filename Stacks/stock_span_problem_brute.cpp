//stock span problem
//Given stock values on each day, calculate for how many previous consecutive days stock value was <= current value
//BRUTE FORCE
#include<iostream>
using namespace std;

void stock_span(int stock[], int n)
{
	int answer[7];
	answer[0] = 1;
	answer[1] = 1;
	
	for(int i=2; i<n; i++)
	{
		for(int j=i-1; j>=0; j--)
		{
			if(stock[j] > stock[i])
			{
				answer[i] = i - j;
				break;
			}
				answer[i] = i+1;
		}
	}
	
	for(int k=0; k<n; k++)
	{
		cout<<answer[k]<<" ";
	}
}

int main()
{
	int stock[7] = {100,80,60,70,60,85,100};
	int n = 7;
	
	stock_span(stock,n);
	
	return 0;
}  
