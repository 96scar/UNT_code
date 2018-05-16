/*
Name: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 2/15/15
Instructor: Keathly
Description: the structure header file of the gradebook program
*/

/*declaration of structures and declaring max sizes*/

#define CHUNKSIZE 2
#define MAX_NAME 80

/*
course structure that stores the course id and course name
*/
typedef struct
{
   int course_id;
   char course_name[MAX_NAME];
}  course;

/*
student structure that stores the student id and student name
*/
typedef struct
{
  int stud_id;
  char  stud_name[MAX_NAME];
} student;

/*
enrollment structure that stores the enrollment id, student location, course, location, the grades, and the grade count
*/
typedef struct
{
  int enroll_id;
  int stud_loc;
  int course_loc;
  int *grade_list;
  int grade_cnt;
  int grade_cap;
} enroll;

/*
the students structure that stores the student count, the student structure with a student list
*/
typedef struct
{
  int stud_cnt;
  int stud_cap;
  student *stud_list;
} students;

/*
the courses structure that stores the course count, and the course strucure with a course list
*/
typedef struct
{
  int course_cnt;
  int course_cap;
  course *course_list;
} courses;

/*
the enrollments structure that stores the enrollment count and the enrollment sturcture with an enrollment list
*/
typedef struct
{
  int enroll_cnt;
  int enroll_cap;
  enroll *enroll_list;
} enrolls;