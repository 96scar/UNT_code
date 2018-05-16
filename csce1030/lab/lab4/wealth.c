/*
Author: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 9/18/14
Instructor: Mark Thompson
Purpose: This program will compute the compound interest after receiving the number 
of years and the amount of money invested. This is using a rate of 6%, or 0.06. I will use a loop to do this lab.
*/

/* These directives tell the preprocessor to include a copy of the standard input/output library into this program.  */
#include <stdio.h>


/* This means that the function main doesn't take any arguments and it returns in int value. */
int main()
{
	/* This declares input and years as int variables. "input", which is the number of years, will be input by the user. 
	"years" starts out at 1. This is so that the while loop has a starting point. */
	int input, years;
	years = 1;

	/* This declares investment and returnrate as variables. They are doubles. 
	The investment is how much money is invested. I initialize returnrate as 0.06 because the rate of return in 6%. */
        double investment, returnrate;
	returnrate = 0.06;

	/* This asks the user to input the number of years for the interest to be compounded. I store the value in years. */
	printf("\nNumber of years to compute interest: ");
	scanf("%d", &input);

	/* This asks the user to input the amount of money they want to invest. I store the value in investment. */
	printf("Amount of money to invest: ");
	scanf("%lf", &investment);
	

	/* This is a loop that will compute the investment will be increased by the rate of return. It prints out the new value of the investment along with the year. 
	This is a while loop. The investment starts out at whatever the user input. When years is bigger than the input, the loop will no longer run again. 
	This is the ending point. I use a double % sign to print one % sign. */
	while ( years <= input )
	{	
			/* This is equation to find out how much money the investment will give each year.
        		This equation is put after the user inputs the investment so that the equation works. 
			This has to be inside the loop to work correctly. */
        		double value;
        		value = investment + investment * returnrate;

			/* This is what the while loop will print while the years is less than or equal to the input.*/ 
			printf("Year %d: Investment increased by 0.06%%. Valued at: $%.2lf\n", years, value);

			/* This increments years by 1, and goes back to the conditional to see if the loop will run again. 
			I also make the new investment equal to value so that the value output will be larger each year. */
			years += 1;
			investment = value;
	}

	/* This returns the function value to zero so that the compiler will work. */
	return 0;
}
