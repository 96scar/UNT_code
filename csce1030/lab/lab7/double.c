/*
Author: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 10/9/14
Instructor: Mark Thompson
Purpose: Computes the square of an integer using only addition in 2 different ways: using a for-loop, and using a do-while loop.
*/

/*This preprocessor directive tells the preprocessor to include a copy of the standard input/output library in this program.*/
#include <stdio.h>

/*The function main has no arguments and returns an int value.*/
int main()
{
	/*Declares num, menu, and square as int values.*/
	int num, menu, square;

	/*Asks the user to input an integer num.*/
	printf("\nInput an integer to be squared: ");
	scanf("%d", &num);	

	/*Prints out the menu and asks the user to choose an option in the menu.*/
	printf("\nChoose an option from the menu.\n1 for-loop\n2 do-while loop\n\n");
	scanf("%d", &menu);	

	/*Checks to see if the user input a 1 or a 2 and performs the following statements until the break. 
	Uses a default case to tell the user that they did not choose a menu number.*/
	switch(menu)
	{

		/*When the menu value chosen is 1, the for loop will be performed. Square is set to start at 0, 
		the loop continues as long as square is less than or equal to num times num minus num. 
		The increment is square equals square plus num.*/
		case 1: for ( square = 0 ; square <= num * num - num ; square += num )
			{
				/*This is an empty statement.*/
				;			
			}
			break;
		
		/*When the menu value chosen is 2, the do while loop is performed. I set square eqal to 0. 
		Square is incremented to square plus num. The condition is checked to see if square is less 
		than or equal to num times num minus num. */
		case 2: square = 0;
			do
			{
				square += num;
			}
			while(square <= num * num - num);
			break;

		/*The default case lets the user know that they did not choose a menu number.*/
		default: printf("\nYou did not input a menu number.\n");
			 square = 0;
			 break;
	}

	/*Prints out the value of the integer squared, regardless of which loop option was chosen.*/
	printf("\nThe value of your integer squared is %d.\n\n", square);

	/*Returns the function value to zero so that the compiler works.*/
	return 0;
}

