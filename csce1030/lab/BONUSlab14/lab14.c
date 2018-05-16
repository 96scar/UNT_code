/*
Author: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 12/3/14
Instructor: Mark Thompson
Purpose: Reverses the string input in the command line argument (not ./a.out) and outputs it to a file.
*/

/*
Tells the preproccessor to include the standard input output and string library.
*/
#include <stdio.h>
#include <string.h>

/*Function prototype tells compiler to expect use of this function.*/
void reverse(char *word);

/*The function main takes arguments int argc(argument counter) and char *argv[](a 2D array for the command line arguments), and it returns an int value.*/
int main(int argc, char *argv[])
{
	/*Declares an int called i for a for loop*/
	int i;

	/*Makes a file pointer called fp*/
	FILE *fp;

	/*Opens a file called reversed in write mode. This deletes everything already existing in the file. If the file doesn't exist yet, it creates it.*/
	fp = fopen("reversed", "w");

	printf("\n");

	/*If the number of command line arguments is 1, only ./a.out, prints an error message.*/
	if(argc == 1)
		printf("Incorrect command line arguments.");
	/*If there's more than one command line argument, print number of commands minus ./a.out*/
	else
	{
		printf("Number of Commands: %d", argc - 1);
		printf("\n\nTo see reversed string, type \"more reversed\"");

		/*Starts i at the number of command line arguments minus one (because the index number is one less), loops as long as i is greater than 0 (the ./a.out command), and decrements i by one each time.*/
		for(i = argc - 1; i > 0; --i)
		{
			/*Calls the reverse function, passing the last word first, and the first word last.*/
			reverse(argv[i]);
	
			/*Outputs the string to a file that fp is pointing to*/
			fprintf(fp, "%s ", argv[i]);
		}
	}
	printf("\n\n");

	/*Closes the file*/
	fclose(fp);

	/*Returns main to 0 so compiler works*/
	return 0;
}

/*
Function: reverse
Parameters: a char representing the string passed in
Return: nothing
Description: Reverses the string
*/
void reverse(char *word)
{
	int i, j;
	char letter;
	i = 0;
	j = strlen(word) - 1;

	/*While i is less than j*/
	while(i < j)
	{
		/*Copies the ith letter of the string to letter*/
		letter = word[i];

		/*Replaces the ith letter of the string to the jth letter of the string*/
		word[i] = word[j];
	
		/*Replaces the jth letter of the string with letter*/
		word[j] = letter;
		
		/*Increments i and decrements j*/
		i++;
		j--;	
	}
}
