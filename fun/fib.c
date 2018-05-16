#include <stdio.h>
#include <stdlib.h>

int fib(int n);

int main(int argc, char *argv[])
{
	int i, fibnum, final;
	
	printf("argc: %d\n", argc);
	
	if(argc==1 || argc>2)
	{
		printf("usage: ./fib number\n");
		exit(1);
	}
	
	final = atoi(argv[1]);
	
	for(i=0; i<final; i++)
	{
		fibnum = fib(i);
		printf("fib[%d]: %d\n", i, fibnum);
	}
	
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