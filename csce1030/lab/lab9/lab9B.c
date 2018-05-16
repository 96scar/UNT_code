/*
Author: Scarlett Jones
Date: 10/23/2014
Insturctor: Mark Thompson
Purpose: Uses pointers to change the value of other variables and pointers.
*/

/*Tells the preprocessor to include a copy of the standard input/output library in the program.*/
#include <stdio.h>

/*The function main takes no arguments and returns an int value.*/
int main()
{
	/*Declares d1 as a double variable. Declares pointers p1 and p2 as doubles. Initializes d1 to 10.0. Points p1 to d1. Sets p2 equal to p1.*/
	double d1, *p1, *p2;
	d1 = 10.0;
	p1 = &d1;
	p2 = p1;

	/*Prints out the values of d1, *p1, and *p2, which should be the same.*/
	printf("\nd1 = %.1lf\n*p1 = %.1lf\n*p1 = %.1lf\n", d1, *p1, *p2);

	/*Sets contents of p2 to 33.33.*/
	*p2 = 33.33;

	/*I predict that the contents of p1 and the value of d1 will also be 33.33.*/
	printf("\nd1 = %.2lf\n*p1 = %.2lf\n*p1 = %.2lf\n", d1, *p1, *p2);

	/*My prediction was correct. This makes sense because whatever address p2 is pointing to will be changed to 33.33. p2 is equal to p1, which is pointing to d1. So all of the values are 33.33.*/
	/*Returns the function main to 0, an int value, so that the compiler will work.*/
	return 0;
}
