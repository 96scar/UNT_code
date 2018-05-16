#include <stdio.h>
typedef struct cstruct { double r; double i; } complex;

complex Cadd(complex,complex);
complex Cdif(complex,complex);
complex Cmult(complex,complex);
complex CmultI(complex);
void Cwrite(complex);
complex Cread(void);
