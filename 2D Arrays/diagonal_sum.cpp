//2d arrays - diagonal sum - given n=m 
#include<iostream>
using namespace std;

void diag_sum(int mat[][3], int n, int m)
{
	//primary diagonal sum
	int pd_sum = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(i==j)
			{
				pd_sum += mat[i][j]; 
			}
		}
	}
	cout<<"primary diagonal sum is "<<pd_sum<<endl;
	
	//secondary diagonal sum
	int sd_sum = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			int k = (n-1)/2;
			
			if(n%2 == 1 && i==j==k)
			{
				continue;
			}
			
			if(i+j == n-1)
			{
				sd_sum += mat[i][j]; 
			}
		}
	}
	cout<<"secondary diagonal sum is "<<sd_sum<<endl;
	
	int sum = pd_sum + sd_sum;
	cout<<"total diagonal sum is "<<sum<<endl;
}

int main()
{
	int matrix[3][3] = {1,2,3,4,5,6,7,8,9};
	int n = 3;
	int m = 3;
	
	diag_sum(matrix,n,m);
	
	return 0;
}
