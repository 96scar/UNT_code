/*Name: Scarlett Jones
Date: 5/4/15
Teacher: Keathly
Description: function, constructor, and destructor file of library database
*/

#include <iostream>
#include <cstdio>
#include <string> // not sure what difference between string and cstring are
#include <cstring>
#include <ctime> // learned about this from www.cplusplus.com
//#include <fstream> // learned abut it on cplusplus.com
#include "header.h"

using namespace std;

string patron::getName() { return name; }
int patron::getID() {return pID;}
string patron::getad() {return address;}
string patron::getCell() {return cell;}
string patron::getEmail() {return email;}
void patron::setNext (patron *n)  {next = n; }

patrons::patrons()
{
   pcnt = 0;
   top = bottom = NULL;
}
    
patrons::~patrons()
{
	if(top == NULL) // so that the destructor doesn't delete something that isn't there
	{
		return;
	}
	else
	{
    patron * now = top;
    while (now != bottom)
    {
	patron * next = now->getNext();
	delete now;
	now = next;
    }
	}
}
    
    
void patrons::addPatron()
{
    string nm, ad, c, e;
    int id, i=0;
    patron *temp, *temp2;
    temp2 = top;
		
    cout << endl << "Enter patron name ";
	cin.ignore();
    getline(cin, nm);
    cout << endl << "Enter patron ID ";
    cin >> id;
    cout << endl << "Enter patron address ";
	cin.ignore();
    getline(cin, ad);
	cout << endl << "Enter patron's phone number ";
	getline(cin, c);
	cout << endl << "Enter patron's email ";
	getline(cin, e);
        
    temp = new patron (nm, id, ad, c, e);
    if (pcnt == 0)
    {
		top = bottom = temp;
		temp->setNext(NULL);
        pcnt++;
    }         
    else
    {
        bottom->setNext(temp);
        bottom = temp;
        temp->setNext(NULL);
        pcnt++;
    }        
}
             
void patrons::printPatrons()
{
	patron *now;
	now = top;
	if(top == NULL)
	{
		cout << "No patrons." << endl;
		return;
	}
    while (now != NULL)
    {
        cout << "Patron: " << now->getName() << endl;
        cout << "ID: " << now->getID() << endl;
        cout << "address: " << now->getad() << endl;
		cout << "Phone number: " << now->getCell() << endl;
		cout << "Email: " << now->getEmail() << endl << endl;
        now = now->getNext();
    }
                 
}
			 
void patrons::printAddresses()
{
	patron *now = top;
	if(top == NULL)
	{
		cout << "No mailing addresses." << endl;
		return;
	}
	while(now != NULL)
	{
		cout << "Patron: " << now->getName() << endl;
		cout << "Address: " << now->getad() << endl << endl;
		now = now->getNext();
	}
}

void patrons::deletePatron() // got help from runnable.com to learn how to delete items in a linked list
{	
	string nm, ad, c, e;
	int id, i=0;
	patron *temp, *temp2, *now, *pre, *del;
	pre = NULL;
	del = NULL;
	now = top;
	
	cout << "Enter patron ID: ";
	cin >> id;
	cin.ignore();
	
	while(now != NULL)
	{
		if(id == now->getID())
		{
			if(top->getID() == now->getID()) // deleting the top
			{
				del = top;
				top = del->getNext();
				delete del;
				pcnt--;
				return;
			}
			pre = top;
			del = top->getNext();
			
			while(del != NULL)
			{
				if(del->getID() == id) // deleting other than the top
				{
					pre = del; // check this part
					if(del == bottom) // deleting bottom
					{
						bottom = pre;
						//now = bottom; // trying this now
					}
					delete del;
					pcnt--;
					break;
				}
				pre = del;
				del = del->getNext();
				//pcnt--;
			}
		}
		else
		{
			;
		}
	} 
	temp->getNext();
}

void patrons::editPatron()
{
	patrons::deletePatron();
	patrons::addPatron();
}

string book::getTitle() {return title;}
string book::getAuthor() {return author;}
int book::getID() {return bID;}
double book::getCost() {return cost;}
void book::setNext(book *n) {next = n;}

books::books()
{
   bcnt = 0;
   top = bottom = NULL;
}
    
books::~books()
{
	if(top == NULL)
	{
		return;
	}
	else
	{
	book * now = top;
    while (now != bottom)
    {
		book * next = now->getNext();
		delete now;
		now = next;
    }
	}
}

void books::addBook()
{
    string t, a;
	double c;
    int bid, i=0;
    book *temp, *temp2;
    temp2 = top;
		
    cout << endl << "Enter book title ";
	cin.ignore();
    getline(cin, t);
    cout << endl << "Enter acquisition number ";
    cin >> bid;
    cout << endl << "Enter author ";
	cin.ignore();
    getline(cin, a);
	cout << endl << "Enter cost ";
	cin >> c;
        
    temp = new book (t, a, bid, c);
    if (bcnt == 0)
    {
		top = bottom = temp;
		temp->setNext(NULL);
        bcnt++;
    }         
    else
    {
        bottom->setNext(temp);
        bottom = temp;
        temp->setNext(NULL);
        bcnt++;
    }        
}

void books::deleteBook()
{
	//string t, a;
	int bid, i=0;
	book *temp, *temp2, *now, *pre, *del;
	pre = NULL;
	del = NULL;
	now = top;
	
	cout << "Enter book acquisition number: ";
	cin >> bid;
	cin.ignore();
	
	while(now != NULL)
	{
		if(bid == now->getID())
		{
			if(top->getID() == now->getID()) // deleting the top
			{
				del = top;
				top = del->getNext();
				delete del;
				bcnt--;
				return;
			}
			pre = top;
			del = top->getNext();
			
			while(del != NULL)
			{
				if(del->getID() == bid) // deleting other than the top
				{
					pre = del; // check this part
					if(del == bottom) // deleting bottom
					{
						bottom = pre;
					}
					delete del;
					break;
				}
				pre = del;
				del = del->getNext();
				bcnt--;
			}
		}
		else
		{
			;
		}
	} 
	temp->getNext();
	
}

