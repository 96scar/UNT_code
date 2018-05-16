// Scarlett Jones
// Lab practice

#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *); // prototype

int main()
{
	int a = 1, b = 2;

	printf("Before swap: a=%d b=%d\n", a, b);
	swap(&a, &b);
	printf(" After swap: a=%d b=%d\n", a, b);

	return 0;
}

void swap(int *x, int *y) // function header
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
	printf("Inside swap: x=%d y=%d\n", *x, *y);
	
	return;
}
