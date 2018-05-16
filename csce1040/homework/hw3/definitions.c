/*
Name: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 2/15/15
Instructor: Keathly
Description: the definitions of the functions file of the gradebook program
*/

#include <stdio.h>
#include <stdlib.h> /* need to use malloc */
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
   printf("\nCSCE 1040\nProgram 1\nScarlett Jones\nScarlettJones@my.unt.edu\n");
}

/*
Name: add course
Takes: the courses structure
Returns: nothing
Description: adds a new course to the gradebook by taking its id and name. If max has been reached realloc more space*/
void addcourse(courses *c)
{
  if(c->course_cnt == c->course_cap)
  {
	course *temp;
	temp = (course *) realloc(c->course_list, sizeof(course) *(c->course_cap + CHUNKSIZE));
	c->course_cap += CHUNKSIZE;
	c->course_list = temp;
   }

  printf("Enter new course ID: ");
  scanf ("%d%*c", &(c->course_list[c->course_cnt].course_id));
  printf ("Enter course name: ");
  fgets(c->course_list[c->course_cnt].course_name, MAX_NAME, stdin) ;
  c->course_cnt += 1;
}

/*
Name: addstudent
Takes: the students structure
Returns: nothing
Description: adds new students to the gradebook by taking their id and name. if the max students has been reached, reallocates more space
*/
void addstudent(students *s)
{
  if(s->stud_cnt == s->stud_cap)
  {
	student *temp;
	temp = (student *) realloc(s->stud_list, sizeof(student) *(s->stud_cap + CHUNKSIZE));
	s->stud_cap += CHUNKSIZE;
	s->stud_list = temp;
  }

  printf("Enter new student ID: ");
  scanf ("%d%*c", &(s->stud_list[s->stud_cnt].stud_id));
  printf ("Enter student name: ");
  fgets(s->stud_list[s->stud_cnt].stud_name, MAX_NAME, stdin) ;
  s->stud_cnt += 1;
}

/*
Name: addenroll
Takes: the enrollment structure
Returns: nothing
Description: adds a student to a course by asking for enrollment id, student id, and course id. Reallocate more space if max is reached.
*/
void addenroll(enrolls *e)
{
  if(e->enroll_cnt == e->enroll_cap)
  {
	enroll *temp;
	temp = (enroll *) realloc(e->enroll_list, sizeof(enroll) *(e->enroll_cap + CHUNKSIZE));
	e->enroll_cap += CHUNKSIZE;
	e->enroll_list = temp;
   }

  printf("Enter new enrollment id: ");
  scanf ("%d%*c", &(e->enroll_list[e->enroll_cnt].enroll_id));
  printf ("Enter student ID for enrollment: ");
  scanf ("%d%*c", &(e->enroll_list[e->enroll_cnt].stud_loc));
  printf ("Enter course ID for enrollment: ");
  scanf ("%d%*c", &(e->enroll_list[e->enroll_cnt].course_loc));
				
  enroll *temp;
  temp = (enroll *)malloc (sizeof(enroll) * CHUNKSIZE);
  e->enroll_cnt += 1;
}

/*
Name: addgrade
Takes: the enrollment structure
Returns: nothing
Description: asks for enrollment id, student id, and course id and then saves the grade in the enrollment structure. allocate more space if max grades has been reached.
*/
void addgrade(enrolls *g)
{
  int i, ctemp, stemp;
  ctemp = 0;
  stemp = 0;

  printf("\n\nEnter course id: ");
  scanf("%d%*c", &ctemp);
  printf("\nEnter student id: ");
  scanf("%d%*c", &stemp);
 /* for ( i=0; i < g->enroll_cnt; i++)
  {
    if(ctemp == g->enroll_list[i].course_loc && stemp == g->enroll_list[i].stud_loc)
    {
	  
	if(g->enroll_list[i].grade_cnt == g->enroll_list[i].grade_cap)
	{
		enroll *temp;
		temp = (enroll *) realloc(g->enroll_list[i].grade_list, sizeof(enroll) * (g->enroll_list[i].grade_cap + CHUNKSIZE));
		g->enroll_list[i].grade_cap += CHUNKSIZE;
		g->enroll_list[i].grade_list = temp;
	}

    		printf("\n\nAdd grade: ");
		scanf("%d%*c", g->enroll_list[i].grade_list);
		g->enroll_list[i].grade_cnt++;	
    }
  } */
}

