#include <stdio.h>

int fib(int n);

int main()
{
	int fibnum = fib(10);
	printf("%d\n",fibnum);
	
	return 0;
}

int fib(int n)
{
	if(n<=2)
		return 1;
	else 
		return fib(n-1)+fib(n-2);
}
