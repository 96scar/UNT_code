/*
Author: Scarlett Jones (ScarlettJones@my.unt.edu)
Date: 10/11/14
Instructor: Mark Thompson
Description: An online store that uses a tax rate, shipping cost, discounts, while loop, for loop, and switch statements. 
*/

/*This is a preprocessor directive that tells the preprocessor to include a copy of the standard input/output library in the progrem.*/
#include <stdio.h>

/*This defines the tax rate as 8.25%, the shipping cost as $25, and the discount price as 90% of the price, or 10% off.*/
#define TAX_RATE 	1.0825
#define SHIPPING_COST 	25
#define DISCOUNT_PRICE 	0.90

/*The function main takes no arguments and returns an int value.*/
int main()
{
	/*Initially displays the department and course number, program number, my name, my EUID, and my e-mail address*/
	printf("\nCSCE 1030");
	printf("\nProgram 3");
	printf("\nScarlett Jones");
	printf("\nsrj0101");
	printf("\nScarlettJones@my.unt.edu\n");

	/*Prints out a welcome message to the store.*/
	printf("\nWelcome to The Office Store!\n");

	/*Defines menu as an int value. Initializes menu as 1 so that the while loop will begin.*/
	int menu;
	menu 		= 1;

	/*Defines chairs, cabinets, desks, bookcases, subtotal, items, total, and shipping as doubles. 
	Initializes chairs, cabinets, desks, bookcases, and subtotal as 0.*/
	double chairs, cabinets, desks, bookcases, subtotal, items, total, shipping;
	chairs 		= 0;
	cabinets 	= 0;
	desks 		= 0;
	bookcases 	= 0;
	subtotal 	= 0;

	/*The while loop checks to see if the input for menu is between 1 and 5. If it isn't, the while loop will end.*/
	while (menu >= 1 && menu <= 5)
	{
		/*Sets items equal to 1, checks to see if items is greater than or equal to 0, and has no increment. 
		Later, when I set items equal to -1, the for loop will end.*/
		for (items = 1 ; items >= 0 ; )
		{
			/*Asks the user to choose a menu number.*/
		        printf("\nInput the number corresponding to the product you wish to purchase:");

			/*Prints out the menu options for the cost of the store items available.*/
	                printf("\n1: Office Chairs   $59.99 each");
			printf("\n2: File Cabinets   $29.99 each");
			printf("\n3: Desks           $99.99 each");
			printf("\n4: Bookcases       $44.99 each");
			printf("\n5: Checkout\n");

        	        /*Asks the user for input on the menu number they want, the item they want to buy.*/
                	scanf("%d", &menu);

			/*The switch statement depends on which menu number the user chooses. These are the different cases. 
			The default is if the user doesn't input a correct menu number.*/
			switch(menu)
			{
				/*Case 1 (Office Chairs) asks how many office chairs the user would like. The price of one chair, $59.99, is multiplied by items, 
				the amount of chairs the user wants. The current subtotal is printed out.*/
				case 1:  printf("How many office chairs would you like? ");
					 scanf("%lf", &items);
					 chairs = 59.99;
					 chairs *= items;
					 printf("\nCurrent Subtotal: $%.2lf.\n", chairs + cabinets + desks + bookcases);
					 break;
				/*Case 2 (File Cabinets) asks how many file cabinets the user would like. The price of one file cabinet, $29.99, is multiplied 
				by items, the amount of cabinets the user wants. The current subtotal is printed out.*/
				case 2:  printf("How many file cabinets would you like? ");
					 scanf("%lf", &items);
					 cabinets = 29.99;
					 cabinets *= items;
					 printf("\nCurrent Subtotal: $%.2lf.\n", chairs + cabinets + desks + bookcases);
					 break;
				/*Case 3 (desks) asks how many desks the user would like. The price of one desk, $99.99, is multiplied by items, the amount 
				of cabinets the user wants. The current subtotal is printed out.*/
				case 3:  printf("How many desks would you like? ");
					 scanf("%lf", &items);
					 desks = 99.99;
					 desks *= items;
					 printf("\nCurrent Subtotal: $%.2lf.\n", chairs + cabinets + desks + bookcases);
					 break;
				/*Case 4 (bookcases) asks how many bookcases the user would like. The price of one bookcase, $44.99, is multiplied by items, 
				the amount of cabinets the user wants. The current subtotal is printed out.*/
				case 4:  printf("How many bookcases would you like? ");
					 scanf("%lf", &items);
					 bookcases = 44.99;
					 bookcases *= items;
					 printf("\nCurrent Subtotal: $%.2lf.\n", chairs + cabinets + desks + bookcases);
					 break;
				/*Case 5 (checkout) adds up the cost of chairs, cabinets, desks, and bookcases. If the subtotal is greater than or equal to $500, 
				a discount of 10% off is taken. Otherwise, there is an empty statement, because no discount is given. If the subtotal is greater 
				than 0, the total is equal to the subtotal times the tax rate times the shipping cost. Shipping is equal to shipping cost. Otherwise, 
				the total is equal to 0 and shipping is equal to 0.*/
				case 5:  subtotal = chairs + cabinets + desks + bookcases;
					 if (subtotal >= 500)
					 	subtotal *= DISCOUNT_PRICE;
					 else
					 	;

					 if (subtotal > 0)
					 {
					 	total = subtotal * TAX_RATE + SHIPPING_COST;
						shipping = SHIPPING_COST;
					 }
					 else
					 {
					 	total = 0;
					 	shipping = SHIPPING_COST * 0;
					 }
					 /*A thank you message and a receipt is printed out,showing the total cost of each type of item, the subtotal, 
					 the discount, the tax, the shipping cost, and the total.*/
					 printf("\nThank you for shopping at The Office Store!");
	        		         printf("\nOffice Chairs: $%.2lf", chairs);
		            	         printf("\nFile Cabinets: $%.2lf", cabinets);
          			         printf("\nDesks:         $%.2lf", desks);
    			                 printf("\nBookcases:     $%.2lf", bookcases);
   			                 printf("\nSubtotal:      $%.2lf", chairs + cabinets + desks + bookcases);
			                 printf("\nDiscount:      $%.2lf", -(chairs + cabinets + desks + bookcases - subtotal));
			                 printf("\nTax:           $%.2lf", subtotal * TAX_RATE - subtotal);
			                 printf("\nShipping:      $%.2lf", shipping);
			                 printf("\nTotal:         $%.2lf\n", total);
					 
					 menu = 6;
					 items = -1;
					 break;
				/*Prints out an error message, teling the user to input a correct menu number. Resets the menu to 1 so the while loop will continue, 
				and sets items to -1 so the for loop will exit.*/
				default: printf("\nPlease input a correct menu number.\n");
					 menu = 1;
					 items = -1;
					 break;
			}
		}		
	}

	/*This returns the function main to zero, an int, so that the compiler will work.*/
	return 0;
}
