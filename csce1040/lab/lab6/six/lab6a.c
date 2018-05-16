#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct weapon {
  char          *name;
  int           price;
  struct weapon *next;
};

int main()
{
  int   price;
  char  item[20];
  struct weapon *head = NULL;
  struct weapon *tail = NULL;
  struct weapon *walk = NULL;
  struct weapon *temp = NULL;

  while(scanf("%s%d", item, &price) != EOF) {
    printf("Read in: %s %d\n", item, price);
    if(head == NULL) {

      head = (struct weapon *) malloc(sizeof(struct weapon));
      head->next = NULL;
      tail = head;
    }
    else { // the list already has nodes

      tail->next = (struct weapon *) malloc(sizeof(struct weapon));
      tail = tail->next;
      tail->next = NULL;
    }

    tail->name = (char *) malloc(sizeof(char) * strlen(item) + 1);
    strcpy(tail->name, item);
    tail->price = price;
  }
  // print the list
  printf("---------- The original list: -----\n");

  walk = head;

  while(walk != NULL) 
  {
	printf("%20s %4d\n", walk->name, walk->price);
	walk = walk->next;
  }

  // remove the items from the list
  temp = head;
  while(temp != NULL)
  {
  	head = head->next;
  	temp->name[0] = '\0'; 	// reinitialize the name string
  	temp->price = 0;	// reinitialize the price
  	free(temp->name);	// return the string memory to the system
  	free(temp);		// return the node memory to the system
  	temp = head;		// set temp to null (the adress is illegal)
	// print the current list
	printf("---------- The current list: -----\n");
	walk = head;
	while(walk != NULL)
	{
		printf("%20s %4d\n", walk->name, walk->price);
		walk = walk->next;
	}
  }

  // INSERT CODE HERE

  return;
}
