#include "complex.h"
#include <malloc.h>
#include <stdlib.h>
#include <pthread.h>
#define CUTOFF 1024*128
 
typedef struct {
  int n;
  complex wn;
  complex *X, *Y;
} fft_t;

pcfft(fft_t *input)
/************************************************************************
  Parallel Fast fourier transform. 
  n = 2^k
  Y = F_n X
  wn is a primitive nth root of unity.
  packaged in input.
************************************************************************/
 
 
{
int n;
complex wn;
complex *X,*Y;
int m,j;
complex w2,w,t;
complex *X1, *X2, *Y1, *Y2;
fft_t *input1, *input2;
pthread_t thread1, thread2;
int error;
 

/* extract arguments */
  n = input->n;
  wn = input->wn;
  X = input->X;
  Y = input->Y;

/* Base case.  */  
 
  if (n <= CUTOFF) 
    {
    cfft(n,wn,X,Y);
    return;
    }

/* X1,X2 = L^{n}_2 X; */

m = n/2;

X1 = (complex *) malloc(m*sizeof(complex));
X2 = (complex *) malloc(m*sizeof(complex));
Y1 = (complex *) malloc(m*sizeof(complex));
Y2 = (complex *) malloc(m*sizeof(complex));

if (X1 == NULL || X2 == NULL || Y1 == NULL || Y2 == NULL)
  printf("malloc failed\n");

for (j = 0; j < m; j++)
  {
  X1[j] = X[2*j];
  X2[j] = X[2*j+1];
  }
  
/* cfft(m,Cmult(wn,wn),X1,Y1); */
input1 = (fft_t *) malloc(sizeof(fft_t));
input1->n = m;
input1->wn = Cmult(wn,wn);
input1->X = X1;
input1->Y = Y1;
error = pthread_create(&thread1,NULL,(void *(*)(void *)) pcfft,(void *)input1);
if (error != 0) printf("thread not created\n");
/* cfft(m,Cmult(wn,wn),X2,Y2); */
input2 = (fft_t *) malloc(sizeof(fft_t));
input2->n = m;
input2->wn = Cmult(wn,wn);
input2->X = X2;
input2->Y = Y2;
error = pthread_create(&thread2,NULL,(void *(*)(void *)) pcfft,(void *)input2);
if (error != 0) printf("thread not created\n");

pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
 
w.r = 1.0;
w.i = 0.0;

for (j=0;j<m;j++)
  {
  Y[j] = Cadd(Y1[j],Cmult(w,Y2[j]));    /*  Y[j] = Y1[j] + w^i Y2[j] */
  Y[j+m] = Cdif(Y1[j],Cmult(w,Y2[j]));  /*  Y[j+m] = Y1[j] - w^i Y2[j] */
  w = Cmult(w,wn);
  }
free(X1);
free(X2);
free(Y1);
free(Y2);
free(input1);
free(input2);
}

cfft(n,wn,X,Y)
/************************************************************************
  Fast fourier transform. 
  n = 2^k
  Y = F_n X
  wn is a primitive nth root of unity.
************************************************************************/
 
int n;
complex wn;
complex X[],Y[];
 
{

int m,j;
complex w2,w,t;
complex *X1, *X2, *Y1, *Y2;
 

/* Base case.  */  
 
  if (n == 1) 
    {
    Y[0] = X[0];
    return;
    }

  if (n == 2) 
    {
    Y[0] = Cadd(X[0],X[1]);
    Y[1] = Cdif(X[0],X[1]);
    }

/* X1,X2 = L^{n}_2 X; */

m = n/2;

X1 = (complex *) malloc(m*sizeof(complex));
X2 = (complex *) malloc(m*sizeof(complex));
Y1 = (complex *) malloc(m*sizeof(complex));
Y2 = (complex *) malloc(m*sizeof(complex));

for (j = 0; j < m; j++)
  {
  X1[j] = X[2*j];
  X2[j] = X[2*j+1];
  }
  
cfft(m,Cmult(wn,wn),X1,Y1);
cfft(m,Cmult(wn,wn),X2,Y2);
 
w.r = 1.0;
w.i = 0.0;

for (j=0;j<m;j++)
  {
  Y[j] = Cadd(Y1[j],Cmult(w,Y2[j]));    /*  Y[j] = Y1[j] + w^i Y2[j] */
  Y[j+m] = Cdif(Y1[j],Cmult(w,Y2[j]));  /*  Y[j+m] = Y1[j] - w^i Y2[j] */
  w = Cmult(w,wn);
  }
free(X1);
free(X2);
free(Y1);
free(Y2);
}
