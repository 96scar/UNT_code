/*
Name: Scarlett Jones
Date: 2/15/15
Instructor: Keathly
Description: the structure header file of the gradebook program
*/

/*declaration of structures and declaring max sizes*/

#define MAX_STUDENTS 100 /*maximum number of students in the gradebook*/
#define MAX_COURSES 25 /*maximum number of courses in the gradebook*/
#define MAX_NAME 80 /*maximum number of characters in names of courses and students*/
#define MAX_CLASS 20 /*maximum number of students in a class*/
#define MAX_GRADES 10 /*maximum number of grades per student per course*/
#define MAX_LOAD 4 /*maximum number of courses student can take*/

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
//  int grade_loc;
//  int stud_grade[MAX_GRADES];
//  int studgrade_cnt;
} enroll;

/*
the students structure that stores the student count, the student structure with a student list
*/
typedef struct
{
  int stud_cnt;
  student stud_list[MAX_STUDENTS];
} students;

/*
the courses structure that stores the course count, and the course strucure with a course list
*/
typedef struct
{
  int course_cnt;
  course course_list[MAX_COURSES];
} courses;

/*
the enrollments structure that stores the enrollment count and the enrollment sturcture with an enrollment list
*/
typedef struct
{
  int enroll_cnt;
  enroll enroll_list[MAX_STUDENTS * MAX_LOAD];
  int stud_grade[MAX_GRADES];
  int studgrade_cnt;
  int grade_loc;
} enrolls;