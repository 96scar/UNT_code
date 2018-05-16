/*
Author: Scarlett Jones
Date: 12/6/14
Instructor: Mark Thompson
Purpose: the classic game of battleship for one player only. this is split into three files.
*/

/*local header file to include in this file*/
#include "prgm.h"

/*other functions defined*/
/*
============================================================================
 Function    : printStudInfo
 Parameters  : none
 Return      : none
 Description : This function prints the student header information.		   
============================================================================
 */
void printStudInfo(void)
{
	/* display student information */
  	printf("+----------------------------------------------+\n");
	printf("|       Computer Science and Engineering       |\n");
  	printf("|        CSCE 1030 - Computer Science I        |\n");
  	printf("| Scarlett Jones  srj0101 srj0101@my.unt.edu   |\n");
  	printf("+----------------------------------------------+\n\n");
}

/*
============================================================================
 Function    : printIntro
 Parameters  : integer representing number of shot available to player based
		   on level of difficulty
 Return      : none
 Description : This function prints an introductory message to the user, and
		   gives details about the game including the number of attempts
		   the user gets based on their chosen level of difficulty.  
============================================================================
*/
void printIntro(int maxTries)
{
        printf("\n");
        printf("+------------------------------------------------------------+\n");
        printf("| The computer program will randomly assign an aircraft car- |\n");
        printf("| rier and a battleship, that are oriented either vertically |\n");
        printf("| or horizontally, to the board. You will have %d chances to |\n", maxTries);
        printf("| sink both the computer's aircraft carrier and battleship!! |\n");
        printf("| You'll play on a %d x %d board, where the aircraft carrier |\n", SIZE, SIZE);
        printf("| will have a length of 5 units and the battleship will have |\n");
        printf("| a length of 4 units.                                       |\n");
        printf("+------------------------------------------------------------+\n\n");
}

/*
============================================================================
 Function    : printGridRow
 Parameters  : integer representing row of the board
 Return      : none
 Description : This function prints the corresponding letter for the integer
   row.  
============================================================================
 */
void printGridRow(int i)
{
	  /* based on row integer passed, print out corresponding row letter of board */
        switch (i)
        {
        case 0: printf("\t\tA | ");
                break;
        case 1: printf("\t\tB | ");
                break;
        case 2: printf("\t\tC | ");
                break;
        case 3: printf("\t\tD | ");
                break;
        case 4: printf("\t\tE | ");
                break;
        case 5: printf("\t\tF | ");
                break;
        case 6: printf("\t\tG | ");
                break;
        case 7: printf("\t\tH | ");
                break;
        case 8: printf("\t\tI | ");
                break;
        case 9: printf("\t\tJ | ");
                break;
        default:printf("Unknown grid row value: %d. Program terminating.\n", i);
                exit(1);
        }
}

/*
============================================================================
 Function    : dispGrid
 Parameters  : pointer to two-dimensional array representing game board
 Return      : none
 Description : This function prints the game board, including row and column
   headers and assigned ships.  
============================================================================
 */
void dispGrid(int **board, int view)
{
        int i;	/* index used in outer loop counter */
        int j;	/* index used in inner loop counter */

	if(view == 0) /*hidden*/
	{
        	printf("\t\t    1 2 3 4 5 6 7 8 9 10 \n");
        	printf("\t\t  +---------------------+\n");
	
		/* loop through two-dimensional array to print out corresponding items */
	        for (i = 0; i < SIZE; i++)
	        {
	                printGridRow(i); /* print grid row and left vertical column of board */
	
	                for (j = 0; j < SIZE; j++)
	                {
	                        switch (board[i][j])
	                        {
	                        case 0:   /* print blank space for open/unassigned location */
	                                  printf("  ");
	                                  break;
				case 4:   /* print blank space for assigned battleship */
				 	  printf("  ");
	  				  break;
	                        case 5:   /* print blank space for assigned aircraft carrier */
	  				  printf("  ");
				  	  break;
				case 'X': /*print 'X' for a hit*/
					  printf("X ");
					  break;
				case 'O': /*print 'O' for a miss*/
					  printf("O ");
					  break;
	                        default:/* should never get here, but handle error case by terminating program gracefully */
	                                printf("Unknown value for board[%d][%d] : %d. Terminating program.\n", i, j, board[i][j]);
	                                exit(1);
	                        }
	                }

	                printf("|\n");  /* print right vertical column of board */
		}
		
	        printf("\t\t  +---------------------+\n\n");
	}	
	else if(view == 1) /*reveal*/
	{
        	printf("\t\t    1 2 3 4 5 6 7 8 9 10 \n");
        	printf("\t\t  +---------------------+\n");
	
		/* loop through two-dimensional array to print out corresponding items */
	        for (i = 0; i < SIZE; i++)
	        {
	                printGridRow(i); /* print grid row and left vertical column of board */
	
	                for (j = 0; j < SIZE; j++)
	                {
	                        switch (board[i][j])
	                        {
	                        case 0:   /* print blank space for open/unassigned location */
	                                  printf("  ");
	                                  break;
				case 4:   /* print 'B' for assigned battleship */
				 	  printf("B ");
	  				  break;
	                        case 5:   /* print 'A' for assigned aircraft carrier */
	  				  printf("A ");
				  	  break;
				case 'X': /*print 'X' for a hit*/
					  printf("X ");
					  break;
				case 'O': /*print 'O' for a miss*/
					  printf("O ");
					  break;
	                        default:/* should never get here, but handle error case by terminating program gracefully */
	                                printf("Unknown value for board[%d][%d] : %d. Terminating program.\n", i, j, board[i][j]);
	                                exit(1);
	                        }
	                }

	                printf("|\n");  /* print right vertical column of board */
	        }

	        printf("\t\t  +---------------------+\n\n");
	}
}

