/*
Name: Scarlett Jones
Date: 4/16/15
Teacher: Keathly
Description: main file of library database
*/


#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include "header.h" // my own header file
using namespace std;

int main()
{
	patrons mypatrons; // to access the patrons class
	books mybooks; // to access the books class
	transactions mytrans; // to access the transactions class

	int menu=1; // so that the while loop will start
	
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
		cout << "Selection: ";	
		cin >> menu;
		cout << endl;
	     
		switch(menu)
		{
			case 0: cout << endl << "Exiting library database." << endl; break; // exit
			case 1: mypatrons.addPatron(); break; // add patron
			case 2: mybooks.addBook(); break; // add book
			case 3: mypatrons.deletePatron(); break; // remove patron
			case 4: mybooks.deleteBook(); break; // remove book
			case 5: mypatrons.editPatron(); break; // edit patron
			case 6: mybooks.editBook(); break; // edit book
			case 7: mytrans.addTran(); break; // check out book
			case 8: mytrans.deleteTran(); break; // check in book
			case 9: break; // add fines... I don't think that the library needs control of this from the menu
			case 10: break; // pay fines, if the patron hasn't paid fines yet
			case 11: mypatrons.printPatrons(); break; // print all patrons
			case 12: break; // print patrons with fines
			case 13: mypatrons.printAddresses(); break; //print out mailing addresses
			case 14: store(mypatrons, mybooks, mytrans); cout << endl << "Saving library database..." << endl; break; // save database
			case 15: load(mypatrons, mybooks, mytrans); cout << endl << "Loading library database..." << endl; break; // load database
			default: cout << endl << "Incorrect Menu selection." << endl;  break; // incorrect input on menu
		}
		cout << endl; // makes formatting look better
	}

	return 0;
}