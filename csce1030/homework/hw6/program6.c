
/*
Author: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 11/25/14
Instructor: Mark Thompson
Purpose: A simplified version of the classic game of Battleship. This displays the board after ships are randomly assigned. 
*/

/*Preprocessor directive that tells the preprocessor to include a copy of the standard input/output lirary*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*Defines the constant SIZE at a set value. This is how big the board is.*/
#define SIZE 10

/*Function prototypes tell the compiler to expect use of these functions*/
void myInfo(void);
void welcomeMessage(void);
void assignShip(int **board, int unit, int orientation, int row, int column);
void displayBoard(int **board);

/*The function main has no arguments and returns an int value*/
int main()
{
	/*The time seed to make the rand function random.*/
	srand(time(NULL));

	/*Creates a 2D array called board, i, j, attempt, aircraft(length), battleship(length), orientation, row, and column as int vaues*/
	int **board, i, j, attempt, aircraft, battleship, orientationA, orientationB, rowA, rowB, columnA, columnB;
	aircraft = 5;
	battleship = 4;
	attempt = 0;
	orientationA = rand()%2;
	orientationB = rand()%2;	

	/*Dynamiclally allocates space for the board, initialzes everything to 0*/
	board = calloc(SIZE, sizeof(int*));
	for(i = 0; i < SIZE; i++)
	{
		board[i] = calloc(SIZE, sizeof(int));
	}

	/*Calls the myInfo function*/
	myInfo();

	/*Call the welcomeMessage function*/
	welcomeMessage();

	printf("\n\tInitializing board... now let's begin!\n");

	/*Call the assignShip function*/
	while(attempt != 1)
	{
		rowA = rand()%SIZE;
		columnA = rand()%SIZE;
		rowB = rand()%SIZE;
		columnB = rand()%SIZE;	
	
		if(orientationA == 0) /*horizontal aircraft*/
		{
			if(columnA + aircraft > SIZE)
			{
				attempt = 0; /*fail*/
			}
			else
			{
				i = 0;
				while(i < SIZE)
				{
					if(board[rowA + i][columnA + i] == board[rowB + i][columnB + i])
					{
						attempt = 0; /*fail*/
					}
					else
					{
						assignShip(board, aircraft, orientationA, rowA, columnA);
						attempt = 1; /*success*/
						i = SIZE;
					}
					i++;
				}
			}
		}
		else if(orientationA == 1) /*vertical aircraft*/
		{
			if(rowA + aircraft > SIZE)
			{
				attempt = 0; /*fail*/
			}
			else
			{
				i = 0;
				while(i < SIZE)
				{
					if(board[rowA + i][columnA + i] == board[rowB + i][columnB + i])
					{
						attempt = 0; /*fail*/
					}
					else
					{
						assignShip(board, aircraft, orientationA, rowA, columnA);
						attempt = 1; /*success*/
						i = SIZE;
					}
					i++;
				}
			}
		}
		else if(orientationB == 0) /*horizontal battleship*/
		{
			if(columnB + battleship > SIZE)
			{
				attempt = 0; /*fail*/
			}
			else
			{
				i = 0;
				while(i < SIZE)
				{
					if(board[rowA + i][columnA + i] == board[rowB + i][columnB + i])
					{
						attempt = 0; /*fail*/
					}
					else
					{
						assignShip(board, battleship, orientationB, rowB, columnB);
						attempt = 1; /*success*/
						i = SIZE;
					}
					i++;
				}
			}
		}
		else if(orientationB == 1)
		{
			if(rowB + battleship > SIZE)
			{
				attempt = 0; /*fail*/
			}
			else
			{
				i = 0;
				while(i < SIZE)
				{
					if(board[rowA + i][columnA + i] == board[rowB + i][columnB + i])
					{
						attempt = 0; /*fail*/
					}
					else
					{
						assignShip(board, battleship, orientationB, rowB, columnB);
						attempt = 1; /*success*/
						i = SIZE;
					}
					i++;
				}
			}
		}


			assignShip(board, aircraft, orientationA, rowA, columnA);
			assignShip(board, battleship, orientationB, rowB, columnB);
			attempt = 1;
	}
	
	/*Call the displayBoard funciton*/
	displayBoard(board);

	/*Frees up the memory taken by the array board.*/
	free(board);

	/*Returns the function main to zero so the compiler will work*/
	return 0;
}

