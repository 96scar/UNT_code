/*
Name: Scarlett Jones
Lab 5: Bit minipulations
*/

/*Preprocessor directive*/
#include <stdio.h>
#include <string.h>

void encrypt(char *second, char *third);
void decrypt(char *second, char *third);

/*command line arguments in main*/
int main(int argc, char *argv[])
{
	/*Check to see if command line arguments is correct amount*/
	if(argc < 4)
	{
		printf("\nIncorrect amount of arguments.\n\n");
	}
	else if(argc > 4)
	{
		printf("\nIncorrect amount of arguments.\n\n");
	}
	else
	{
		/*Check to see if correct words for command line arguments were used*/
		if((strcmp(argv[1], "encrypt") == 0))
		{

			/*call the encrypt function*/
			encrypt(argv[2], argv[3]);
		}
		else if((strcmp(argv[1], "decrypt") == 0))
		{
		
			/*call the decrypt function*/
			decrypt(argv[2], argv[3]);
		} 
		else
		{
			printf("\nSecond argument incorrect.\n\n");
		}
	}

	return 0;
}

/*
Function: encrypt
parameters: the second and third index of the argv
Returns: nothing
Description: encrypts the text file entered in (*second) and puts it in another text file (*third)
*/
void encrypt(char *second, char *third)
{
	FILE *fp;
	FILE *efp;

	char tempc;
	int tempi;
	
	fp = fopen(second, "r");
	efp = fopen(third, "a");

	while(fscanf(fp, "%c", &tempc) != EOF)
	{
		tempi = tempc;

		tempi = ~tempi;
	
		fprintf(efp, "%d ", tempi);
	}

	
	fclose(fp);

	fclose(efp);

	return;
}

/*
Function: decrypt
parameters: the second and third index of the argv
returns: nothing
description: decrypts the text file from the (*third) and puts it in other file (*second)
*/
void decrypt(char *second, char *third)
{
	FILE *fp;
	FILE *dfp;

	int tempi;
	char tempc;

	fp = fopen(third, "r");
	dfp = fopen(second, "a");

	while(fscanf(fp, "%d", &tempi) != EOF)
	{
		tempi = ~tempi;
	
		tempc = tempi;
	
		fprintf(dfp, "%c", tempc);
	}

	fclose(fp);
	
	fclose(dfp);

	return;
}
