/*
Author: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 10/22/2014
Purpose: This program is an online store that uses functions to calculate the subtotal, discount, and tax.
*/

/* This preprocessor directive tells the preprocessor to include a copy of the standard input/output library in the program.  */
#include <stdio.h>

#define CHAIR_PRICE 	59.99  /* chair price 		  */
#define CABINET_PRICE 	29.99  /* cabinet price	 	  */
#define DESK_PRICE 	99.99  /* desk price   		  */
#define BOOKCASE_PRICE 	44.99  /* bookcase price 	  */
#define TAX_RATE 	0.0825 /* tax rate of 8.25% 	  */
#define SHIPPING_COST 	25.00  /* shipping cost of $25.00 */

/* These function prototypes let the compiler know that it should expect these functions to be used and defined later in the program. */
void MyInfo(void);
int MenuOption(void);
float TotalCost(float object, float quantity, float chairs, float cabinets, float desks, float bookcases);
float discount(float cost);
float tax(float subtotal, float taxrate);

/* The function main takes no arguments and returns an int value. */
int main()
{
	int menu;
	menu = 1;

	float items, chairs, cabinets, desks, bookcases, subtotal, total, discountprice, shipping;
	chairs = 0;
	cabinets = 0;
	desks = 0;
	bookcases = 0;
	subtotal = 0;
	total = 0;

	/* Calls the function MyInfo. */
	MyInfo();

	/* Prints out a friendly welcoming message. */
	printf("Welcome to the CSCE 1030 StoreFront!\n\n");

	while (menu >= 1 && menu <= 5)
	{
		/* Calls the function MenuOption. */
		menu = MenuOption();
		
		switch (menu)
		{
			case 1:  /* Office Chairs */ 
				 printf("\nQuantity of Office Chairs: ");
				 scanf("%f", &items);
				 if (items >= 0)
				 {
				 	subtotal = TotalCost(CHAIR_PRICE, items, chairs, cabinets, desks, bookcases);
				 	chairs += CHAIR_PRICE * items;
				 }
				 else 
				 	printf("\nYou cannot buy a negative number of office chairs.\n\n");
				 break;
			case 2:  /* File Cabinets */
				 printf("\nQuantity of File Cabinets: ");
                                 scanf("%f", &items);
				 if (items >= 0)
				 {
				 	subtotal = TotalCost(CABINET_PRICE, items, chairs, cabinets, desks, bookcases);
				 	cabinets += CABINET_PRICE * items;
				 }
				 else
				 	printf("\nYou cannot buy a negative number of file cabinets.");
				 break;
			case 3:  /* Desks */
				 printf("\nQuantity of Desks: ");
                                 scanf("%f", &items);
				 if (items >= 0)
				 {
				 	subtotal = TotalCost(DESK_PRICE, items, chairs, cabinets, desks, bookcases);
				 	desks += DESK_PRICE * items;
				 }
				 else
				 	printf("\nYou cannot buy a negative number of desks.\n\n");
				 break;
			case 4:  /* Bookcases */
				 printf("\nQuantity of Bookcases: ");
                                 scanf("%f", &items);
				 if (items >= 0)
				 {
				 	subtotal = TotalCost(BOOKCASE_PRICE, items, chairs, cabinets, desks, bookcases);
				 	bookcases += BOOKCASE_PRICE * items;
				 }
				 else
				 	printf("\nYou cannot buy a negative number of bookcases.\n\n");
				 break;
			case 5:  /* Checkout */
				 printf("\n\nThank you for shopping at the CSCE 1030 StoreFront!\n");
				 printf("\nOffice Chairs: $%.2f", chairs);
				 printf("\nFile Cabinets: $%.2f", cabinets);
				 printf("\nDesks:	       $%.2f", desks);
				 printf("\nBookcases:     $%.2f", bookcases);
				 printf("\nSubtotal:      $%.2f", subtotal);
				 discountprice = discount(subtotal);
				 total = tax(discountprice, TAX_RATE);
				 if (total > 0)
				 {
					shipping = SHIPPING_COST;
					printf("\nShipping:      $%.2f", shipping);
				 	printf("\nTotal:         $%.2f\n\n", total + shipping);
				 }
				 else
				 {
					shipping = 0;
					printf("\nShipping:      $%.2f", shipping);
					printf("\nTotal:         $%.2f\n\n", total);
				 }
				 menu = 6;
				 break;
			default: /* Error: incorrect input */
				 printf("\nPlease input a correct menu number.\n\n");
				 menu = 1;
				 break;
		}
	}

	/* This returns the function main to zero so that the compiler will work.  */
	return 0;
}


/*
Function: MyInfo
Parameters: none
Return: nothing
Description: This function prints out my personal information.
*/
void MyInfo(void)
{
	printf("\nCSCE 1030");
	printf("\nProgram 4");
	printf("\nScarlett Jones");
	printf("\nsrj0101");
	printf("\nScarlettJones@my.unt.edu\n\n");

	return;
}


/*
Function: MenuOption
Parameters: none
Return: an int called menu, which is the menu option chosen.
Description: This function prints out the menu.
*/
int MenuOption(void)
{
	int menu;

	printf("Enter the number corresponding to the product you wish to purchase:\n");
	printf("1: Office Chairs $59.99 each\n");
	printf("2: File Cabinets $29.99 each\n");
	printf("3: Desks	 $99.99 each\n");
	printf("4: Bookcases	 $44.99 each\n");
	printf("5: Checkout	 	    \n");	
	printf("Menu option chosen: ");
	scanf("%d", &menu);

	return menu;
}


/*
Function: TotalCost
Parameters: a float representing the cost of the object chosen, and a float representing the quantity of items to purchase
Return: a float, the subtotal after the cost of the object is multiplied by the amount of items wanted
Description: This function computes the total cost of the objects when given the number of items bought and the price per object
*/
float TotalCost(float object, float quantity, float chairs, float cabinets, float desks, float bookcases)
{
	float subtotal;
	subtotal = object * quantity + chairs + cabinets + desks + bookcases;

	printf("\nCurrent Subtotal: $%.2f\n\n", subtotal);

	return subtotal;
}


/*
Function: discount
Parameters: a float representing the cost of the items
Return: a float, the new cost after the discount is applied or is not applied
Description: This function computes the price after the discount is applied, if it needs to be, which is only if the price is over 500
*/
float discount(float cost)
{	
	float newcost;

	if (cost >= 500)
		newcost = cost * 0.90;
	else
		newcost = cost;
	
	printf("\nDiscount:      $%.2lf", cost - newcost);
	
	return newcost;
}


/*
Function: tax
Parameters: a float representing the subtotal, and a float representing the tax rate
Return: a float, the the cost of tax
Description: This function computes the cost of tax for the subtotal
*/
float tax(float subtotal, float taxrate)
{
	float taxamount;

	taxamount = subtotal * taxrate;

	printf("\nTax:           $%.2f", taxamount);

	return taxamount + subtotal;
}
