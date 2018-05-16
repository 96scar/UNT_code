#include <stdio.h>
#include <stdlib.h>

int fib(int n);

int main()
{
	int fibnum;
	
	printf("Enter an n value: ");
	scanf("%d", &fibnum);

	fibnum = fib(fibnum);

	printf("%d\n",fibnum);
	
	return 0;
}

int fib(int n)
{
	if(n==0)//IF: branch on not equal to ELIF
		return 0;
	else if(n==1) //ELIF: branch on not equal to ELIF2
		return 1;
	else if(n > 1) //ELIF2: slti and branch on equal to ELSE
		return fib(n-1)+fib(n-2);
	else
	{
		printf("n must be a positive integer.");
		exit(1);
	}
}
