/*
Author: Scarlett Jones ( ScarlettJones@my.unt.edu)
Date: 2/10/15
Instructor: Keathly
*/

/*preprocessor directive, include standard library*/
#include <stdio.h>

/*function prototype*/
int liar(int n);

/*main function, returns 0*/
int main()
{
	/*declars count an int (count is the number to generate sequence with), i is set to 1 for the while loop later*/
	int count;
	int i = 1;

	/*asks for and accepts input for a number to generate sequence with*/
	printf("\nNumber to generate Liar-Liar sequence with: ");
	scanf("%d", &count);
	
	/*hardcoded numbers*/
	printf("\n123456789012345678901234567890\n");

	/*ptints out the liar-liar sequence is from 1 to count*/
	while(i <= count)
	{
		/*If count is less than or equal to 23 and greater than or equal to 1, print out the liar sequence. Otherwise, print out that the number is out of range and to try again.*/
		if(count <= 23 && count >= 1)
		{
			printf("Liar-Liar(%2d) = %11d\n", i, liar(i));
			i++;
		}
		else
		{
			printf("\nOut of range, try again\n\n");
			i = count + 1;
		}
	}
	
	/*for formatting purposes. prints newline at end of code*/
	printf("\n");

	/*returns main to zero*/
	return 0;
}

/*
Function: liar
Takes: an int called n
Returns: either -1 or generate liar sequence, or says it can't go over 23
Description: generates the liar-liar sequence 
*/
int liar(int n)
{
	if(n<=2 && n>=1)
	{
		return -1;
	}
	else if(n <= 23)
	{
		return (2*(liar(n-1)+liar(n-2)));
	}
	else
	{
		;
	}
}
