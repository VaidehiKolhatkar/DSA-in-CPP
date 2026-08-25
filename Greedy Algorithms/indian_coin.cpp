//Indian Coins - return min no. of coins to make a chnage for given value
//coins - {1,2,5,10,20,50,100,200,500,2000}
//e.g., 653 = 5 ..... (500 + 100 + 50 + 2 + 1) 
#include<iostream>
#include<vector>
using namespace std;

int min_coins(int v)
{
	int array[10] = {1,2,5,10,20,50,100,200,500,2000};
	int count = 0;
	
//	while(v != 0)
//	{
//		for(int i=0; i<10; i++)
//		{
//			if(array[i] > v)
//			{
//				count++;
//				v -= array[i-1];
//				break;
//			}
//		}
//	}

	for(int i=9; i>=0; i--)
	{
		while(v >= array[i])
		{
			v -= array[i];
			count++;
		}
	}
	
	return count;
}

int main()
{
	int value = 653;
	
	cout<<min_coins(value);
	
	return 0;
}
