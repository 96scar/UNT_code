/*
Name: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 2/15/15
Instructor: Keathly
Description: the main file of the gradebook program
*/

#include <stdio.h>
#include <stdlib.h> /* to allocate memory */
/*include local header files*/
#include "structure.h"
#include "prototype.h"

int main()
{
	/*makes variables in the structures to be able to access members*/
	students studs;
  	courses classes;
  	enrolls incourse;
  	int menu = -1;
  	studs.stud_cnt=0;
  	classes.course_cnt=0;
  	incourse.enroll_cnt=0;
		
	studs.stud_cap = classes.course_cap = incourse.enroll_cap = CHUNKSIZE;

	studs.stud_list = (student *)malloc (sizeof(student) * CHUNKSIZE);
	incourse.enroll_list = (enroll *)malloc (sizeof(enroll) * CHUNKSIZE);
	classes.course_list = (course *)malloc (sizeof(course) * CHUNKSIZE);	

	myinfo();

	/*When the menu item selected is not 0, then continue the loop*/
  	while (menu != 0)
  	{
	  printf("\nWelcome to the Gradebook.");
  	  printf ("\nSelect a menu option\n");
  	  printf (" 0  - Exit Gradebook\n 1  - Add a new course\n 2  - Add a new student\n 3  - Add a student to a course\n 4  - Add grades for a student in a course\n 5  - Print a list of all grades for a student in a course\n 6  - Print a list of all students in a course\n 7  - Compute the average for a student in a course\n 8  - Print a list of all courses\n 9  - Print a list of all students\n 10 - Compute the average for a course\n 11 - Store Gradebook\n 12 - Load Gradebook\n");
    	  printf ("Enter your selection: ");
	  /*the %*c reads in a character but doesn't store it anywhere. That basically ignores the enter, which is a character.*/
    	  scanf ("%d%*c", &menu);

    	  switch (menu)
    	  {
    	  case 1: addcourse(&classes); 
		  break;
          case 2: addstudent(&studs); 
		  break;
    	  case 3: addenroll(&incourse);
		  break;
    	  case 4: addgrade(&incourse);
		  break;
    	  case 5: prtstudgrade(&incourse);
		  break;
    	  case 6: prtincourse(&incourse);
		  break;
	  case 7: studavg(&incourse);
		  break;
	  case 8: prtcourses(&classes);
		  break;
	  case 9: prtstudents(&studs);
		  break;
	  case 10: courseavg(&incourse);
		   break;
	  case 11: store(&classes, &studs, &incourse);
		   break;
	  case 12: load(&classes, &studs, &incourse);
		   break;
	  default: printf("\nClosed gradebook.\n\n");
		   break;
    	  }
  	}
	

	return 0;
}
