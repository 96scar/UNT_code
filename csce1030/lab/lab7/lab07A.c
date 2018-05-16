/*
Author: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 10/9/14
Instructor: Mark Thompson
Purpose: A for loop that prints the values from -2 to 8.
*/

/*This preprocessor directive tells the preprocessor to include a copy of the standard input/output library in this program.*/
#include <stdio.h>

/*The function main has no arguments and returns an int value.*/
int main()
{
	/*Decalres i as an int variable. I stands for integer.*/
	int i;

	/*A for loop that prints the values from -2 to 8. I initialize i as -2, the first number to print. I make the condition if i is less than or equal to 8, the last number to print. I increment i by 1, because I want to print out every number.*/
	for( i = -2 ; i <= 8 ; i++ )
	{
		/*Prints out the current value of i, starting with -2, and then goes back to increment and check the condition. Once it is incremented to 9, the condition will no longer be true and the for loop will end, no longer printing any integers.*/
		printf("\n%d\n", i);
	}

	/*Returns the function value to zero so that the compiler works.*/
	return 0;
}

