/*
Author: Scarlett Jones (ScarlettJones@my.unt.edu)
Teacher: Keathly
Date: 3/31/15
Description: C++ introductory program. I used arguments to main to make matrices. 
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
	int rows, columns, i, x, y, menu, sum;
	rows = atoi(argv[1]);
	columns = atoi(argv[2]);
	sum = 0;
	menu = 1;

	int matrix[rows][columns];


// I assign the parts of the arguments to main that are the matrix to the matrix
	for(i = 3; i < argc; i++)
	{
		for(x = 0; x < rows; x++)
		{
			for(y = 0; y < columns; y++)
			{
				matrix[x][y] = atoi (argv[i++]);
			}
		}
	}

//while loop goes until menu option chosen is 0
	while(menu != 0)
	{
		cout << "Select a menu option." << endl;
		cout << "0: Exit" << endl
		     << "1: Print the matrix" << endl
		     << "2: Sum all of the elements" << endl
		     << "3: Show the upper half" << endl
		     << "4: Show middle row" << endl
		     << "5: Show middle column" << endl;
		
		cout << "Option: ";
		cin >> menu;
		cout << endl;
	
		switch(menu)
		{
			case 0: // exits program
			break;

			case 1: // print matrix
			for(x = 0; x < rows; x++)
			{
				for(y = 0; y < columns; y++)
				{
					cout << setw(10) << matrix[x][y] << " ";
				}
				cout << endl;
			}
			break;

			case 2: // sums matrix and prints sum
			for(i = 3; i < argc; i++)
			{
				sum += atoi(argv[i]);
			}	
		
			cout << sum << endl;
			break;

			case 3: // shows upper half
		
			if(rows == columns)
			{
				cout << "Matrix is a sqaure." << endl;
				
				for(x = 0; x < rows; x++)
				{
					for(y = 0; y < columns; y++)
					{
						if(y >= x)
						{
							cout << setw(10) << matrix[x][y] << " ";
						}
						else
						{
							cout << "           ";
						}
					}
					cout << endl;
				}
			}
			else
			{
				cout << "Matrix is not a square." << endl;
			}

			break;

			case 4: // shows middle row
			if(rows%2 != 0)
			{
				cout << "Odd number of rows" << endl;
				
				
					for(y = 0; y < columns; y++)
					{
						
							cout << setw(10) << matrix[rows%2][y] << " ";
						
					}
					cout << endl;
				
			}
			else
			{
				cout << "Does not have an odd number of rows." << endl;
			}

			break;

			case 5: // shows middle column
			if(columns%2 != 0)
			{
				cout << "Odd number of columns" << endl;
				
				
					for(x = 0; x < rows; x++)
					{
						
							cout << setw(10) << matrix[x][columns%2] << " ";
						
					}
					cout << endl;
			
			}
			else
			{
				cout << "Does not have an odd number of columns" << endl;
			}

			break;

			default:
			cout << "Input a choice between 0 and 5" << endl;
			break;
		}
	}

//	for(i = 3; i < argc; i++)
//	{
//		for(x = i; x < rows; x++)
//		{
//			for(y = 0; y < columns; y++)
//			{

//		cout << setw(columns);
//		cout << argv[i] << " " << endl;
//			}
//			cout << endl;
//		}
//	}

	return 0;
}
