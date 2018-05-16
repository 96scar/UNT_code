/*
Author: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 10/16/2014
Instructor: Mark Thompson
Purpose: Computes and returns the factorial of a positive integer n, which is the product of all positive integers from 1 to n. There are two functions.
*/

/* This preprocessor directive tells the preprocessor to include a copy of the standard input output library into the program. */
#include <stdio.h>

/* These are the function prototypes to compute the factorial of an integer. This lets the compiler exepct that these functions will be used later in the program. */
int factorial(int);
void answer(int);

/* The function main takes no arguments and returns an int value. */
int main()
{
	/* Declares num and value as int variables. */
	int num, value;
	
	/* Asks the user to input an integer to find the factorial of. */
	printf("\nInput an integer to find the factorial of: ");
	scanf("%d", &num);

	/* Stores the return of the function factorial into the variable value. */
	value = factorial(num);
	
	/* Passes control to the function answer. */
	answer(value);

	/*  Returns the main function value to 0 so that the compiler will work properly.*/
	return 0;
}

/* Defines the function factorial. */
int factorial(int num)
{
	/* Declares and initializes factorial as an int. */
	int factorial = 1;
	
	/* The while loop continues while num is not equal to 0. */
	while(num != 0)
	{
		/* Sets factorial equal to factorial times num. */
		factorial *= num;

		/* Subtracts 1 from num every time at the end of the while loop. */
		num -= 1;
	}
	/* Must return an int value to pass to main. */
	return factorial;
}

/* Defines the function answer. */
void answer(int factorial)
{
	/* Prints out the answer that was passed from the function factorial. */
	printf("factorial = %d\n\n", factorial);

	/* Void functions return nothing. */
	return;
}
