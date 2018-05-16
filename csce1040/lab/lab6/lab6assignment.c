/*
Name: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 3/3/14
Instrucor: Keathly
Purpose: use linked lists to read in data and determine which list is longer, attach shorter list to longer list. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
  char   *name;
  float  balance;
  struct account *next;
};

int main()
{
  int	 listID;
  float  balance;
  char   name[20];
  struct account *list1head = NULL;
  struct account *list1tail = NULL;
  struct account *list2head = NULL;
  struct account *list2tail = NULL;
  struct account *walk = NULL;

  while(scanf("%d%s%f", &listID, name, &balance) != EOF) 
  {
		if(listID == 1) 
		{
			if(list1head == NULL) 
			{
				// ENTER CODE HERE
				list1head = (struct account *) malloc(sizeof(struct account));
				list1head->next = NULL;
				list1tail = list1head;	
    			}
			else 
			{
				// ENTER CODE HERE
				list1tail->next = (struct account *) malloc(sizeof(struct account));
				list1tail = list1tail->next;
				list1tail->next = NULL;
			}
			// save the information for list 1
			list1tail->name = (char *) malloc(sizeof(char) *strlen(name) + 1);
			strcpy(list1tail->name, name);
			list1tail->balance = balance;
		}
		else 
		{ // listID == 2
      			if(list2head == NULL) 
			{
				// ENTER CODE HERE
				list2head = (struct account *) malloc(sizeof(struct account));
				list2head->next = NULL;
				list2tail = list2head;
      			}
      			else 
			{
				// ENTER CODE HERE
				list2tail->next = (struct account *) malloc(sizeof(struct account));
				list2tail = list2tail->next;
				list2tail->next = NULL;
      			}
			// save the information for list 2
			list2tail->name = (char *) malloc(sizeof(char) *strlen(name) + 1);
			strcpy(list2tail->name, name);
			list2tail->balance = balance;
		}
		
  }

	// ENTER CODE HERE TO COUNT THE NODES IN EACH LIST
	int list1count, list2count; // counters for each list
	list1count = 0;
	list2count = 0;
	
	// walk through each list and increment the count of each list until the end of each list is reached
	walk = list1head; 
	while(walk != NULL)
	{
		walk = walk->next;
		list1count++;
	}

	walk = list2head;
	while(walk != NULL)
	{
		walk = walk->next;
		list2count++;
	}
	


	// ENTER CODE HERE TO ATTACH THE SHORTER LIST TO THE LONGER LIST
	if(list1count > list2count) //list 2 is shorter
	{
		*list1tail = *list2head; // use pointers when setting the last pointer to point to the first
	}
	else // list 1 is shorter
	{
		*list2tail = *list2head; // use pointer to make the last pointer to point to the first
	}

	// print list1
	printf("---------- List 1 ----------\n");
	walk = list1head;
  	while(walk != NULL) 
	{
   		 printf("%20s %8.2f\n", walk->name, walk->balance);
   		 walk = walk->next;
  	}
	// print list2
	printf("--------- List 2 ----------\n");
	walk = list2head;
  	while(walk != NULL) 
	{
    		printf("%20s %8.2f\n", walk->name, walk->balance);
    		walk = walk->next;
  	}


  return;
}
