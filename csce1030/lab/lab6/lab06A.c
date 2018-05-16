/*
Author: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 10/2/14
Instructor: Mark Thompson
Purpose: Add in the missing code. Learn how to use switch statements.
*/

/* This preproccessor directive tells the preproccessor to include a copy of the standard input/output library, found in the usual place.  */
#include <stdio.h>


/* The function main returns an int value and takes no arguments.  */
int main()
{
	/* Decalres value as a double and asks the user to input a value with printf and scanf statements.  */
	double value;
	printf("Input a value: ");
	scanf("%lf", &value);

	/*Prints four options to the screen associated with the functionality of the switch statement below: */
	printf("\n1 Increase the value by 1\n2 Decrease the value by 1\n3 Double the value\n4 Half the value\n");

	/* Declares option as an int.  */
	int option;

	/* Asks the user to choose an option 1 through 4 */
	printf("\nChoose an option: ");
	scanf("%d", &option);

	/* This begins the switch statment in which 4 cases or a default case could be performed.  */
	switch(option)
	{
		/* Case 1 increases the value input by 1.  */
		case 1:
		printf("\n\nYour value increased by 1 is %lf.\n\n", value + 1);
		break;

		/* Case 2 decreases the value input by 1.  */
		case 2:
		printf("\n\nYour value decreased by 1 is %lf.\n\n", value - 1);
		break;

		/* Case 3 doubles the value input.  */
		case 3:
		printf("\n\nYour value doubled is %lf.\n\n", value * 2);
		break;
		
		/* Case 4 halves the value input.  */
		case 4:
		printf("\n\nYour value halved is %lf.\n\n",  value / 2);
		break;

		/* The default case prints out a statment saying that invalid input was chosen, rather than doing nothing.  */
		default:
		printf("\n\nThe option you selected was invalid.\n\n");
	}

	/* This returns the function value to zero to make the complier work.  */
	return 0;
}
