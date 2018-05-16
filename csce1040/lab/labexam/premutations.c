/*
Name: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 3/24/15
Teacher: Keathly
Lab Exam: permutations
I tried to read in one word, send that to the permute function and then print out the permutations of each.
However, I could not correctly read in all the words, and I keep getting a segmentation fault.
I want to use arguments to main to get at least some of the lab done.
I still had difficulties permuting the words all the way and getting rid of duplicates.
*/

#include <stdio.h> // always need this
#include <string.h> // need this to copy strings

void permute(char *w); // function prototype

int main(int argc, char *argv[]) //using command line arguments for the words to permute
{
	int i=0;

	printf("Number of Words to permute: %d\n", argc - 1);

	for(i = 1; i < argc; i++)
	{
		permute(argv[i]);
	}

	return 0;
}

/*
Function: permute
parameters: the word to be permuted
returns: nothing
description: prints out the permutations of the word
*/
void permute(char *w)
{
	int i, j; //position in the word and the length of the word
	char l1, l2; // temporary letter to move around
	i = 0; // array of characters starts at 0
	j = strlen(w) - 1; //subtracted one to account for the null character

	while(i <= j) // goes until i is less than or equal to the number of letters in the word
	{
		l1 = w[i]; // copies the ith letter of the word to the variable l1
		l2 = w[j]; // copies the jth letter of the word to the variable l2

		w[j] = l1; // copies variable l1 to the jth letter of the word
		w[i] = l2; // copies variable l2 to the ith letter of the word

		printf("%s ", w);

		i++; //increments i
	}

	printf("\n\n");

	return;
}
