/*
Author: Scarlett Jones ScarlettJones@my.unt.edu
Date: 9/11/14
Instuctor: Mark Thompson
Purpose: The purpose of this lab is to perform different computations for different types of integers.
*/

/*This means that we are using standard input output.*/
#include <stdio.h>

int main()
{

   /*This defines inputInteger as an integer that will later be input through the keyboard by the user.*/
   int inputInteger;
   
   /*This is asking the user to input an integer for which a negative integer will be squared, a positive integer will be cubed, and a zero will perform no computation.*/
   printf("Input an integer for either a square, a cube, or nothing to occur: \n");
   scanf("%d", &inputInteger);

   /* Using if and else-if statements: If the integer is positive, the value will be cubed. If the integer is negative, the value will be squared. 
If the integer is zero, no computation will be performed and the value 0 will be printed back to the user. */
   if (inputInteger > 0)
      printf("The cube of your value is %d.\n", (inputInteger * inputInteger * inputInteger));
   else if (inputInteger < 0)
      printf("The square of your value is %d.\n", (inputInteger * inputInteger));   
   else
      printf("No computation was performed because the value you inputed was %d.\n", inputInteger);

    /*This returns the value of the compiler to 0.*/
    return 0;
}