/*
Function: myInfo
Parameters: none
Return: nothing
Description: Prints out my information
*/
void myInfo(void)
{
	printf("\n+------------------------------------------------------------+");
	printf("\n|         Computer Science and Engineering                   |");
	printf("\n|          CSCE 1030 - Computer Science I                    |");
	printf("\n|     Scarlett Jones  srj0101   srj0101@my.unt.edu           |");
	printf("\n+------------------------------------------------------------+");

	return;
}

/*
Function: welcomeMessage
Parameters: none
Return: nothing
Description: Prints out the introductory message with details about the game
*/
void welcomeMessage(void)
{
	char level[7];
	int chances, input;
	input = 1;
	printf("\n\n\t\tWelcome to Battleship!\n");

	while(input != 0)
	{
		printf("\nEnter difficulty level of game (easy, normal, hard): ");
		scanf("%s", level);
		
		if((strcmp(level, "easy") == 0))
		{
			chances = 30;
			input = 0;
		}
		else if((strcmp(level, "normal") == 0))
		{
			chances = 25;
			input = 0;
		}
		else if((strcmp(level, "hard") == 0))
		{
			chances = 20;
			input = 0;
		}
		else
		{
			printf("Incorrect input.");
			input = 1;
		}
	}

	printf("\n+--------------------------------------------------------------+	");
	printf("\n| The computer program will randomly assign an aircraft carri- |	");
	printf("\n| er and a battleship, that are oriented eiher vertically or   |	");
	printf("\n| horizontally, to the board. You will have %d chances to sink |	", chances);
	printf("\n| both the computer's aircraft carrier and battleship!! You'll |	");
	printf("\n| play on a %dx%d board, where the aircraft carrier will have  |	", SIZE, SIZE);
	printf("\n| a length of 5 units and the battleship will have a length of |	");
	printf("\n| 4 units.                                                     | 	");
	printf("\n+--------------------------------------------------------------+\n\n	");

	return;
}

/*
Function: assignShip
Parameters: The 2D array board, unit(the ship type length), orientation(horizontal or vertical represented by 0 or 1), row, and column
Return: nothing
Description: Assigns both ships (aircraft carrier and battleship) to the board
*/
void assignShip(int **board, int unit, int orientation, int row, int column)
{
	int i, j;
	i = 0;

	if(orientation == 0) /*horizontal*/
	{
			if(unit == 5)
			{
				while(i < unit)
				{
					board[row][column+i] = 'A';
					i++;
				}
			}
			else if(unit == 4)
			{
				while(i < unit)
				{
					board[row][column+i] = 'B';
					i++;
				}
			}
	}
	else if(orientation == 1) /*vertical*/
	{

			if(unit == 5)
			{
				while(i < unit)
				{
					board[row+i][column] = 'A';
					i++;
				}
			}
			else if(unit == 4)
			{
				while(i < unit)
				{
					board[row+i][column] = 'B';
					i++;
				}
			}
	}
		

	return;
}

/*
Function: displayBoard
Parameters: the 2D array called board
Return: nothing
Description: displays the current status of the game board
*/
void displayBoard(int **board)
{
	int i, j;
	
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
			printf(" %c", board[i][j]);
		}
		printf("\t\t\t\n");
	}

	for(i = -2; i < SIZE; i++)
	{
		for(j = -2; j < SIZE; j++)
		{
			if(i == -2)
			{
				printf("\n\t\t   ");
				i = 1;
				while(i <= SIZE)
				{
					printf(" %d", i);		
	
					i++;
				}
				i = -1;
			}
			else if(i == -1)
			{
				printf("\n\t\t  +");
				i = 1;
				while(i <= SIZE*2+1)
				{
					printf("-");
					i++;
				}
				printf("+");
				i = 0;
			}
			else if(i == 0)
			{
				i = 1;
				int k = 0, m = 0, n = 0;
				char letter = 'A';
				printf("\n\t\t");
				while(i <= SIZE)
				{
					printf("%c |", letter);
					k = 0;
			//		for(i = 0; i < SIZE; i++)
			//		{
			//			for(j = 0; j < SIZE; j++)
			//			{
			//				printf(" %c", board[i][j]);
			//			}
			//		}
					while(k <= SIZE*2)
					{
						printf(" ");
						k++;
					}
					printf("|");
					i++;
					letter++;
					printf("\n\t\t");
				}
				i = SIZE+1;
			}
			else if(i == SIZE+1)
			{
				printf("  +");
				i = 1;
				while(i <= SIZE*2+1)
				{
					printf("-");
					i++;
				}
				printf("+");
			}
			else
				;	
		}
		printf("\n");
	}


	return;
}
