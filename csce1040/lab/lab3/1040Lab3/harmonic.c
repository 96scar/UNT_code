#include <stdio.h>
#include <stdlib.h>

//prototype
float harmonic(int x, int base);

int main()
{
	int base = 0; // recursive base case
	float sum = 0; // sum of hte generated series

	//prompt the user for base case
	printf("Enter the number of terms to generate: ");
	scanf("%d", &base);
	//call the harmonic function
	sum = harmonic(1, base);
	//print the sum of the series
	printf("Sum: %f\n", sum);

	return 0;
}

//function to determine the harmoic term
float harmonic(int x, int base)
{
	float sum = 0;

	if(x == base) // base case
		printf("1/%d\n", x);
	else 
	{
		//recursive call
		printf("1/%d + ", x);
		sum = harmonic(x+1, base);
	}	
	
	//return the sum of the series
	return (sum+(1.0/x));
}