/*
============================================================================
 Function    : assignShip
 Parameters  : pointer to two-dimensional array representing game board, and
		   integer representing ship type, based on the length
 Return      : integer, 0 if ship not assigned or 1 if ship successfully as-
		   signed
 Description : This function attempts to randomly assign the requested ship,
		   either an aircraft carrier or a battleship, to the board.
============================================================================
 */
int assignShip(int **board, int shipType)
{
        int valid = 0;  /* use 0 for false (not assigned); otherwise 1 means assigned successfully */
        int i;		/* index used in loop counter as row */
  	int j;		/* index used in loop counter as column */
        int vertical;	/* randomly generated ship orientation */
        int shipRowPos;	/* randomly generated row position of ship */
        int shipColPos;	/* randomly generated column position of ship */

        srand(time(NULL));

        vertical   = rand() % 2;	/* randomly generated ship orientation: 1 = vertical, 0 = horizontal */

        shipRowPos = rand() % 10;	/* randomly generated ship row position */ 
        shipColPos = rand() % 10;	/* randomly generated ship column position */

        if (vertical) /* vertical orientation */
        {
		    /* check to see if vertical ship can be placed on board at this location */
                if ((shipRowPos + shipType) < SIZE)
                {
                        /* need check if ship already in this position first */
                        for (i = shipRowPos; i < (shipRowPos + shipType); i++)
                        {
                                if (board[i][shipColPos] != 0)
                                {
                                        /* ship already here, return valid = 0 */
                                        return valid;
                                }
                        }

                        /* ship able to fit vertically on board */
                        valid = 1;

                        /* need assign ship's position on board */
                        for (i = shipRowPos; i < (shipRowPos + shipType); i++)
                        {
                                board[i][shipColPos] = shipType;
                        }
                }
        }
        else /* horizontal orientation */
        {
		    /* check to see if horizontal ship can be placed on board at this location */
                if ((shipColPos + shipType) < SIZE)
                {
                        /* need check if ship already in this position first */
                        for (j = shipColPos; j < (shipColPos + shipType); j++)
                        {
                                if (board[shipRowPos][j] != 0)
                                {
                                        /* ship already here */
                                        return valid;
                                }
                        }

                        /* ship able to fit vertically on board */
                        valid = 1;

                        /* need assign ship's position on board */
                        for (j = shipColPos; j < (shipColPos + shipType); j++)
                        {
                                board[shipRowPos][j] = shipType;
                        }
                }
        }

        return valid;
}

/*
============================================================================
 Function    : status
 Parameters  : pointer to two-dimensional array representing game board, and
	       a pointer to a variable of torpeo struct
 Return      : integer, 0 if the game is won or 1 if the game is lost
 Description : This function checks to see if the shot fired by the user hit
	       a battleship, an aircraft carrier, a duplicate shot, or a miss.
	       Once this is checked, it updates the board and updates the 
	       number of hits on either ship and displays a message if a ship
	       was sunk.
============================================================================
*/
int status(int **board, struct torpedo *shot, int maxTries)
{
	int win, lose, playing, a, b;
	win = 0;
	lose = 1;
	playing = 2;
	a = shot->ahits;
	b = shot->bhits;

	if(board[shot->row][shot->column] == 5)
	{
		printf("\t\t\t\a\a\aHIT!!!\n");
		board[shot->row][shot->column] = 'X';
		a++;
		shot->ahits += 1;
	
		if(a == 5)
		{
			printf("\nYou sunk my aircraft carrier!\n");
		}
		else /*print nothing*/
			;

	}
	else if(board[shot->row][shot->column] == 4)
	{
		printf("\t\t\t\a\a\aHIT!!!\n");
		board[shot->row][shot->column] = 'X';
		b++;
		shot->bhits += 1;

		if(b == 4)
		{
			printf("\n\t\a\a\a\aYou sunk my battleship!\n");
		}
		else /*print nothing*/
			;
	}
	else if(board[shot->row][shot->column] == 'X')
	{
		printf("\t\t\t\aWasted shot!\n");
	}
	else if(board[shot->row][shot->column] == 'O')
	{
		printf("\t\t\t\aWasted shot!\n");
	}
	else
	{
		printf("\t\t\t\aMiss...\n");
		board[shot->row][shot->column] = 'O';
	}

		if(a == 5)
		{
			if(shot->ahits == 5 && shot->bhits == 4)
			{
				return win;
			}
			else if(maxTries - 1 == 0 && (shot->ahits < 5 || shot->bhits < 4))
			{
				return lose;
			}
			else
			{
				return playing;
			}
		}
		else if(b == 4)
		{
			if(shot->ahits == 5 && shot->bhits == 4)
			{
				return win;
			}
			else if(maxTries - 1 == 0 && (shot->ahits < 5 || shot->bhits < 4))
			{
				return lose;
			}
			else
			{
				return playing;
			}
		}
		if(shot->ahits == 5 && shot->bhits == 4)
		{
			return win;
		}
		else if(maxTries - 1 == 0 && (shot->ahits < 5 || shot->bhits < 4))
		{
			return lose;
		}
		else
		{
			return playing;
		}
}

