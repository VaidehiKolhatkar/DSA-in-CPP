//diag sum - more efficient logic 
#include<iostream>
using namespace std;

void diag_sum(int mat[][3], int n, int m)
{
	int sum = 0;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(i==j)
			{
				sum += mat[i][j];
			}
			else if(j == n-i-1)
			{
				sum += mat[i][j];
			}
		}
	}
	
	cout<<"diagonal sum is "<<sum;
}

int main()
{
	int matrix[3][3] = {1,2,3,4,5,6,7,8,9};
	int n = 3;
	int m = 3;
	
	diag_sum(matrix,n,m);
	
	return 0;
}
