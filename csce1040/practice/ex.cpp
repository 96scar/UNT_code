#include <iostream>

using namespace std;

void input(int r, int c) //, int &m[r][c]);

int main()
{
	int row, column;
	row = 5;
	column = 5;
	int matrix[row][column];

	input(row, column); //, matrix[row][column]);	


	return 0;
}


void input(int r, int c)//, int &m[r][c])
{
	int i, j, **m;

	for(i = 0; i < r; i++)
	{
		cin << m[i][0];
	
		for(j = 0; j < c; j++)
		{
			

			cin << m[0][j];	
		}
	}

	return;
}
