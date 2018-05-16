/*
Author: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 10/2/14
Instructor: Mark Thompson
Purpose: Create a calendar that asks the user for the current month and then display the number of days in that month. For extra credit, tell how many days are in February on a leap year.
*/

/* This preproccessor directive tells the preproccessor to include a copy of the standard input/output library, found in the usual place.  */
#include <stdio.h>


/* The function main returns an int value and takes no arguments.  */
int main()
{
	/* Declares month as an int and year as a float.  */
	int month;
	float year;

	/* Asks the user to input the current month as an integer code.  */
	printf("\n\nEnter the current month as an integer: ");
	scanf("%d", &month);

	/* This begins the switch statment in which 12 cases or a default case could be performed.  */
	switch(month)
	{
		/* Case 4 (April), case 6 (June), case 9 (September), and case 11 (November) have 30 days. */
		case 4: case 6: case 9: case 11:
		printf("\nThe month you entered has 30 days.\n\n");
		break;

		/* Case 2 (February) has 28 days. */
		case 2:
                printf("\nThe month you entered has 28 days.\n\n");
		break;

		/* Case 1 (January), 3 (March), 5 (May), 7 (July), 8 (August), 10 (0ctober), and 12 (December) have 31 days. */
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		printf("\nThe month you entered has 31 days.\n\n");
		break;

		/* All the other month cases have 31 days. The default case prints out a statment saying that invalid input was chosen, rather than doing nothing.  */
		default:
		printf("\nYou did not enter a month.\n\n");
	}

	/* This returns the function value to zero to make the complier work.  */
	return 0;
}
