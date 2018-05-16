// Scarlett Jones
// Lab 2 assignment

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

//void count(int*, char*, int*, int*);

int main()
{
	char *words[SIZE];
	int i, number, tsum, asum;
	i = 0;
	number = 0;
	tsum = 0;
	asum = 0;
	
	// Initializes *words to NULL
	for(i = 0; i < SIZE; i++)
	   words[i] = 0;

	for(i = 0; i < SIZE; i++)
	{
		// Creates space for each word
		words[i] = (char *) malloc(number * sizeof(char*));

		scanf("%d %p", &number, words);
		
//		if(**words = "t")
//		   tsum += 1;

//		count(&number, words, tsum, asum);

	}

	return 0;
}

//void count(int *num, char *letters int *sumt, int *suma)
//{

//	return;
//}
