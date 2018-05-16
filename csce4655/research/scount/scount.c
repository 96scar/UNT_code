/*****************************************************************************
This program statically schedules threads to sum the elements of an array.

The program is implemented using Pthreads.
Jeremy R. Johnson
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#define MAXCOUNTERS 100
#define MAXSIZE 10000000
extern double wtime();


int X[MAXSIZE];
int sum= 0;
int numcounters;
int size;
pthread_mutex_t lock;

void count(int *id)
{
int i,lsum;

lsum = 0;
for (i=*id;i<size;i+=numcounters)
  {
  lsum = lsum + X[i];
  }
  pthread_mutex_lock(&lock);
  sum = sum + lsum;
  pthread_mutex_unlock(&lock);
}

int main(int argc, char **argv)
{
int error,i,id;
pthread_t mytid, tid[MAXCOUNTERS];


if (argc == 1)
  {
  printf("usage: scount numcounters size\n");
  exit(1);
  }

if (argc == 2)
  {
  numcounters = atoi(argv[1]);
  }
if (argc == 3)
  {
  numcounters = atoi(argv[1]);
  size = atoi(argv[2]);
  }

printf("numcounters = %d, size = %d\n",numcounters, size);
for (i=0;i<size;i++)
  X[i] = 1;

pthread_setconcurrency(numcounters);
pthread_mutex_init(&lock,NULL);

for (id=0;id<numcounters;id++)
  {
  error = pthread_create(&tid[id],NULL,(void *(*)(void *))count, &id);
  }
for (id=0;id<numcounters;id++)
  {
  error = pthread_join(tid[id],NULL);
  }
printf("Counters finished with sum = %d\n",sum);
return 0;
}