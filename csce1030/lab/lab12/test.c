#include <stdio.h>

int main()
{
	int num;
	do
	{
		printf("Enter a positive number: ");
		scanf("%d", &num);
	}while(num < 0);

	int i, factorial;
	
	for (i=1; i<=num; i++)
		factorial = factorial*i;
	
	printf("The answer is : %d", factorial);
	
	return 0;
}
