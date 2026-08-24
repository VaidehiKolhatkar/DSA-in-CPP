//sudoku solver
#include<iostream>
using namespace std;

void print(int sudoku[9][9])
{
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			cout<<sudoku[i][j]<<"  ";
		}
			cout<<endl;
	}
}

bool is_safe(int sudoku[][9], int row, int col, int dig) 
{
	//vertical
	for(int i=0; i<9; i++)
	{
		if(sudoku[i][col] == dig)
		{
			return false;
		}
	}
	
	//horizontal
	for(int j=0; j<9; j++)
	{
		if(sudoku[row][j] == dig)
		{
			return false;
		}
	}
	
	//grid
	//special formulae for start_row and start_col 
	int start_row = (row/3) * 3;
	int start_col = (col/3) * 3;
	
	for(int i=start_row; i<=start_row+2; i++)
	{
		for(int j=start_col; j<start_col+2; j++)
		{
			if(sudoku[i][j] == dig)
			{
				return false;
			}
		}
	}
	
		return true;
}

bool sudoku_solver(int sudoku[][9], int row, int col)
{
	//base case
	if(row == 9)
	{
		print(sudoku);
		return true;
	}
	
	
	int next_row = row;
	int next_col = col+1;
	
	if(col == 8)
	{
		next_row = row+1;
		next_col = 0;
	}
	
	if(sudoku[row][col] != 0)
	{
		return sudoku_solver(sudoku,next_row,next_col);
	}
	
	for(int dig=1; dig<=9; dig++)
	{
		if(is_safe(sudoku,row,col,dig))
		{
			sudoku[row][col] = dig;
			
			if(sudoku_solver(sudoku,next_row,next_col))
			{
				return true;
			}
				sudoku[row][col] = 0;
		}
	}
		return false;
}

int main()
{
	int sudoku[9][9] = {{0, 0, 8, 0, 0, 0, 0, 0, 0},
    					{4, 9, 0, 1, 5, 7, 0, 0, 2},
    					{0, 0, 3, 0, 0, 4, 1, 9, 0},
    					{1, 8, 5, 0, 6, 0, 0, 2, 0},
    					{0, 0, 0, 0, 2, 0, 0, 6, 0},
    					{9, 6, 0, 4, 0, 5, 3, 0, 0},
    					{0, 3, 0, 0, 7, 2, 0, 0, 4},
    					{0, 4, 9, 0, 3, 0, 0, 5, 7},
    					{8, 2, 7, 0, 0, 9, 0, 1, 3}};
    					
    sudoku_solver(sudoku,0,0);
	
	return 0;
}
