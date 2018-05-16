#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, j, rows;
	
	printf("\nEnter number of rows: ");
	scanf("%d", &rows);
	
	if(rows <= 0)
	{
		printf("\nCan't have a negative number of rows.\n");
		exit(1);
	}
	else
	{
		for(i=1; i<=rows; i++)
		{
			printf("%d", rows);
		}
	}
	
	return 0;
}