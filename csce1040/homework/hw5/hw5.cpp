/*
Name: Scarlett Jones (ScarlettJOnes@my.unt.edu)
Teacher: Keathly
Date: 4/16/15
Description: the main file for the library system
*/

#include <iostream>
#include <string>
#include "header.h"

using namespace std;

int main()
{
	patrons mypatrons;
	int menu=1;
	
	// Initially displaying my information and information about this program.
	cout << "CSCE 1040" << endl << "Program 5" << endl << "Scarlett Jones" << endl << "ScarlettJones@my.unt.edu" << endl;

	while(menu != 0)
	{
		cout << "Choose a menu item" << endl;
		cout << " 0: Exit" << endl
		     << " 1: Add Patron" << endl
		     << " 2: Add Book" << endl
		     << " 3: Remove Patron" << endl
		     << " 4: Remove Book" << endl
		     << " 5: Edit Patron" << endl
		     << " 6: Edit Book" << endl
		     << " 7: Check out book" << endl
		     << " 8: Check in book" << endl
		     << " 9: Add Fines" << endl
		     << "10: Pay Fines" << endl
		     << "11: Print all patrons" << endl
		     << "12: Print patrons with fines" << endl
		     << "13: Print out all mailing addresses" << endl
		     << "14: Save database" << endl
		     << "15: Load database" << endl;
		cout << "Selction: ";	
		cin >> menu;
		cout << endl;
	     
		switch(menu)
		{
			case 0: cout << endl << "Exiting library database." << endl; break;
			case 1: mypatrons.addPatron(); break;
			case 2: break;
			case 3: break;
			case 4: break;
			case 5: break;
			case 6: break;
			case 7: break;
			case 8: break;
			case 9: break;
			case 10: break;
			case 11: mypatrons.printPatrons(); break;
			case 12: break;
			case 13: break;
			case 14: cout << endl << "Saving library database..." << endl; break;
			case 15: cout << endl << "Loading library database..." << endl; break;
			default: cout << endl << "Incorrect Menu selection." << endl;  break;
		}
		cout << endl;
	}

	return 0;
}
