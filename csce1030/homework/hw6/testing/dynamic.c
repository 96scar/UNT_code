#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void assignShips

int main()
{
	int size, **board, i, j;

	printf("Board Size: ");
	scanf("%d", &size);
	printf("\n");

	board = calloc(size, sizeof(int*));
	for(i = 0; i < size; i++)
	{
		board[i] = calloc(size, sizeof(int));
	}
	
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	
	free(board);

//	srand(time(NULL));
	
//	board[i][j] = "AB"[random () % 2]; 
//	for(i = 0; i < size; i++)
//	{
//		board[i] = malloc(size * sizeof(int));
//	}
	
//	for(i = 0; i < size; i++)
//	{
//		for(j = 0; j < size; j++)
//		{
//			printf("%d ", board[i][j]);
//		}
//		printf("\n");
//	}

	return 0;
}

void assignShips(int **board, int size, ship)
{
	int i;
	
	for(i=0; i<size; ++i)
	{
		for(j=0; j<size; ++j)
		{
			board[i][j] = rand() %19 -9;
		}
	}	

	return;
}
