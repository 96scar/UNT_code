/*
Author: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 11/6/14
Instructor: Mark Thompson
Purpose: Reads in data for two matrices and then adds them together.
*/

/*Tells the preprocessor to include a copy of the standard input/output library.*/
#include <stdio.h>

/*The function main takes no arguments and returns an int value.*/
int main()
{
	/*Declares an int variable called size, the size of the matrix.*/
	int size, i, j;

	/*Takes input for the size of the matrix.*/
	scanf("%d", &size);

	/*Declares matrix1 and matrix2 2D arrays of size row (size) by column (size)*/
	int matrix1[size][size], matrix2[size][size];
	
	/*Prints out the size of the matrix.*/
	printf("\nMatrix is %dx%d.", size, size);

	/*Scans in values for first matrix*/
	for(i = 0; i < size; ++i)
	{
		for(j = 0; j < size; ++j)
		{
			scanf("%d", &matrix1[i][j]);
		}
	}

	/*Scans in values for second matrix*/
	for(i = 0; i < size; ++i)
	{
		for(j = 0; j < size; ++j)
		{
			scanf("%d", &matrix2[i][j]);
		}
	}

	/*prints out values of first matrix*/
	printf("\nFirst Matrix: \n");
	for(i = 0; i < size; ++i)
	{
		for(j = 0; j < size; ++j)
		{
			printf("%d ", matrix1[i][j]);
	
		}
		printf("\n");
	}

	/*prints out values of second matrix*/
	printf("Second Matrix: \n");
	for(i = 0; i < size; ++i)
	{
		for(j = 0; j < size; ++j)
		{
			printf("%d ", matrix2[i][j]);
		}
		printf("\n");
	}

	/*Adds the two matricies together and print out the values.*/
	printf("matrix1 + matrix2: \n");

	for(i = 0; i < size; ++i)
	{
		for(j = 0; j < size; ++j)
		{
			printf("%d ", matrix1[i][j] + matrix2[i][j]);	
		}
		printf("\n");
	}
	
	printf("\n");

	/*Returns the function main to 0 so the compiler works.*/
	return 0;
}
