/*
Author: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 10/16/2014
Instructor: Mark Thompson
Purpose: Passes a number to the squre_it() function to multiply a number by itself, or square it.
*/

/* This preprocessor directive tells the preprocessor to include a copy of the sstandard input output library into the program. */ 
#include <stdio.h> 

/* This is a function prototype that declares the function so that the compiler will expect the function to be defined and used later. */
int square_it(int num); 

/* The function main takes no arguments and returns an int value. */
int main(void) 
{ 
	/* Declares x and y as int variables. */
	int x, y;

	/* Asks the user for input of an integer that they want to square. */
	printf("\nEnter an integer: "); 
	scanf("%d", &x);

	/* Prints out the integer that the user input. */
	printf("main: x = %d\n", x); 

	/* Passes control to the function square_it. Stores what the function returns in y. */
	y = square_it(x); 

	/* Prints out what what the integer is after it is squared. */
	printf("main: x ^ 2 = %d\n\n", y); 

	/* This returns zero becuase the function main is expecting to return an int value. */
	return 0; 
} 

/* This is defining what the function square_it is going to do. */
int square_it(int num) 
{ 
	/* Prints out the number the user input. */
	printf("square_it: num = %d\n", num); 

	/* Multiplies num by itself. */
	num *= num;

	/* Prints out what num is after it has it's new value of it squared. */
	printf("square_it: num ^ 2 = %d\n", num); 
	return num; 
}

