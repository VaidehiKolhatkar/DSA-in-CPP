//search in rowwise and colwise sorted matrix - straicase approach 
#include<iostream>
using namespace std;
//time complexity O(n+m)
void staircase_search(int mat[][4], int n, int m, int key)
{
	int row = 0;
	int col = m-1;
	int start = mat[row][col];
	
	while(row<n && col>=0)
	{
		if(key==start)
		{
			cout<<"key found at index "<<row<<","<<col<<endl;
			break;
		}
		else if(key < start)
		{
			col--;
			start = mat[row][col];
		}
		else
		{
			row++;
			start = mat[row][col];
		}
	}
	//cout<<"key not found";
}

int main()
{
	int matrix[4][4] = {10,20,30,40,15,25,35,45,27,29,37,48,32,33,39,50};
	int n = 4;
	int m = 4;
	int key;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"Enter the element to search"<<endl;
	cin>>key;
	
	staircase_search(matrix,n,m,key);
	
	return 0;
}
