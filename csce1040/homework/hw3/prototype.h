/*
Name: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 2/15/15
Instructor: Keathly
Description: the function prototype header file of the gradebook program
*/

/*stores prototypes for all the menu functions*/

void myinfo();
void addcourse(courses *c);
void addstudent(students *s);
void addenroll(enrolls *e);
void addgrade(enrolls *g);
void prtstudgrade(enrolls *g);
void studavg(enrolls *g);
void courseavg(enrolls *g);
void prtstudents(students *alls);
void prtcourses(courses *allc);
void prtincourse(enrolls *sinc);
void store(courses *c, students *s, enrolls *e);
void load(courses *c, students *s, enrolls *e);