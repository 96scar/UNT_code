#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string> 
#include <list>
#include <fstream>
#include <cctype>
#include <iomanip>
#include "JonS_00_P2_header.h"

using namespace std;

person::person() {}
string person::getName() {return name;}
int person::getID() {return ID;}
person::person(string n, int id)
{
	name = n;
	ID = id;
}

people::people() //constructor
{
	count = 1;
}

people::~people() //destructor
{
	if(ppl.empty()) // so you don't try to delete something that's not there
	{
		return;
	}
	else
	{
		ppl.clear(); // clear all of list
	}
}

void people::add(string name) // add new element to list
{
	for(iter = ppl.begin(); iter != ppl.end(); iter++)
	{
		if(iter->getName() == name)
		{
			cout << "DUPLICATE: " << name << endl;
			return; // exits the function if there is a duplicate
		}
		else
		{
			;
		}
	}	
	
	p = person(name, count);
	ppl.push_back(p);
	cout << "ADDED: id" << setfill('0') << setw(3) << count << " " << name << endl;
	count++;

	return;
}

void people::search(string name) // search for person in list
{
	for(iter = ppl.begin(); iter != ppl.end(); iter++)
	{
		if(iter->getName() == name)
		{
			cout << "TRUE: " << name << endl;
			return; // returns if the name was found
		}
		else
		{
			;
		}
	}
	
	//if the name wasn't found it gets to here
	cout << "FALSE: " << name << endl;
	
	return;
}

void people::remove(string name) // remove person from list
{
	for(iter = ppl.begin(); iter != ppl.end(); iter++)
	{
		if(iter->getName() == name)
		{
			iter = ppl.erase(iter); //used http://www.cplusplus.com/reference/list/list/erase/
			cout << "Removal Successful: " << name << endl;
			return; //returns if removed
		}
		else
		{
			;
		}
	}
	
	// if it wasn't removed it gets to here
	cout << "ERROR: Not found for Removal: " << name << endl;
	
	return;
}

void people::print() // print the list alphabetized
{
	//ppl.sort(); // why won't this work??? It works in other practice programs I've done.
				  // I need to sort the list<class> alphabetically based on members of the class
	
	if(ppl.empty()) // checks if the list is empty
	{
		cout << "NO NAMES IN LIST" << endl;
		return; // leaves the function
	}
	else
	{
		;
	}
	for(iter = ppl.begin(); iter != ppl.end(); iter++)
	{
		cout << "id" << setfill('0')<< setw(3) << iter->getID() << " "; //prints out id
		cout << iter->getName() << endl; //prints out name
	}
	
	return;
}

void people::file(string filename) // get input from file
{
	ifstream input;
	string str;
	
	input.open(filename.c_str()); // used c_str() to be in the right type
	if(input.fail()) // if the file does not exist
	{
		cout << "Input file opening failed." << endl;
		exit(1); // it will exit
	}
	
	while(getline(input, str))
	{
		int commaPos = str.find(',');
		string prefix = str.substr(0, commaPos); // from beginning to comma
		string suffix = str.substr(commaPos+1); // the rest of the line

		if(prefix == "print" || prefix == "PRINT") //only needs 1 input
		{
			suffix = '\n';
		}
		else
		{
			;
		}

		if(prefix == "add" || prefix == "ADD")
		{
			for(int j = 0; j < suffix.length(); j++) // convert name to correct format
			{
				if(j == 0)
				{
					suffix.at(j) = toupper(suffix.at(j)); //first letter to uppercase
				}
				else
				{
					suffix.at(j) = tolower(suffix.at(j)); // the rest of the letters to lowercase
				}		
			}
			add(suffix); 
		}
		else if(prefix == "search" || prefix == "SEARCH")
		{
			for(int j = 0; j < suffix.length(); j++) // convert name to correct format
			{
				if(j == 0)
				{
					suffix.at(j) = toupper(suffix.at(j)); //first letter to uppercase
				}
				else
				{
					suffix.at(j) = tolower(suffix.at(j)); // the rest of the letters to lowercase
				}		
			}
			
			search(suffix); 
		}
		else if(prefix == "remove" || prefix == "REMOVE")
		{
			for(int j = 0; j < suffix.length(); j++) // convert name to correct format
			{
				if(j == 0)
				{
					suffix.at(j) = toupper(suffix.at(j)); //first letter to uppercase
				}
				else
				{
					suffix.at(j) = tolower(suffix.at(j)); // the rest of the letters to lowercase
				}		
			}
			
			remove(suffix); 
		}
		else if(prefix == "print" || prefix == "PRINT")
		{
			print(); 
		}
		else
		{
			cout << "Not a valid command." << endl;
		}
	}
	
	input.close();
	
	return;
}