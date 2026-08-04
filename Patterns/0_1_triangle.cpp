// 0-1 triangle pattern
/*   1
     0 1
     1 0 1
     0 1 0 1
     1 0 1 0 1
n=5
*/
#include<iostream>
using namespace std;
int main()
{
	int n=5;
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
		{
			if(i%2 == 1)
			{
				if(j%2 == 1)
				{
					cout<<"1 ";
				}
				else
				{
					cout<<"0 ";
				}
			}
			else
			{
				if(j%2 == 1)
				{
					cout<<"0 ";
				}
				else
				{
					cout<<"1 ";
				}
			}
		}
		cout<<endl;
	}
}
