/*
Author: Scarlett Jones
Date: 10/23/2014
Insturctor: Mark Thompson
Purpose: Fills the array values of a[SIZE] with a loop and then prints the values of the array from last to first with the index and value.  
*/

/*Tells the preprocessor to include a copy of the standard input/output library in the program.*/
#include <stdio.h>

/*I define SIZE as 20.*/
#define SIZE 20

/*The function main takes no arguments and returns an int value.*/
int main()
{
	/*An array of type float with 20 indexes, starting at 0 and ending at 19.*/
	float a[SIZE];

	/*Variable i is an int that will be used in a loop to store values in the array.*/
	int i;

	/*Initializes i as 0, loops as long as i is less than 20, goes through the loop, then increments and saves i by 1.*/
	for (i = 0 ; i < SIZE ; ++i)
	{
		/*Stores the value of i divided by 2 in the array at index i.*/
		a[i] = (float) i/2;
	}

	/*Initializes i as 19, loops as long as i is greater than or equal to 0, goes through the loop, then decrements and saves i by 1.*/
	for (i = SIZE - 1; i >= 0 ; --i)
	{
		/*Prints out the index next to its array value.*/
		printf("\nIndex: %d		Array Value: %.1f\n", i, a[i]);
	}

	/*Returns the function main to 0, an int value, so that the compiler will work.*/
	return 0;
}
