#include <stdio.h>

int fact(int n);

int main()
{
	int factorial = fact(10);
	printf("%d\n",factorial);

	return 0;
}

int fact(int n)
{
	if(n==0)
		return 1;
	else
		return (n*fact(n-1));
}
