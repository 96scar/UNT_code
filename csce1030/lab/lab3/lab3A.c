/*
Author: Scarlett Jones ScarlettJones@my.unt.edu
Date: 9/11/14
Instuctor: Mark Thompson
Purpose: The purpose of this lab is to find the missing code and correct it.
*/

/*This means that we are using standard input output.*/
#include <stdio.h>

int main()
{
   /*This defines inputGrade as an integer that will later be input through the keyboard by the user.*/
   int inputGrade;
   
   /*This is asking the user to input a grade for which a letter grade will be printed.*/
   printf("Input grade and receive corresponding letter grade - either A or B: \n");
   scanf("%d", &inputGrade);

   /* Using if and else-if statements, print the correct letter grade for the input grade. 90 and over print A, else print a B */
   if (inputGrade >= 90)
      printf("Your letter grade is an A.\n");
   else if (inputGrade < 90)
      printf("Your letter grade is a B.\n");   
   else
      printf("You did not input a grade.\n");

    /*This is so that the compiler returns its value to 0.*/
    return 0;
}
