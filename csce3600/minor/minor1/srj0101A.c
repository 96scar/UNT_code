/*
Name: Scarlett Jones
Course Section: CSCE 3600.006
Date Completed: January 24, 2016
Due Date: February 1, 2016
Description: This C program asks the user to input an ASCII character and then prints out the decimal, hexadecimal, and binary values.
*/

#include <stdio.h> /* standard library */

void convert(int decimal); /* decimal to binary function */

int main()
{
	char input; /* The input variable is a character that the user enters */
	int decimal; /* The decimal variable is the integer value of input that the user enters */

	printf("\n\n");
	printf("Enter an ASCII character: "); /* asks the user to input an ascii character */
	scanf("%c", &input); /* takes in a character */
	
	printf("\n\n");
	printf("The ASCII value of %c is: %d (dec) -- %X (hex) -- ", input, input, input);
	/* the decimal value of a character is the ascii value, and the hexadecimal value with uppercase letters. */
	
	decimal = input; /* sets decimal equal to input */
	convert(decimal); /* sends decimal into the convert function */
	
	printf("\n");
	
	return 0; /* returns 0 to the main function */
}

/*
Name: Convert
Description: takes in a decimal value and converts it into a binary value
Parameters: int decimal
Returns: nothing, it's void
*/
void convert(int decimal)
{
	int quotient, dividend, divisor, remainder, i; 
	/* quotient is the answer to a division,
		dividend is the number dividing into,
		divisor is the number dividing by,
		remainder is the number left over from division,
		i is the increment value used to put numbers into an array */
	int bi[8] = {0}; /* bi is an array of 8 numbers that is the binary value. it is initialized to all 0 */
	quotient = 1; /* initialize to 1 so the while loop starts */
	dividend = decimal; /* decimal is the number dividing into */
	divisor = 2; /* we are dividing by 2 */
	remainder = 0; /* initialize remainder as 0 to be safe */

	i = 7; /* start increment at 7 so the binary number is in the correct order */
	while(quotient != 0) /* loop continues until quotient is 0 */
	{
		quotient = dividend/divisor; /* the quotient is now equal to the dividend divided by the divisor */
		remainder = dividend - (quotient*divisor); /* the remainder is the dividend minus the quotient times the divisor */
		dividend = quotient; /* the new number to divide into is the quotient */
		
		bi[i] = remainder; /* put the remainder number in the position at i */
		
		i--; /* decrement i to put the next number in front of the current number */
	}
	
	for(i = 0; i < 8; i++) /* this for loop starts at the beginning of the bi array and prints out the binary number in the correct order */
	{
		printf("%d", bi[i]); /* prints out the number in bi at i */
	}
	
	printf(" (bin)"); /* prints out bin to tell you the value */
	printf("\n\n");
	return;
}