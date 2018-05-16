#include <stdio.h>

int main()
{
	double x[10];
	int i;

	for(i=1; i<10; i++)
	{
		x[i] = x[i] * x[i-1] + x[i];
	}
	return 0;
}
