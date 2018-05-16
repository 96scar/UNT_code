#include <stdio.h>

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
  customer cust_list[25];
} customers;

typedef struct
{
  int item_cnt;
  item item_list[100];
} items;

typedef struct
{
  int order_cnt;
  order order_list[150];
} orders;

void additem(items * stuff)
{
  int id; float pr;
  printf("Enter new item ID: ");
  scanf ("%d%*c", &(stuff->item_list[stuff->item_cnt].item_id));
  printf ("Enter cost: ");
  scanf ("%f%*c", &(stuff->item_list[stuff->item_cnt].price));
  stuff->item_cnt += 1;
}

void addcustomer(customers * peeps)
{
  int id; char temp[80];
  printf("Enter new customer ID: ");
  scanf ("%d%*c", &(peeps->cust_list[peeps->cust_cnt].cust_id));
  printf ("Enter name: ");
  fgets(peeps->cust_list[peeps->cust_cnt].cust_name, 80, stdin) ;
  peeps->cust_cnt += 1;
}

void addorder(orders * stuff)
{
  int id; int cs; int iid;

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
}
