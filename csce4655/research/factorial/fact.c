#include <stdio.h>

unsigned long long int factorial(unsigned long long int num);

int main()
{
	unsigned long long int num;
	unsigned long long int result;
	
	printf("Enter a number to find its Factorial: ");
	scanf("%llu", &num);
	if(num < 0)
	{
		printf("Factorial of a negatie number not possible\n");
	}
	else
	{
		result = factorial(num);
		printf("The Factorial of %llu is %llu.\n", num, result);
	}
	return 0;
}

unsigned long long int factorial(unsigned long long int num)
{
	if(num==0 || num==1)
	{
		return 1;
	}
	else
	{
		return(num*factorial(num-1));
	}
}