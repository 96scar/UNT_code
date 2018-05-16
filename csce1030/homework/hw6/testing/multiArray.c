#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int main(void)
{
	double **myArray;
	int i, j;

	srand(time(NULL));

	myArray = calloc(SIZE, sizeof(double *));
	for (i = 0; i < SIZE; i++)
	{
		myArray[i] = calloc(SIZE, sizeof(double));
	}

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			myArray[i][j] = rand() % (i + 1) + 1;
			printf("[%d][%d]=%.2lf\n", i, j, myArray[i][j]);
		}
	}

	/* general rule: for each calloc(), there should be exactly 1 corresponding free() */
	for (i = 0; i < SIZE; i++)
	{
		free(myArray[i]);
	}
	free(myArray);

	for (i = 0; i < 20; i++)
	{
		printf("%d\n", rand() % 5);
	}

	return 0;
}
