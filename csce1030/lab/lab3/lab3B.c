/*
Author: Scarlett Jones ScarlettJones@my.unt.edu
Date: 9/11/14
Instuctor: Mark Thompson
Purpose: The purpose of this lab is to tell whether an input integer is positive, negative, or zero.
*/

/*This means that we are using standard input output.*/
#include <stdio.h>

int main()
{

   /*This defines inputInteger as an integer that will later be input through the keyboard by the user.*/
   int inputInteger;
   
   /*This is asking the user to input an integer for which they will be told whether it is positive, negative, or zero.*/
   printf("Input an integer to see what the value is and whether it is positive, negative, or zero: \n");
   scanf("%d", &inputInteger);

   /* Using if and else-if statements, tell the user what the value they printed is and whether it is positive, negative, or zero. */
   if (inputInteger > 0)
      printf("The value you printed is %d, and it is positive.\n", inputInteger);
   else if (inputInteger < 0)
      printf("The value you printed is %d, and it is negative.\n", inputInteger);   
   else
      printf("The value you printed is %d, and it is zero.\n", inputInteger);

    /*This returns the value to 0 for the compiler.*/
    return 0;
}
