/*
Author: Scarlett Jones
Email: ScarlettJones@my.unt.edu
Due Date: 9/17/14
Instructor: Mark Thompson
Description: This program calculates the time it takes a projectile to hit the ground and the maximum height the object will reach with the quadratic equation.
*/


/* These two "includes" tell the preprocessor to include a copy of the header files stdio.h and math.h, found in the usual place. 
Stdio.h is the standard input/output library and math.h is the math library. The math library is needed to be able to perform the square root function.  */
#include <stdio.h>
#include <math.h>


/* The funcion main takes no arguments and returns an int value. */
int main()
{


	/* This initially displays the department and course number, the program number, my name, my EUID, and my e-mail address. */
	printf("\n\nCSCE 1030\nProgram 1\nScarlett Jones\nsrj0101\nScarlettJones@my.unt.edu\n\n");
	

	/* This declares so, vo, and a as doubles and defines a as - 16. This is from the equation s(t)= -16*t^2 + vo*t+so when s(t) equals zero, 
	because the height is zero when the final time elapses. I also use the quadratic formula: t= -vo - sqrt(vo^2 -4*a*so)/(2*a). 
	Only one of the solutions is valid, and that is the one that subtracts the squareroot, not adds. I only use the valid solution. so and vo will be input by the user. */
	double so, vo, a;
	a = -16;


	/* This asks the user to input an initial height(so) in feet and an initial veloctiy(vo) in feet/second. */
	printf("Enter initial height of so in feet: ");
	scanf("%lf", &so);
	printf("Enter initial velocity of vo in feet/second: ");
	scanf("%lf", &vo);


	/* This declares discriminant, square, num1, denom1, num2, and denom2 as doubles. The discriminant is found by multiplying vo by vo and then subtracting -4 times a times so. 
	The square is found by taking the square root of the discriminant. num1 is found by subtracting the square from -vo. denom1 is found by mmultiplying 2 times a. 
	num2 is found by adding negative (vo times vo) to 4 times a times so. denom2 is found by multiplying 4 by a.  */
	double discriminant, square, num1, denom1, num2, denom2;
	discriminant = (vo * vo) - 4 * a * so;
	square = sqrt(discriminant);
	num1 = (-(vo) - square);
	denom1 = (2 * a);
	num2 = (-(vo * vo) + 4 * a * so);
	denom2 = (4 * a);

	
	/* This prints out when the projectile will hit the ground as a double with 2 decimal places. It divides num1 by denom1. */
	printf("The projectile will hit the ground in %.2lf seconds.\n", num1 / denom1 );
	

	/* This prints out the maximum height of the object as a double with 2 decimal places. It devides num2 by denom2.  */
	printf("The maximum height the object will reach is %.2lf feet.\n\n", num2 / denom2 );


	/* This returns the function value to zero so that the compiler will work.  */
	return 0;


}
