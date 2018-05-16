#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declare the board size and other variables//

//Create the random number generator seed

//Loop to create the wanted board size

//Plant the random numbers into the board within the loop

int main()

{
//Initialize Variables
int randomNumber;
int rows;
int columns;

//Declare board size. size of board is 5 x 5
int board[5][5]; 

//Create the random number generator seed
srand(time(NULL));

//Assign the random numbers from 1 - 25 into variable randomNumber

//Create the rows for the board
    for ( rows = 0; rows < 5 ; rows++ )
    {
        //Create the columns for the board
        for ( columns = 0; columns < 5 ;  columns++ )
         {
         //Assign variable randomNumber into variable board
         randomNumber = rand() %25 + 1;

         board[rows][columns] = randomNumber;
         printf("%d\t", board[rows][columns]);

    }
        //Newline after the end of 5th column.
        printf("\n");
}

}//end main
