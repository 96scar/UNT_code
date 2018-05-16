/*
Author: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 11/4/2014
Instructor: Mark Thompson
Purpose: This is a simple database of grades that allows for storing of data in the database, retrieving data, and calculating individual and group statistics.
*/

/*Tells the preprocessor to include a copy of the standard input output library and the string functions to the program.*/
#include <stdio.h>
#include <string.h>

/*The max number of students is set at 200.*/
#define MAX_STUDENTS 200

/*These function prototypes let the compiler expect use of these functions later in the program.*/
void myInfo(void);
void menu(int *choice);
void database(int id[MAX_STUDENTS], float hw[MAX_STUDENTS], float ex1[MAX_STUDENTS], float ex2[MAX_STUDENTS]);
void studentInfo(int id[],int a, float hw[], float ex1[], float ex2[]);
void studentAverage(int id[MAX_STUDENTS], float hw[MAX_STUDENTS], float ex1[MAX_STUDENTS], float ex2[MAX_STUDENTS], float *average);
void letterGrade(float average);
void assignmentAverage(int id[MAX_STUDENTS], float hw[MAX_STUDENTS], float ex1[MAX_STUDENTS], float ex2[MAX_STUDENTS]);

/*The function main takes no arguments and returns an int value.*/
int main()
{
	/*Calls the function myInfo*/
	myInfo();

	/*Declares and intializes option as an int variable at 1 for the while loop to begin.*/
	int option;

	/*Declares four arrays with size MAX_STUDENTS to store euid, homework average, exam 1 and exam 2.*/
	float homework_average[MAX_STUDENTS], exam1[MAX_STUDENTS], exam2[MAX_STUDENTS], grade;
	int  euid[MAX_STUDENTS];

	/*Welcome message*/
	printf("\n\nWelcome to the UNT grade database.\n\n");

	/*Calls the function database. Passes it the arrays euid, homework_average, exam1, and exam2.*/
	database(euid, homework_average, exam1, exam2);
		
	option = 1;

	/*Checks to see if input for menu is between 1 and 4. Loops until this is not true.*/
	while(option >= 1 && option <= 4)
	{
		/*Calls the function menu*/
		menu(&option);

		switch (option)
		{
			case 1:  /*student grade data*/
				 printf("\nPlease enter student EUID: ");
				 studentInfo(euid,MAX_STUDENTS, homework_average, exam1, exam2);
				 break;
			case 2:  /*student grade average*/
				 printf("\nPlease enter student EUID: ");
				 studentAverage(euid, homework_average, exam1, exam2, &grade);
				 letterGrade(grade);
				 break;  
			case 3:  /*class average for an assignment*/
				 printf("\nPlease enter the assignment: ");
				 assignmentAverage(euid, homework_average, exam1, exam2);	  
				 break;  
			case 4:  /*exit*/
				 printf("\nGoodbye!\n\n");
				 option = 5;
				 break;  
			default: /*incorrect input*/
				 printf("\nInput a menu option between 1 and 4.\n\n");
				 option = 1;
				 break;
		}  
	}	

	/*Returns the function main value to 0 so that the compiler works.*/
	return 0;
}

/*
Function: myInfo
Parameters: none
Return: nothing
Description: Prints out my personal information
*/
void myInfo(void)
{
	printf("\nCSCE 1030\nProgram 5\nScarlett Jones\nsrj0101\nScarlettJones@my.unt.edu\n\n");

	return;
}

/*
Function: menu
Parameters: Choice, as a pointer
Return: nothing
Description: Prints out the menu for the program, asks for input of data through pointers and adresses
*/
void menu(int *choice)
{
	printf("\nPlease enter what information you want out of the database:\n1. Student grade data\n2. Student grade average\n3. Class average for an assignment\n4. Exit\n>");	
	scanf("%d", choice);	

	return;
}

/*
Function: database
Parameters: Arrays id, hw, ex1, and ex2
Return: nothing
Description: Reads in the data for the database
*/
void database(int id[MAX_STUDENTS], float hw[MAX_STUDENTS], float ex1[MAX_STUDENTS], float ex2[MAX_STUDENTS])
{
	printf("\n\nInput the information for the database.\n\n");

	int i;

	for(i = 0; i < MAX_STUDENTS; ++i)
	{
		scanf("%d", &id[i]);
	
		if(id[i] == -1)
		{
			id[i] = 0;
			break;
		}
		else
		{
			scanf("%f%f%f", &hw[i], &ex1[i], &ex2[i]);
		}
	}
	return;
}

