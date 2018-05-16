#include <stdio.h>
#include <time.h>

#define SIZE 10

int main()
{
	srand(time(NULL));
	
	int orientation, row, column, ship;	
	orientation = rand()%2;
	row = rand()%SIZE;
	column = rand()%SIZE;
	ship = rand()%2;

	if(orientation == 0)
		printf("\nHorizontal\n\n");
	else if(orientation == 1)
		printf("\nVertical\n\n");
	else
		printf("Neither");

	int i, j;
	i = 0;
	j = 0;

	printf("\nRow starts at %d\n\n", row);

	printf("\nColumn starts at %d\n\n", column);

	if(ship == 0)
		printf("\nAAAAA\n\n");
	else if(ship == 1)
		printf("\nBBBB\n\n");
	else
		;


	return 0;
}
