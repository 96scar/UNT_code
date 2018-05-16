/*
Author: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 10/30/2014
Instructor: Mark Thompson
Purpose: A stemming algorithm that reads only the stems of words, ignoring endings.
*/

/*These preprocessor directives tell the preprocessor to include a copy of the standard input/output library and the string fuctions into the program.*/
#include <stdio.h>
#include <string.h>

/*The function main has no arguments and returns an int value.*/
int main()
{
	/*Declares an array of characters.*/
	char word[30];	

	/*Asks for a word to input, prints out the initial word that was input.*/
	printf("Please enter a word to stem: ");
	scanf("%s", word);
	printf("Initial word: %s\n", word);

	int length;
	length = strlen(word);
	
	/*If the word ends in s, remove the s by charging the word. If the word ends in sses, remove the es by chaning to word. if the word ends in ed, remove the ed by changing the word. If the word ends in ing, remove the ing. If the word ends in nning, remove the ning.*/
	if (word[length - 1] == 's')
	{
		if (word[length - 4] == 's' && word[length - 3] == 's' && word[length - 2] == 'e')
		{
			word[length - 2] = '\0';
		}
		else
			word[length - 1] = '\0';
	}
	else if (word[length - 2] == 'e' && word[length - 1] == 'd')
	{
		word[length - 2] = '\0';
	}
	else if (word[length - 3] == 'i' && word[length - 2] == 'n' && word[length - 1] == 'g')
	{
		if (word[length - 5] == 'n' && word[length - 4] == 'n')
		{
			word[length - 4] = '\0';
		}
		else
			word[length - 3] = '\0';
	}
	/*prints out what the word is after it has been stemmed.*/
	printf("Stemmed word: %s\n", word);

	/*Returns the function main's value to 0 so that the ccmpiler will work.*/
	return 0;
}
