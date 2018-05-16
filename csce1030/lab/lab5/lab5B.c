/*
Author: Scarlett Jones(ScarlettJones@my.unt.edu)
Date: 9/25/14
Instructor: Mark Thompson
Purpose: To reinforce concepts already covered in previous labs, and to give me a better understanding of working with character data.
*/

/* This preproccessor directive tells the preprocessor to include a copy of the standard input/output library in the program, found in the usual place.  */
#include <stdio.h>


/* The function main takes no arguments and returns an int value. */
int main()
{
	/* I define x as an integer value so that I can end the while loop when 0 is input. I initiate the variable x as 65 so that the while loop will begin. */
	char x;
	x = 65;

	/* This asks the user to input text to be encoded. */
        printf("Please enter the text to be encoded: ");
	
	/* This is a while loop that will loop until the value 0 is input. 48 is the ASCII value of 0. */
	while ((x = getchar()) != 48)
	{
		/*I add in an if else statement to change letters to the next letter in the alphabet. I use the ASII table to convert the characters to the right thing. */
		if (x >= 65 && x <= 89)		
			putchar(x + 1);
		else if (x == 90)
			 putchar(x - 25);
		else if (x >= 97 && x <= 121)
			putchar(x + 1);
		else if (x == 122)
			putchar(x - 25);
		else if (x == 32)
			putchar(0);
		else
			putchar(x);

	}

	/* This returns the function value to zero so that the compiler will work.  */
	return 0;
}
