/*
Name: Scarlett Jones
EUID: srj0101
Email: ScarlettJones@my.unt.edu
Due Date: 2/8/16
Description: This program parses command line arguments and builds, prints, 
and executes a cat command using pipes and redirection.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i, j;
	char cmd[96];
	char flag;
	
	system("clear");

	printf("\n");
	printf("argc: %d", argc);
	printf("\n");
	for(i = 0; i < argc; i++)
	{
		printf("argc[%d]: %s", i, argv[i]);
		printf("\n");
	}

	
	/* can only do this for loop if there is more than one argc */
	j = 1;
	for(i = 1; i < argc; i++)
	{
		switch(argv[i][j])
		{
			case 'i':
			printf("\n-i flag: input redirection\n");
			break;
				
			case 'g': 
			printf("\n-g flag: grep\n");
			break;

			case 's': 
			printf("\n-s flag: sort\n");
			break;
	
			case 'o': 
			printf("\n-o flag: output redirection\n");
			break;

			default: 
			printf("\nUnknown flag: -%c\n", argv[i][j]);
			printf("\nProgram terminated...\n");
			exit(1);
			break;
		}
	}
	

	
	switch(argc)
	{
		case 1:  /*the only argument is the executable file */
		printf("\n%s\n", argv[0]);
		break;
		
		case 2:  /*1 command to execute */
		printf("\ncmd: ");
		/* system("cat < %s"); */
		break;
		
		case 3:   /*2 commands to execute */
		printf("\ncmd: ");
		/* system("cat < %s"); */
		break;
		
		case 4: /* 3 commands to execute */
		printf("\ncmd: ");
		/* system("cat < %s"); */
		break;
		
		case 5: /* 4 commands to execute */
		printf("\ncmd: ");
		/* system("cat < %s"); */
		break;
		
		default:  /*too many arguments */
		printf("\nToo many arguments\n");
		break;
	}	


	return 0;
}