void books::editBook()
{
	books::deleteBook();
	books::addBook();
}

void books::printBooks()
{
	book *now = top;
	if(top == NULL)
	{
		cout << "No books." << endl;
		return;
	}
	while(now != NULL)
	{
		cout << "Title: " << now->getTitle() << endl;
		cout << "Author: " << now->getAuthor() << endl;
		cout << "Acquisition Number: " << now->getID() << endl;
		cout << "Cost: " << now->getCost() << endl << endl;
		now = now->getNext();
	}
}

int transaction::getID() {return tID;}
int transaction::getPLOC() {return patron_loc;}
int transaction::getBLOC(){return book_loc;}
time_t transaction::getStart() {return start;}
int transaction::getPeriod() {return period;}
time_t transaction::getEnd() {return end;}
void transaction::setNext(transaction *n) {next = n;}

transactions::transactions()
{
	tcnt = 0;
	top = bottom = NULL;
}

transactions::~transactions()
{
	if(top == NULL)
	{
		return;
	}
	else
	{
	transaction * now = top;
	while(now != bottom)
	{
		transaction * next = now->getNext();
		delete now;
		now = next;
	}
	}
}

void transactions::addTran()
{
	int tid, pLOC, bLOC, i=0;
	time_t s, e;
	int p;
	transaction *temp, *temp2;
	temp2 = top;
	
	cout << endl << "Enter transaction ID: ";
	cin >> tid;
	cin.ignore();
	cout << endl << "Enter patron ID: ";
	cin >> pLOC;
	cin.ignore();
	cout << endl << "Enter book acquisition number: ";
	cin >> bLOC;
	cin.ignore();
	time(&s);
	cout << "Checkout Time: " << ctime(&s) << endl;
	cout << endl << "Enter checkout length in days: ";
	cin >> p;
	cin.ignore();
	p *= 86400; // how many seconds there are in a day
	e = s + p;
	cout << "Time to Check in: " << ctime(&e) << endl;
	
	temp = new transaction(tid, pLOC, bLOC, s, p, e);
	if(tcnt == 0)
	{
		top = bottom = temp;
		temp->setNext(NULL);
        tcnt++;
    }         
    else
    {
        bottom->setNext(temp);
        bottom = temp;
        temp->setNext(NULL);
        tcnt++;
    }        
}

void transactions::deleteTran()
{
	int tid, pLOC, bLOC, i=0, p, compare;
	time_t s, e, current;
	transaction *temp, *temp2, *now, *pre, *del;
	pre = NULL;
	del = NULL;
	now = top;
	
	cout << "Enter transaction number: ";
	cin >> tid;
	cin.ignore();
	time(&current);
	
		while(now != NULL)
		{
			if(current > now->getEnd())
			{
				
				cout << endl << "Cannot turn in book until fines are paid." << endl;
				
				return;
			}
			if(tid == now->getID())
			{
				if(top->getID() == now->getID()) // deleting the top
				{
					del = top;
					top = del->getNext();
					delete del;
					tcnt--;
					return;
				}
				pre = top;
				del = top->getNext();
				
				while(del != NULL)
				{
					if(del->getID() == tid) // deleting other than the top
					{
						pre = del; // check this part
						if(del == bottom) // deleting bottom
						{
							bottom = pre;
						}	
						delete del;
						break;
					}
					pre = del;
					del = del->getNext();
					tcnt--;
				}
			}
			else
			{
				;
			}
		} 
		temp->getNext();
}

void transactions::printTran()
{
		transaction *now = top;
	if(top == NULL)
	{
		cout << "No items checked out." << endl;
		return;
	}
	while(now != NULL)
	{
		cout << "Transaction ID: " << now->getID() << endl;
		cout << "Patron: " << now->getPLOC() << endl;
		cout << "Book: " << now->getBLOC() << endl;
		now = now->getNext();
	}
}

void transactions::printLate()
{
	time_t current;
	transaction *now = top;
	
	if(top == NULL)
	{
		cout << "No patrons with fines.";
	}
	while(now != NULL)
	{
		if((time(&current)) > now->getEnd()) // if it's late
		{
			cout << difftime(current, now->getEnd()) << " seconds late" << endl;
			//show fines for how late they are
			cout << "Transaction ID: " << now->getID() << endl;
			cout << "Patron: " << now->getPLOC() << endl;
			cout << "Book: " << now->getBLOC() << endl;
			cout << endl;
		}
		now = now->getNext();
	}
}

void store(patrons p, books b, transactions t)
{
/*	FILE *save;
	
	save = fopen("library", "wb");
	
	fwrite(p, sizeof(patrons), 1, save);
	fwrite(b, sizeof(books), 1, save);
	fwrite(t, sizeof(transactions), 1, save);
	
	cout << endl << "Library saved." << endl;
	
	fclose(save);
*/	
}
void load(patrons p, books b, transactions t)
{
/*	FILE *save;
	
	if((save = fopen("library", "rb")) != NULL)
	{
		save = fopen("library", "rb");
		fread(p, sizeof(patrons), 1, save);
		fread(b, sizeof(books), 1, save);
		fread(t, sizeof(transactions), 1, save);
		fclose(save);
		cout << endl <<  "Library loaded." << endl;
	}
	else
	{
		cout << endl << "File doesn't exist." << endl;
	}
*/
}