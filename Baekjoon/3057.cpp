#include<stdio.h>

int main(void)
{
	int row, col;
	
	scanf("%d %d", &row, &col);
	
	int** program = new int*[row];
	for(int i=0;i<row;i++)
		program[i] = new int[col];
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			scanf("%d", &program[i][j]);
		}
	}
	
	
	
	for(int i=0;i<row;i++)
		delete[] program[i];
	delete[] program;
	
	return 0;
}

bool killer(int _n, int** _program)
{
	int i = 0, j = _n;
	if(_n%2 == 0)
	{
		while(i<j)
		{
			if(compare_row(i, j, _n, _program))
		}
	}
	else
	{
		
	}
}

bool compare_row(int _row1, int _row2, int _col, int** _program)
{
	int i;
	for(i=0;i<_col;i++)
	{
		if(_program[_row1][i] == _program[_row2][i])
		{
			continue;
		}
		else
			return 0;
	}
	if (i == _col)
		return 1;
}
