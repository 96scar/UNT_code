/*
Author: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 9/26/14
Instructor: Mark Thompson
Description: A calculator with a menu that allows for addition, multiplication, square root, and exit. Detects errors and reprints menu until exit is chosen.
*/

/* This causes the preprocessor to include a copy of the header files stdio.h, found in the usual place, stdio.h is th  strandar input/output library. */
#include <stdio.h>

/*This is needed to be able to use the square root function.*/
#include <math.h>

/* The function main takes no arguments and returns an int value. */
int main()
{

	/* This initially displays the department and course number, the program number, my name, my EUID, and my e-mail address.  */
	printf("\nCSCE 1030\nProgram 2\nScarlett Jones\nsrj0101\nScarlettJones@my.unt.edu\n");

	/* This declares a, b, and menu as double numbers. a is the first number input by the user, while b is the second number input by the user. 
	menu is the menu number that the user chooses. */
	double a, b, menu;
	menu = 1;

	printf("\nHello! Choose a menu number to perform an operation!\n");

		/* This begins the while loop, and the menu will be reprinted until the user choses 4. 
		If the user inputs an incorrect menu number, an error message will be displayed and the menu will be reprinted.  */
		while (menu >= 1 && menu <= 3)
		{ 
		 printf("\n1 Addition\n2 Multiplication\n3 Square Root\n4 Exit\n\n");
                 scanf("%lf", &menu); 
		
			if (menu == 1)
			{		
				printf("\nInput two double numbers to add: ");
				scanf("%lf %lf", &a, &b);
				printf("\n%lf+%lf=%.3lf.\n", a, b, a + b);
			}
			else if (menu == 2)
			{
				printf("\nInput two double numbers to multiply: ");
				scanf("%lf %lf", &a, &b);
				printf("\n%lf*%lf=%.3lf.\n", a, b, a * b);
			}
			else if (menu == 3)
			{
				printf("\nInput one double number to find the square root of: ");
				scanf("%lf", &a);
				
				if (a >= 0)
				{
					printf("\nThe square root of %lf is %.3lf.\n", a, sqrt(a));
				}
				else
				{
					printf("\nYou input a negative number. Try again.\n");
				}
			
			}
			else if (menu != 1 && menu != 2 && menu != 3 && menu != 4)
			{
				printf("\nYou did not input a menu number. Try again!\n");
				menu = 1;
			}
			else
			{
				printf("\nThank you for using this program. Goodbye!\n\n");
			}
		}	

	/* This returns the function value to zero so that the compiler will work correctly.  */
	return 0;
}
