/*
Author: Scarlett Jones
Date: 12/6/14
Instructor: Mark Thompson
Purpose: the classic game of battleship for one player only. this is split into three files.
*/
#include "prgm.h"

int main()
{
	int **board;		/* pointer to two-dimensional array for game board */
        int i;			/* index used in loop counters, specifically outer loop */
        int j;			/* index used in loop counters, specifically inner loop */
        char level[10] = "";	/* user input for difficulty of game */
        int maxTries;		/* number of shots available to user based on difficulty level */
        int validLoc = 0;	/* boolean indicating whether or not valid location found to assign ship */
	int hidden = 0;
	int reveal = 1;
	

	  printStudInfo();		/* display student information */

        printf("\n                Welcome to Battleship!                    \n\n");

	  /* prompt user to enter difficulty level of game */
        while ((strcmp(level, "easy")) && (strcmp(level, "normal")) && (strcmp(level, "hard")))
        {
                printf("Enter difficulty level of game (easy, normal, hard): ");
                scanf("%s", level);
                if ((strcmp(level, "easy")) && (strcmp(level, "normal")) && (strcmp(level, "hard")))
                {
                        printf("Invalid input. Response is case sensitive. Please select again.\n");
                }
        }

	  /* assign number of shots available based on difficulty level chosen */
        if (!strcmp(level, "easy"))
        {
                maxTries = 30;
        }
        else if (!strcmp(level, "normal"))
        {
                maxTries = 25;
        }
        else /* strcmp(level, "hard")) */
        {
                maxTries = 20;
        }

        printIntro(maxTries);	/* call function to print introductory message, including number of shots */

        printf("\t\tInitializing board... ");

        /* allocate memory for and initialize two-dimensional board */
        board = calloc(SIZE, sizeof(int *));

        for(i = 0; i < SIZE; i++)
        {
                board[i] = calloc(SIZE, sizeof(int));
        }

        /* now place battleship on board */
        printf("now let's begin!\n\n");

	  /* repeatedly attempt to assign battleship until successful */
        while (!validLoc)
        {
                validLoc = assignShip(board, 4);
        }

        validLoc = 0;	/* re-initialize valid location to false for aircraft carrier */

	  /* repeatedly attempt to assign aircraft carrier until successful */
        while (!validLoc)
        {
                validLoc = assignShip(board, 5);
        }

        dispGrid(board, hidden);  /* call function to display board with ships assigned */	

	
	struct torpedo shot;
	shot.ahits = 0;
	shot.bhits = 0;

	i = 1;
	int result;

	while(maxTries > 0)
	{
		printf("\tEnter position to fire torpedo #%d(e.g., B7): ", i);
		shot.row = getchar();
		scanf("%c", &shot.row);
		scanf("%d", &shot.column);

		if(shot.row >= 'A' && shot.row <= 'J' && shot.column >= 1 && shot.column <= 10)
		{
			shot.row -= 'A';
			shot.column -= 1;
			result = status(board, &shot, maxTries);
			dispGrid(board, hidden);
		}
		else if(shot.row >= 'a' && shot.row <= 'j' && shot.column >= 1 && shot.column <= 10)
		{
			shot.row -= 'a';
			shot.column -= 1;
			result = status(board, &shot, maxTries);
			dispGrid(board, hidden);
		}
		else
		{
			printf("\n\tTorpedo cannot be fired here.\n");
			dispGrid(board, hidden);
			i--;
			maxTries++;
		}

		switch(result)
		{
			case 0: /*won game*/
				maxTries = 0;
				break;
			case 1: /*lost game*/
				maxTries = 0;
				break;
			default: /*game still going on*/
				 break;
		}
	
		i++;
		maxTries--;
	}
	switch(result)
	{
		case 0: /*won game*/
			printf("\n\tCongratulations! You sank both ships in %d tries!\n", i - 1);
			dispGrid(board, reveal);
			break;
		case 1: /*lost game*/
			printf("\n\tSorry, but you were not able to sink my ships! Tough break...\n");
			dispGrid(board, reveal);
			break;
		default: /*shouldn't get this case*/
			 ;
	}
			
	return 0;
}
