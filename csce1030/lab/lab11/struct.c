/*
Author: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 11/6/14
Instructor: Mark Thompson
Purpose: Stores information about employee in a struct and then prints it out.
*/

/*Tells the preprocessor to include a copy of the standard input/output library.*/
#include <stdio.h>

/*A struct named employee that has two char arrays, 2 ints, and a double.*/
struct employee
{
	char first[10], last[10];
	int id, room;
	double phone;

};

/*The function main takes no arguments and returns an int value.*/
int main()
{
	/*Creates a variable in the struct.*/
	struct employee employee1;
	
	/*Asks for input of the employee's first and last name, id number, room number, and phone number.*/
	printf("\nEnter employee information.\n");
	printf("\nEmployee's first name: ");
	scanf("%s", employee1.first);
	printf("\nEmployee's last name: ");
	scanf("%s", employee1.last);
	printf("\nEmployee's ID number: ");
	scanf("%d", &employee1.id);
	printf("\nEmployee's office room number: ");
	scanf("%d", &employee1.room);
	printf("\nEmployee's office phone number: ");
	scanf("%lf", &employee1.phone);

	/*Prints out the employee's information.*/
	printf("\n\nHere is the employee's information.\n");
	printf("\nEmployee's first name: %s\n", employee1.first);
	printf("\nEmployee's last name: %s\n", employee1.last);
	printf("\nEmployee's ID number: %d\n", employee1.id);
	printf("\nEmployee's office room number: %d\n", employee1.room);
	printf("\nEmployee's office phone number: %.0lf\n\n", employee1.phone);

	/*Returns the function main to 0 so the compiler works.*/
	return 0;
}