/*
Name: prtstudgrade
Takes: the enrollments structure
Returns: nothing
Description: prints out student's grade(s) in a course
*/
void prtstudgrade(enrolls *g)
{
   int i, ctemp, stemp;
   ctemp = 0;
   stemp = 0;
  
   printf("\n\nEnter course id: ");
   scanf("%d%*c", &ctemp);
   printf("\nEnter student id: ");
   scanf("%d%*c", &stemp);
 /*  for ( i=0; i < g->enroll_cnt; i++)
   {
   	if(ctemp == g->enroll_list[i].course_loc && stemp == g->enroll_list[i].stud_loc)
   	{
    		printf("\nStudent's grade(s): \n%d\n", g->enroll_list[i].grade_list);
    	}
  } */
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
  int i, temp;
  temp = 0;

  printf("\n\nEnter course id: ");
  scanf("%d%*c", &temp);
  for ( i=0; i < sinc->enroll_cnt; i++)
  {
    if(temp == sinc->enroll_list[i].course_loc)
    {
    	printf ("\nEnrollment id: %d  Student ID: %d  Course ID: %d\n", sinc->enroll_list[i].enroll_id, sinc->enroll_list[i].stud_loc, sinc->enroll_list[i].course_loc);
    }
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
   int i;

   save = fopen("gradebook", "w");

   fwrite(c, sizeof(courses), 1, save);
   fwrite(s, sizeof(students), 1, save);
   fwrite(e, sizeof(enrolls), 1, save);
   
   fwrite(&(c->course_cap), sizeof(int), 1, save);
   fwrite(&(s->stud_cap), sizeof(int), 1, save);
   fwrite(&(e->enroll_cap), sizeof(int), 1, save);


   fwrite(&(c->course_cnt), sizeof(int), 1, save);
   for(i = 0; i < c->course_cnt; i++)
   	fwrite(&(c->course_list[i]), sizeof(course), 1, save);

   fwrite(&(s->stud_cnt), sizeof(int), 1, save);
   for(i = 0; i < s->stud_cnt; i++)
   	fwrite(&(s->stud_list[i]), sizeof(student), 1, save);

   fwrite(&(e->enroll_cnt), sizeof(int), 1, save);
   for(i = 0; i < e->enroll_cnt; i++)
   	fwrite(&(e->enroll_list[i]), sizeof(enroll), 1, save);

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
   int i;

   if((save = fopen("gradebook", "r")) != NULL)
   {
   	save = fopen("gradebook", "r");


	fread(c, sizeof(courses), 1, save);
   	fread(s, sizeof(students), 1, save);
   	fread(e, sizeof(enrolls), 1, save);


	fread(&(c->course_cnt), sizeof(int), 1, save);
	fread(&(c->course_cap), sizeof(int), 1, save);
 	for(i = 0; i < c->course_cnt; i++)
	{
		if(i > c->course_cap)
		{
			course *ctemp;
			ctemp = (course *) realloc(&(c->course_list[i]), sizeof(course) *(c->course_cap));
			c->course_list = ctemp;
		}
	
   		fread(&(c->course_list[i]), sizeof(course), 1, save);
	}

   	fread(&(s->stud_cnt), sizeof(int), 1, save);
	fread(&(s->stud_cap), sizeof(int), 1, save);
   	for(i = 0; i < s->stud_cnt; i++)
	{
		if(i > s->stud_cap)
		{
			student *stemp;
			stemp = (student *) realloc(&(s->stud_list[i]), sizeof(student) *(s->stud_cap));
			s->stud_list = stemp;
		}

   		fread(&(s->stud_list[i]), sizeof(student), 1, save);
	}

   	fread(&(e->enroll_cnt), sizeof(int), 1, save);
	fread(&(e->enroll_cap), sizeof(int), 1, save);
   	for(i = 0; i < e->enroll_cnt; i++)
	{
		if(i > e->enroll_cap)
		{
			enroll *etemp;
			etemp = (enroll *) realloc(&(e->enroll_list[i]), sizeof(enroll) *(e->enroll_cap));
			e->enroll_list = etemp;
		}

   		fread(&(e->enroll_list[i]), sizeof(enroll), 1, save);
	}
   	fclose(save);

	printf("\nGradebook loaded.\n");
   }
   else
   {
   	printf("\nNo gradebook information exists.\n");

   	return;
   }

}