/*
Author: Scarlett Jones
Date: 12/6/14
Instructor: Mark Thompson
Purpose: the classic game of battleship for one player only. this is split into three files.
*/

/*preprocessor directives tell this local file to include the standar input/output library, the standard library, and the string library.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*size of the gameboard*/
#define SIZE 10

/*template of structure type*/
struct torpedo
{
	char row;
	int column, ahits, bhits;
};

/*list of function prototypes*/
void printStudInfo(void);
void printIntro(int maxTries);
void printGridRow(int i);
void dispGrid(int **board, int view);
int assignShip(int **board, int shipType);
int status(int **board, struct torpedo *shot, int maxShots);
