/*
Name: Scarlett Jones
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
//#include "bubble.h"

struct classStats{
	float mean;
	float min;
	float max;
	float median;
	char *name;
};

int main()
{
	// ENTER YOUR CODE HERE
	
	char class[100];	
	int i;

	struct classStats variable;

	struct student *student[19];


	
	scanf("%s", class);

	for(i = 0; i < 19; i++)
	{
		student[i] = malloc (sizeof(student));
	//	scanf("%s %s %d %d %d", student[i]->first, student[i]->last, student[i]->exam1, student[i]->exam2, student[i]->exam3);

	//	student[i]->mean = (student[i]->exam1 + student[i]->exam2 + student[i]->exam3)/3;
	}
	
/*	for(i = 0; i < 19; i++)
	{


		printf("%s %s %d %d %d %d", student[i]->first, student[i]->last, student[i]->exam1, student[i]->exam2, student[i]->exam3, student[i]->mean);
	}*/

	return 0;
}

