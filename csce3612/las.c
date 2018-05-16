/*
	Scarlett Jones
	find the largest and smallest of n non-zero positive integers.
	user will input value of n followed by each of the n values.
*/

#include <stdio.h>

int main()
{
	int first, n, number, high, low; // create variables needed
	
	first=0; // move value 0 into first
	n=0; // move value 0 into n

	printf("How many numbers? "); // ask for how many numbers
	scanf("%d", &n); // move value given into n
	
	while(n != 0) //repeat until n is not equal to zero
	{
		printf("\nEnter a number: "); // ask for a number to input
		scanf("%d", &number); // move value given into number
		
		if (first==0) // if it is the first time through the loop
		{
			low = number; // the lowest number is initially set to the first number given
			high = number; // the higher number is initially set to the first number given
			first = 1; // it is no longer the first time going through the loop anymore
		}
		
		if(number > high) // if the number given is greater than the current highest value
		{
			high = number; // change high to number
		}
		
		if(number < low) // if the number given is less than the curent lowest value
		{
			low = number; // change low to number
		}
		
		n = n - 1; // decrement n so we know which number we are on
	}
	
	printf("High: %d\n", high); // output the high value to stdout
	printf("Low: %d\n", low); // output the low value to stdout
	
	return 0;
}