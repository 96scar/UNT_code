#include <stdio.h>
#include <stdlib.h>

#define CHUNKSIZE 2

typedef struct
{
   int item_id;
   float price;
}  item;

typedef struct
{
  int cust_id;
  char  cust_name[80];
} customer;

typedef struct
{
  int order_id;
  int cust_loc;
  int item_loc;
}  order;

typedef struct
{
  int cust_cnt;
  int cust_cap;
  customer *cust_list;
} customers;

typedef struct
{
  int item_cnt;
  int item_cap;
  item *item_list;
} items;

typedef struct
{
  int order_cnt;
  int order_cap;
  order *order_list;
} orders;

void additem(items * stuff)
{
  int id; float pr;
  if (stuff->item_cnt == stuff->item_cap) 
  {
    item *temp;
    temp = (item *) realloc(stuff->item_list, sizeof(item) *(stuff->item_cap + CHUNKSIZE));
    stuff->item_cap += CHUNKSIZE;
    stuff->item_list = temp;
  }


  printf("Enter new item ID: ");
  scanf ("%d%*c", &(stuff->item_list[stuff->item_cnt].item_id));
  printf ("Enter cost: ");
  scanf ("%f%*c", &(stuff->item_list[stuff->item_cnt].price));
  stuff->item_cnt += 1;
}

void addcustomer(customers * peeps)
{
  int id; char temp[80];
    
    if (peeps->cust_cnt == peeps->cust_cap)
    {
        customer *temp;
        temp = (customer *) realloc(peeps->cust_list, sizeof(customer) *(peeps->cust_cap + CHUNKSIZE));
        peeps->cust_cap += CHUNKSIZE;
        peeps->cust_list = temp;
    }

  printf("Enter new customer ID: ");
  scanf ("%d%*c", &(peeps->cust_list[peeps->cust_cnt].cust_id));
  printf ("Enter name: ");
  fgets(peeps->cust_list[peeps->cust_cnt].cust_name, 80, stdin) ;
  peeps->cust_cnt += 1;
}

void addorder(orders * stuff)
{
  int id; int cs; int iid;
    if (stuff->order_cnt == stuff->order_cap)
    {
        order *temp;
        temp = (order *) realloc(stuff->order_list, sizeof(order) *(stuff->order_cap + CHUNKSIZE));
        stuff->order_cap += CHUNKSIZE;
        stuff->order_list = temp;
    }


  printf("Enter new order id: ");
  scanf ("%d%*c", &(stuff->order_list[stuff->order_cnt].order_id));
  printf ("Enter customer ID for order: ");
  scanf ("%d%*c", &(stuff->order_list[stuff->order_cnt].cust_loc));
 printf ("Enter item ID for order: ");
  scanf ("%d%*c", &(stuff->order_list[stuff->order_cnt].item_loc));
  stuff->order_cnt += 1;
}

void prtcustomers(customers * cs)
{
  int i;
  for ( i=0; i < cs->cust_cnt; i++)
  {

    printf ("Customer id: %d  Name: %s\n", cs->cust_list[i].cust_id, cs->cust_list[i].cust_name);
  }
}


void prtitems(items *stuff)
{
 int i;
  for ( i=0; i < stuff->item_cnt; i++)
  {

    printf ("Item id: %d  Price: %f\n", stuff->item_list[i].item_id, stuff->item_list[i].price);
  }
}


void prtsales(orders *stuff)
{
  int i;
  for ( i=0; i < stuff->order_cnt; i++)
  {

    printf ("Order id: %d  Customer ID: %d  Item ID: %d\n", stuff->order_list[i].order_id, stuff->order_list[i].cust_loc, stuff->order_list[i].item_loc);
  }
}


main ()
{

  customers custs;
  items inventory;
  orders sales;
  int choice = -1;
  custs.cust_cnt=0;
  inventory.item_cnt=0;
  sales.order_cnt=0;
  custs.cust_cap = inventory.item_cap = sales.order_cap = CHUNKSIZE;
  
  custs.cust_list = (customer *)malloc (sizeof(customer) * CHUNKSIZE);
  sales.order_list = (order *)malloc (sizeof(order) * CHUNKSIZE);
  inventory.item_list = (item *)malloc (sizeof(item) * CHUNKSIZE);

  while (choice != 0)
  {
    printf ("What do you want to do?\n");
    printf (" 0 - quit\n 1 - Add item\n 2 - Add customer\n 3 - Add order\n 4 - print customers\n 5 - print items\n 6 - print orders\n");
    printf ("Enter your selection: ");
    scanf ("%d%*c", &choice);

    switch (choice)
    {

      case 1: additem(&inventory); break;
      case 2: addcustomer(&custs); break;
      case 3: addorder(&sales);break;
      case 4: prtcustomers(&custs);break;
      case 5: prtitems(&inventory);break;
      case 6: prtsales(&sales);break;
     }
  }
 free(inventory.item_list);
 free(sales.order_list);
 free(custs.cust_list);
}






