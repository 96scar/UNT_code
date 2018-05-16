/*
Author: Scarlett Jones
Date: 11/20/2014
Instructor: Mark Thompson
Purpose: Two functions will dynamically allocate memory based on user input. Three commands are available: reverse, create, and exit. Reverse will reverse what the user types. Create will create a string. Exit will exit the program.
*/

/*These preprocessor directives tell the preprocessor to include a copy of the standard input/output library, the standard library, and the string library to the program. Stdlib.h includes malloc and calloc, and string.h includes strlen.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Two function prototypes that tell the preprocessor to expect functions reverse and create_string later in the program.*/
void reverse();
void create_string();

/*The function main takes no arguments and returns an int value.*/
int main()
{
	/*Sets program to 1 so that the while loop will begin.*/
	int program = 1;

	/*While loop goes until program equals 0, happens when the user types exit.*/
	while(program != 0)
	{
		/*These variables are used in for loops.*/
		int i, j;

		/*Asks the user for an input string/command.*/
		printf("Give a command: ");
	
		char *plarge, *psmall, length, *firstword, input;
		gets(&input);
		length = strlen(&input);
		plarge = malloc(length + 1  * sizeof(char));
		psmall = calloc(length + 1, sizeof(char));
		strcpy(&input, plarge);

		/*Creates the variable firstword*/
		for(i = 0; i < length; i++)
		{
			while(plarge[i] != ' ')
			{
					for(j = 0; j < i; j++)
					{
						firstword[j] = plarge[j];
					}
			}
		}
		
		printf("\nFirst word: %s\n\n", firstword);
		
		if((strcmp(firstword, "reverse")) == 0)
		{
			printf("\nReversing string:\n");
			reverse();
		}
		else if((strcmp(firstword, "create")) == 0)
		{
			printf("\nCreating string:\n");
			create_string();
		}
		else if((strcmp(firstword, "exit")) == 0)
		{
			printf("\nGoodbye\n\n");
			program = 0;
		}
		else
			printf("\nInvalid command.\n");
	free(plarge);
	free(psmall);
	}
	

	/*Returns the function to zero so that the compiler will work.*/
	return 0;
}

/*
Function: reverse
Parameters: 
Return: nothing
Description: Reverses the string and prints it out
*/
void reverse()
{
	printf("");
	return;
}

/*
Function: create_string
Parameters: 
Return: nothing
Description: creates a string
*/
void create_string()
{
	printf("");
	return;
}
