//diagonal sum - optimal O(n) complexity
#include<iostream>
using namespace std;

void diag_sum(int mat[][3], int n, int m)
{
	int sum = 0;
	
	for(int i=0; i<n; i++)
	{
		sum += mat[i][i];
		
		if(i != n-i-1)
		{
			sum += mat[i][n-i-1];
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
