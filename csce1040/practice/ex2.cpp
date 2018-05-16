#include <iostream>
#include <iomanip>

using namespace std;

void initialize(int r, int c, int& a[r][c]);
void print(int r, int c, int a[r][c]);

int main()
{
	const int row = 5;
	const int column = 5;
	int array[row][column];
	
	initialize(row, column, array[row][column]);
	print(row, column, array[row][column]);

	return 0;
}

void initialize(int r, int c, int& a[r][c])
{
	int i, j;

	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			a[i][j] = 0;
		}
	}

	return;
}

void print(int r, int c, int a[r][c])
{
	int i, j;

	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			cout << setw(30) << a[i][j];
		}
		cout << endl;
	}

	return;
}
