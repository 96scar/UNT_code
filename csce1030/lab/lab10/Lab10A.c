/*
Author: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 10/30/2014
Instructor: Mark Thompson
Purpose: Uses two different functions to pass by value and pass by reference in order to cube a value.
*/

/*Tells the preprocessor to include a copy of the standard input/output library into the program.*/
#include <stdio.h>
#include <math.h>

/*Function prototypes let the compiler know to expect use of these functions.*/
double by_value_cubed(double);
double by_ref_cubed(double*, double*);

/*The function main takes no arguments and returns an int value.*/
int main()
{
	/*Declares the variables value1, value2, answer1, and answer2 as doubles.*/
	double value1, value2;
	double answer1, answer2;

	/*Sets value1 equal to 3.3*/
	value1 = 3.3;

	/*Call by_value_cubed to compute the cube of value1 and store it in answer1.*/
	answer1 = by_value_cubed(value1);

	/*Sets value2 equal to 2.2*/
	value2 = 2.2;

	/*Call by_ref_cubed to compute the cube of value2 and store it in answer2.*/
	by_ref_cubed(&value2, &answer2);
	
	/*prints out the values of answer1 and answer2*/
	printf("\nValue1 cubed=%lf   Value2 cubed=%lf\n\n", answer1, answer2);

	/*Returns the function main's value to 0 so that the compiler works.*/
	return 0;
}

/*
Function: by_value_cubed
Parameters: a double representing the value input
Return: the answer, which is the value cubed
Description: This function cubes the value passed into the function
*/
double by_value_cubed(double value)
{
	double answer = pow(value, 3);

	return answer;
}

/*
Function: by_ref_cubed
Parameters: a double pointer pointing to the address of value2 and a double pointer pointing to the address of answer2
Return: the value of value2
Description: This function compute the value of value2 cubed and stores it into answer2 by reference
*/
double by_ref_cubed(double *value2, double *answer2)
{
	*answer2 = pow(*value2, 3);

	return *value2;
}
