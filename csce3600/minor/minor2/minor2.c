/*
Name: Scarlett Jones
EUID: srj0101
Email: ScarlettJones@my.unt.edu
Due Date: 2/8/16
Date Finished: 2/5/16
Description: This program parses command line arguments and builds, prints, 
and executes a cat command using pipes and redirection.
*/

#include <stdio.h>
#include <stdlib.h> /* need this to use exit(1) */
#include <string.h> /* need this to use string functions */

void callPrintArgs(int argc, char *argv[]);

int main(int argc,  char **argv)
{	
	callPrintArgs(argc, argv);

	return 0;
}

void callPrintArgs(int argc, char **argv)
{ 	
	int i; /* i is used for for loops*/
	char buffer[80]; /* buffer is what the string is copied to for the whole command */
 
	/* Makes sure there are more than 1 arguments, otherwise exits*/
	if(argc > 1)
	{
		;
	}
	else /* print out the executable name */
	{
		printf("\n%s\n\n", argv[0]+2);
		exit(1);
	}  
	
	for(i = 0; i < 80; i++)
    {
		buffer[i] = '\0'; /* sets buffer string characters all to null */
	}

	/* checks to see if the first flag is i, because it must be i first.
		if not, the program ends	*/
	if(argv[1][1] == 'i')
	{
		;
	}
	else
	{
		printf("\nThe first flag must be -i. Program terminated...\n");
		exit(1);
	}
	
	/* Because we know i must be the flag by now, I copy the command
		cat < and the argument to the buffer*/
	strcpy(buffer, "cat < ");
	
	/* strncpy allows you to copy part of a string with a start and end position*/
	strncpy(buffer+(strlen(buffer)), argv[1]+2, strlen(buffer)+strlen(argv[1])-2);
		
	for( i = 2; i < argc; i++ ) /* the rest of the optional arguments */
    {
		switch(argv[i][1]) /* check the 1 index for the command letter */
		{
			case 'g': /* grep command */
			strcpy(buffer+(strlen(buffer)), " | grep "); 
			break;
			
			case 's': /* sort command */
			strcpy(buffer+(strlen(buffer)), " | sort ");
			break;
			
			case 'o': /* output file */
			strcpy(buffer+(strlen(buffer)), "> ");
			break;
			
			default: /* incorrect flag */
			printf("\nUnknown flag: -%c\n", argv[i][1]);
			printf("\nProgram terminated...\n");
			exit(1);			
			break;
		}
		/* copy the command to the buffer without the first 2 characters */
		strncpy(buffer+(strlen(buffer)), argv[i]+2, strlen(buffer)+strlen(argv[i])-2);
    }
    
	printf("\ncmd: %s\n\n", buffer); /* prints out the buffer words */
    system(buffer); /* calls buffer in system */

	return;
}
