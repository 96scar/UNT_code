#include "complex.h"

complex Cmult(complex a, complex b)
{
complex c;

c.r = a.r*b.r - a.i * b.i;
c.i = a.r*b.i + a.i * b.r;
return c;
}

complex CmultI(complex a)
{
  complex c;
  c.r = -a.i;
  c.i = a.r;
  return c;
}


complex Cadd(complex a, complex b)
{
complex c;

c.r = a.r + b.r;
c.i = a.i + b.i;
return c;
}

complex Cdif(complex a, complex b)
{
complex c;

c.r = a.r - b.r;
c.i = a.i - b.i;
return c;
}

complex Cread()
{
complex c;

scanf("%lf",&c.r);
scanf("%lf",&c.i);
return c;
}

void Cwrite(complex c)
{
printf("%f + i%f",c.r,c.i);
}
