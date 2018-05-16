/*
Author: Scarlett Jones
Date: 10/23/2014
Insturctor: Mark Thompson
Purpose: Counts the number of times a vowel appears in text inputted through the keyboard.
*/

/*Tells the preprocessor to include a copy of the standard input/output library in the program.*/
#include <stdio.h>

/*The function main takes no arguments and returns an int value.*/
int main()
{
	/*Declares and initializes an array called vowel as an int type with 6 positions, from 0 to 5. 
	Remember that a is 0, e is 1, i is 2, o is 3, u is 4, y is 5.*/
	int vowel[6] = {0, 0, 0, 0, 0, 0}, i;

/*Declares input as a char variable.*/
	char input;

	/*Asks the user to input text.*/
	printf("Please enter text. To stop press CTRL-D: ");

/*While the input is not equal to EOF, or CTRL-D, the while loop will continue.*/
	while(input != EOF)
	{
		/* Uses getchar to ask user for input of text because it will only read one character at a time.*/
		input=getchar();

		/*Tests to see if input is a, e, i , o , u, or y. If it is one of those, 
		it increases its frequency in the array at its position number.
		Otherwise, nothing happens.*/
		if (input == 'a')
			vowel[0] += 1;
		else if (input == 'e')
			vowel[1] += 1;
		else if (input == 'i')
			vowel[2] += 1;
		else if (input == 'o')
			vowel[3] += 1;
		else if (input == 'u')
			vowel[4] += 1;
		else if (input == 'y')
			vowel[5] += 1;
		else

		;

	}

	/*For loop that initializes i as 0, continues as long as i is less than 6, performs the actions in the loop, then increments and stores i by 1.*/
	for (i = 0 ; i < 6 ; ++i)
	{
		/*At position i, the array's value is printed. Each array value from 0 to 5 is printed.*/
		printf("\n%d\n", vowel[i]);
	}

	/*Returns the function main to 0, an int value, so that the compiler will work.*/
	return 0;
}
