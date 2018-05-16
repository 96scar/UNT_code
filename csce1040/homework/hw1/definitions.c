/*
Name: Scarlett Jones
Date: 2/15/15
Instructor: Keathly
Description: the definitions of the functions file of the gradebook program
*/

#include <stdio.h>
//stores definitions of the menu functions
#include "structure.h"
#include "prototype.h"

/*
Name: myinfo
Takes: nothing
Returns: nothing
Description: Display the department and course number, program number, my name, and my email address
*/
void myinfo()
{
   printf("\nCSCE 1040\nProgram 1\nScarlett Jones\nScarlett.Jones@my.unt.edu\n");
}

/*
Name: add course
Takes: the courses structure
Returns: nothing
Description: adds a new course to the gradebook by taking its id and name. if max has been reached, prints out error message.
*/
void addcourse(courses *c)
{
  if(c->course_cnt < 25)
  {
  	printf("Enter new course ID: ");
  	scanf ("%d%*c", &(c->course_list[c->course_cnt].course_id));
  	printf ("Enter course name: ");
  	fgets(c->course_list[c->course_cnt].course_name, 80, stdin) ;
  	c->course_cnt += 1;
  }
  else
  {
  	printf("\nMaximum number of courses reached.\n");
  }
}

/*
Name: addstudent
Takes: the students structure
Returns: nothing
Description: adds new students to the gradebook by taking their id and name. if the max students has been reached, prints out an error message
*/
void addstudent(students *s)
{
  if(s->stud_cnt < 100)
  {
  	printf("Enter new student ID: ");
  	scanf ("%d%*c", &(s->stud_list[s->stud_cnt].stud_id));
  	printf ("Enter student name: ");
  	fgets(s->stud_list[s->stud_cnt].stud_name, 80, stdin) ;
  	s->stud_cnt += 1;
  }
  else
  {
  	printf("\nMaximum number of students reached.\n");
  }
}

/*
Name: addenroll
Takes: the enrollment structure
Returns: nothing
Description: adds a student to a course by asking for enrollment id, student id, and course id. error message if max reached.
*/
void addenroll(enrolls *e)
{
  if(e->enroll_cnt < 100)
  {
  	printf("Enter new enrollment id: ");
  	scanf ("%d%*c", &(e->enroll_list[e->enroll_cnt].enroll_id));
  	printf ("Enter student ID for enrollment: ");
  	scanf ("%d%*c", &(e->enroll_list[e->enroll_cnt].stud_loc));
  	printf ("Enter course ID for enrollment: ");
  	scanf ("%d%*c", &(e->enroll_list[e->enroll_cnt].course_loc));
  	e->enroll_cnt += 1;
  }
  else
  {
  	printf("\nMaximum number of enrollments reached.\n");
  }
}

/*
Name: addgrade
Takes: the enrollment structure
Returns: nothing
Description: asks for enrollment id, student id, and course id and then saves the grade in the enrollment structure. error message if max grades has been reached.
*/
void addgrade(enrolls *g)
{
/*
   int t_enrollid=0;

   if(g->studgrade_cnt < 10)
   {
    printf("\nEnter enrollment ID: ");
   scanf("%d", &t_enrollid);
    if(t_enrollid == enroll_id)
    
  printf("\nEnter grade: ");
  scanf("%d%*c", &(g->stud_grade[g->studgrade_cnt].grade_loc));
  g->studgrade_cnt +=1;
  }
  else
  {
	printf("\nMaximum number of grades reached.\n");
  }
*/
}

/*
Name: prtstudgrade
Takes: the enrollments structure
Returns: nothing
Description: prints out a student's grade in a course
*/
void prtstudgrade(enrolls *g)
{
   printf("\nStudent's Grades: \n");
}

/*
Name: studavg
Takes: the enrollments structure
Returns: nothing
Description: computes the average of a student's grades in a course
*/
void studavg(enrolls *g)
{
   printf("\nStudent's Course Average: \n");
}

/*
Name: courseavg
Takes: the enrollments structure
Returns: nothing
Description: computes the average of all grades in a course
*/
void courseavg(enrolls *g)
{
   printf("\nCourse Average: \n");
}

/*
Name: prtstudents
Takes: the students structure
Returns: nothing
Description: prints out a list of all students with a for loop
*/
void prtstudents(students *alls)
{
  int i;
  for ( i=0; i < alls->stud_cnt; i++)
  {

    printf ("Student id: %d  Student Name: %s\n", alls->stud_list[i].stud_id, alls->stud_list[i].stud_name);
  }
}

/*
Name: prtcourses
Takes: the structure courses
Returns: nothing
Description: prints out a list of all the courses with a for loop
*/
void prtcourses(courses *allc)
{
  int i;
  for ( i=0; i < allc->course_cnt; i++)
  {

    printf ("Course id: %d  Course name: %s\n", allc->course_list[i].course_id, allc->course_list[i].course_name);
  }
}

/*
Name: prtincourse
Takes: the enrollment structure
Returns: nothing
Description: prints out a list of all students in a course
*/
void prtincourse(enrolls *sinc)
{
  int i;
  for ( i=0; i < sinc->enroll_cnt; i++)
  {
    printf ("Enrollment id: %d  Student ID: %d  Course ID: %d\n", sinc->enroll_list[i].enroll_id, sinc->enroll_list[i].stud_loc, sinc->enroll_list[i].course_loc);
  }
}

/*
Name: store
Takes: three structs representing courses, students, and enrollments
Returns: nothing
Description: saves the structs in a file named gradebook
*/
void store(courses *c, students *s, enrolls *e)
{
   FILE *save;
   save = fopen("gradebook", "w");
   fwrite(c, sizeof(courses), 1, save);
   fwrite(s, sizeof(students), 1, save);
   fwrite(e, sizeof(enrolls), 1, save);
   fclose(save);
   printf("\nGradebook saved.\n");
}

/*
Name: load
Takes: three structs representing courses, students, and enrollments
Returns: nothing
Description: Checks to see if the gradebook file exists, if not, prints an error message and exits the function. If the file does exist, it loads the information to the gradebook.
*/
void load(courses *c, students *s, enrolls *e)
{
   FILE *save;

   if((save = fopen("gradebook", "r")) != NULL)
   {
   	save = fopen("gradebook", "r");
   	fread(c, sizeof(courses), 1, save);
   	fread(s, sizeof(students), 1, save);
   	fread(e, sizeof(enrolls), 1, save);
   	fclose(save);
	printf("\nGradebook loaded.\n");
   }
   else
   {
   	printf("\nNo gradebook information exists.\n");
   	return;
   }

}