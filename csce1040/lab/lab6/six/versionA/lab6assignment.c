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
	int		 listID;
  float  balance;
  char   name[20];
  struct account *list1head = NULL;
  struct account *list1tail = NULL;
	struct account *list2head = NULL;
  struct account *list2tail = NULL;
  struct account *walk = NULL;

  while(scanf("%d%s%f", &listID, name, &balance) != EOF) {
		if(listID == 1) {
			if(list1head == NULL) {

				// ENTER CODE HERE

    	}
			else {

				// ENTER CODE HERE

			}
		}
		else { // listID == 2
      if(list2head == NULL) {

				// ENTER CODE HERE

      }
      else {

				// ENTER CODE HERE

      }
		}
  }

	// ENTER CODE HERE TO COUNT THE NODES IN EACH LIST

	// ENTER CODE HERE TO ATTACH THE SHORTER LIST TO THE LONGER LIST

	// print list1
	walk = list1head;
  while(walk != NULL) {
    printf("%20s %8.2f\n", walk->name, walk->balance);
    walk = walk->next;
  }
	// print list2
	printf("----------------\n");
	walk = list2head;
  while(walk != NULL) {
    printf("%20s %8.2f\n", walk->name, walk->balance);
    walk = walk->next;
  }


  return;
}