/*
Function: studentInfo
Parameters: arrays id, hw, ex1, and ex2
Return: nothing
Description: Reads in an euid and compares it to the contents of the array id. When it matches, uses that index to give other information of student's grades.
*/
//void studentInfo(float id[MAX_STUDENTS], float hw[MAX_STUDENTS], float ex1[MAX_STUDENTS], float ex2[MAX_STUDENTS])
void studentInfo(int id[],int size, float hw[], float ex1[], float ex2[])
{
	int i, euid;
	scanf("%d", &euid);
	for(i = 0; i < MAX_STUDENTS; i++)
	{
		if(euid == id[i])
		{
			printf("EUID: %d\nHomework Average: %.2f\nExam 1: %.0f\nExam 2: %.0f\n", id[i], hw[i], ex1[i], ex2[i]);
			return;
		}
		else
			;
//			printf("Not a valid EUID.\nTry again: ");	
	}

	return;
}


/*
Function: studentAverage
Parameters: Arrays id, hw, ex1, and ex2
Return: nothing
Description: Prints out the average of a student
*/
void studentAverage(int id[MAX_STUDENTS], float hw[MAX_STUDENTS], float ex1[MAX_STUDENTS], float ex2[MAX_STUDENTS], float *average)
{
	int i, euid;
	scanf("%d", &euid);
	for(i = 0; i < MAX_STUDENTS; ++i)
	{
		if(euid == id[i])
		{
			*average = (0.5 * hw[i] + 0.25 * ex1[i] + 0.25 * ex2[i]);
			printf("EUID: %d\nStudent Average: %.2f\n", id[i], *average);
			return;
		}
		else
			;
//			printf("Not a valid EUID.\nTry again: ");
	}

	return;
}

/*
Function: letterGrade
Parameters: A float that is the student's average grade
Return: nothing
Description: prints out the letter grade of the student
*/
void letterGrade(float average)
{
		if(average >= 89.50)
		{
			printf("Letter Grade: A");
			return;
		}
		else if(average >= 79.50)
		{
			printf("Letter Grade: B");
			return;
		}
		else if(average >= 69.50)
		{
			printf("Letter Grade: C");
			return;
		}
		else if(average >= 59.50)
		{
			printf("Letter Grade: D");
			return;
		}
		else if(average < 59.50 && average >= 0)
		{
			printf("Letter Grade: F");
			return;
		}
		else
		{
			printf("Your grade is in negative numbers.");
			return;
		}
		return;
}

/*
Function: assignmentAverage
Parameters: three floats that are arrays- hw, ex1, and ex2
Return: nothing
Description: 
*/
void assignmentAverage(int id[MAX_STUDENTS], float hw[MAX_STUDENTS], float ex1[MAX_STUDENTS], float ex2[MAX_STUDENTS])
{
	char assignment[30], homework[]="homework", exam1[]="exam1", exam2[]="exam2";
	int i, denom = 0;
	float classavg, sum = 0;
	printf("\nChoose from homework, exam1, and exam2: ");
	scanf("%s", assignment);

	if(strcmp(assignment, homework) == 0)
	{
		for(i = 0; i < MAX_STUDENTS; ++i)
		{
			if(id[i] != 0)
			{
				sum += hw[i];
				++denom;
			}
			else
				break;	
		}
		classavg = sum/denom;
		printf("Class Homework Average: %f\n", classavg);
	}
	else if(strcmp(assignment, exam1) == 0)
	{
		for(i = 0; i < MAX_STUDENTS; ++i)
		{
			if(id[i] != 0)
			{
				sum += ex1[i];
				++denom;
			}
			else
				break;
		}
		classavg = sum/denom;
		printf("Class Exam 1 Average: %f\n", classavg);
	}
	else if(strcmp(assignment, exam2) == 0)
	{
		for(i = 0; i < MAX_STUDENTS; ++i)
                {
                        if(id[i] != 0)
                        {
                                sum += ex2[i];
                                ++denom;
                        }
                        else
                                break;
                }
                classavg = sum/denom;
	       	printf("Class Exam 2 Average: %f\n", classavg);
	}
	else
		printf("\nSorry, I do not understand that word.\nTry again: ");

	return;
}
