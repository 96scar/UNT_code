/*
Name: Scarlett Jones
EUID: srj0101
ID: 11026836
Email: ScarlettJones@my.unt.edu
Course: CSCE 3600.001
Teacher: Mark Thompson
Date: 3/1/16
Description: I was provided with code that allows input
from a sentence that is stored into an array of characters.
Then, a thread is created for each character. I used mutex
locks to print out the characters in the correct order and
to capitalize each letter that has an odd index.
*/

#include <stdio.h>
#include <string.h>
#include <pthread.h> /* make sure to use the -lpthread flag */

#define SIZE 50
pthread_mutex_t mulo = PTHREAD_MUTEX_INITIALIZER; /*declare a mutex lock*/

char sentence[2000];
int  ind = 0;

char convertUppercase(char lower)
{
	//Converts lowercase un uppercase
	if ((lower > 96) && (lower < 123))
	{
		return (lower - 32);
	}
	else
	{
		return lower;
	}
}

void printChar()
{
	//prints the converted sentence
	printf("The new sentence is [%d]: \t%c\n", ind, sentence[ind]);
	
	ind++;
}

void *convertMessage(void *ptr)
{
	
	
	// Function that each threads initiates its execution
	char aux;
	pthread_mutex_lock(&mulo); /* lock the current thread so that the characters will be checked for 
								 an odd index in order*/	

	
	if (ind % 2)
	{
		sentence[ind] = convertUppercase(sentence[ind]);
	}
	
	printChar();
	pthread_mutex_unlock(&mulo); /* unlock the current thread once it has been properly converted or left alone */
	return 0;
}

int main()
{
	int i;
	char buffer[SIZE];
	char *p;
	pthread_t ts[SIZE]; // define up to 50 threads
	pthread_mutex_init(&mulo, NULL); /* initialize the mutex variable mulo */
	
	
	printf("Please enter a phrase (less than 50 characters): ");

	if (fgets(buffer, sizeof(buffer), stdin) != NULL)
	{
		if ((p = strchr(buffer, '\n')) != NULL)
		{
			*p = '\0';
		}
	}

	strcpy(sentence, buffer); // copy string to char array
	
	printf("The original sentence is: \t %s\n", sentence);

	// create one thread for each character on the input word
	for(i = 0; i < strlen(buffer) + 1; ++i)
	{
		pthread_create(&ts[i], NULL, convertMessage, NULL);
	}
	
	// we wait until all threads finish execution
	for(i = 0; i < strlen(buffer); i++)
	{
		pthread_join(ts[i], NULL);
	}
	
	pthread_mutex_destroy(&mulo); /* destroy the mutex variable mulo because we are done with the program */
	
	printf("\n");
	
	return 0;
}
