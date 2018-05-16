#include <stdio.h>
#include <stdlib.h>

#define HIGHEST 1000
#define LOWEST 1

int main()
{
	unsigned int number;

	srand((unsigned int)time(NULL));

	number = random()%(HIGHEST - LOWEST + 1) + LOWEST;
	printf("random number: %d\n", number);
	number = random()%(HIGHEST - LOWEST + 1) + LOWEST;
	printf("random number: %d\n", number);
	number = random()%(HIGHEST - LOWEST + 1) + LOWEST;
	printf("random number: %d\n", number);

	return 0;
}
