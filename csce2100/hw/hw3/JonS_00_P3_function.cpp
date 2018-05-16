#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string> 
#include <list>
#include <fstream>
#include <sstream>
#include <cctype>
#include <iomanip>
#include "JonS_00_P3_header.h"

using namespace std;

void commands()
{
	cout << endl << "Scarlett's Address Book" << endl;
	cout << "Available Commands" << endl;
	cout << "add name <name>" << endl
		 << "add spouse <uid> <name>" << endl
		 << "add child <uid> <name>" << endl
		 << "add address1 <uid> <address>" << endl
		 << "add city <uid> <city>" << endl
		 << "add state <uid> <state>" << endl
		 << "add zip <uid> <zipcode>" << endl
		 << "add date_birth <uid> <ddmmyyyy>" << endl
		 << "add date_wedding <uid> <ddmmyyyy>" << endl
		 << "add date_death <uid> <ddmmyyyy>" << endl
		 << "search <name>" << endl
		 << "print all" << endl
		 << "print <uid>" << endl
		 << "file <file>" << endl
		 << "commands" << endl
		 << "quit" << endl;
}

string convert(string word)
{
	for(int i = 0; i < word.length(); i++) // convert name to correct format
	{
		if(i == 0)
		{
			word.at(i) = toupper(word.at(i)); //first letter to uppercase
		}
		else
		{
			word.at(i) = tolower(word.at(i)); // the rest of the letters to lowercase
		}		
	}
	return word;
}

string capitalize(string word)
{
	for(int i = 0; i < word.length(); i++)
	{
		word.at(i) = toupper(word.at(i));
	}
	return word;
}

string lowercase(string word)
{
	for(int i = 0; i < word.length(); i++)
	{
		word.at(i) = tolower(word.at(i));
	}
	return word;
}

int people::duplicate(string first, string last)
{	
	for(iter = ppl.begin(); iter != ppl.end(); iter++)
	{
		if(iter->getFirst() == first && iter->getLast() == last)
		{
			cout << "DUPLICATE: " << first << " " << last << " UID: " << iter->getID() << endl;
			return 1; // exits the function if there is a duplicate
		}
		else
		{
			;
		}
	}
	
	return 0;
}

person::person() 
{
	childcount = 0;
}
string person::getFirst() {return first;}
string person::getLast() {return last;}
string person::getAddress() {return address1;}
string person::getCity() {return city;}
string person::getState() {return state;}
string person::getZip() {return zip;}
string person::getBirth() {return date_birth;}
string person::getDeath() {return date_death;}
string person::getWed() {return date_wedding;}
string person::getSpouseFirst() {return spousefirst;}
string person::getSpouseLast() {return spouselast;}
string person::getChildFirst() {return childfirst;}
string person::getChildLast() {return childlast;}
string person::getID() {return ID;}

void person::showChildren()
{
	int i;
	for(i = 0; i < 3; i++)
	{
		cout << "CHILD: " << child[i] << endl;
	}
}

void person::setName(string fs, string ls) 
{
	first = fs;
	last = ls;
}
void person::setAddress(string adr) {address1 = adr;}
void person::setCity(string c) {city = c;}
void person::setState(string st) {state = st;}
void person::setZip(string z) {zip = z;}
void person::setBirth(string birth) {date_birth = birth;}
void person::setDeath(string death) {date_death = death;}
void person::setWed(string wed) {date_wedding = wed;}
void person::setSpouse(string sfs, string sls)
{
	spousefirst = sfs;
	spouselast = sls;
}
void person::setChild(person *c, string cfs, string cls)
{
	childfirst = cfs;
	childlast = cls;
	
	child[childcount] = c;
	
	childcount++;
}
void person::setID(string id) {ID = id;}	

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


void people::addName(string first, string last)
{	
	if(duplicate(first, last) == 1)
	{
		return;// won't add if there is a duplicate
	}
	else
	{	
		string tid;
		stringstream s; // use this to be able to setfill and setw the id
		s.str(" ");
		s << "ID" << setfill('0') << setw(3) << count;
		tid = s.str(); // converting stringstream to string type
		p.setID(tid);
		p.setName(first, last);

	
		for(iter = ppl.begin(); iter != ppl.end(); iter++)
		{	
			if(last > iter->getLast()) // OR last name is greater than current iterator
			{
				iter++;
				if(iter == ppl.end())
				{
					iter--;
					ppl.push_back(p);
					cout << endl << "ADDED: " << first << " " << last << " " << "UID: " << tid << endl;
					count++;
					return;
				}
				if(last < iter->getLast()) // AND last name is less than next iterator
				{
					break;
				}
				else
				{
					iter--;//back to current iter
				}
			}	
			else if(last < iter->getLast()) // last name is less than current iterator
			{
					break;					
			}	
			else if(last == iter->getLast()) // OTHERWISE, last names are same, sort by first name
			{
				if(first > iter->getFirst()) // OR first name is greater than current iterator
				{
					iter++; // next iter
					if(first < iter->getFirst()) // AND first name is less than next iterator
					{
						break;
					}
					else
					{
						iter--; // back to current iter
					}
				}				
				else if(first < iter->getFirst()) // first name is less than current iterator
				{
						break;
				}
			}	
		}
		ppl.insert(iter, p);
		
		cout << endl << "ADDED: " << first << " " << last << " " << "UID: " << tid << endl;
		count++;
	}

	iter--;
	return;	
}

void people::addAddress(string address1, string ID)
{
	for(iter = ppl.begin(); iter != ppl.end(); iter++)
	{
		if(ID == iter->getID())
		{
			iter->setAddress(address1);
			cout << endl << "ADDED ADDRESS1: "; 
			cout << address1 << endl;
			cout << "UID: ";  
			cout << ID; 
			cout << endl;
			return;
		}
	}
	cout << endl << ID << " does not exist." << endl;
	return;
}

void people::addCity(string city, string ID)
{
	for(iter = ppl.begin(); iter != ppl.end(); iter++)
	{
		if(ID == iter->getID())
		{
			iter->setCity(city);
			cout << endl << "ADDED CITY: "; 
			cout << city << endl; 
			cout << "UID:  "; 
			cout << ID; 
			cout << endl;
			return;
		}
	}
	cout << endl << ID << " does not exist." << endl;
	return;	
}

void people::addState(string state, string ID)
{
	for(iter = ppl.begin(); iter != ppl.end(); iter++)
	{
		if(ID == iter->getID())
		{
			iter->setState(state);
			cout << endl << "ADDED STATE: "; 
			cout << state << endl;
			cout << "UID: "; 
			cout << ID; 
			cout << endl;
			return;
		}
	}
	cout << endl << ID << " does not exist." << endl;
	return;
}

void people::addZip(string zip, string ID)
{
	for(iter = ppl.begin(); iter != ppl.end(); iter++)
	{
		if(ID == iter->getID())
		{
			iter->setZip(zip);
			cout << endl << "ADDED ZIP: "; 
			cout << zip << endl;
			cout << "UID: "; 
			cout << ID; 
			cout << endl;
			return;
		}
	}
	cout << endl << ID << " does not exist." << endl;
	return;
}

void people::addBirth(string date_birth, string ID)
{
	for(iter = ppl.begin(); iter != ppl.end(); iter++)
	{
		if(ID == iter->getID())
		{
			iter->setBirth(date_birth);
			cout << endl << "ADDED BIRTHDAY: "; 
			cout << date_birth << endl; 
			cout << "UID: "; 
			cout << ID; 
			cout << endl;
			return;
		}
	}
	cout << endl << ID << " does not exist." << endl;
	return;
}

void people::addDeath(string date_death, string ID)
{
	for(iter = ppl.begin(); iter != ppl.end(); iter++)
	{
		if(ID == iter->getID())
		{
			iter->setDeath(date_death);
			cout << endl << "ADDED DATE of DEATH: "; 
			cout << date_death << endl;
			cout << "UID: "; 
			cout << ID; 
			cout << endl;
			return;
		}
	}
	cout << endl << ID << " does not exist." << endl;
	return;
}

void people::addWed(string date_wed, string ID)
{
	for(iter = ppl.begin(); iter != ppl.end(); iter++)
	{
		if(ID == iter->getID())
		{
			iter->setWed(date_wed);
			cout << endl << "ADDED WEDDING-DAY: "; 
			cout << date_wed << endl;
			cout << "UID: "; 
			cout << ID;
			cout << endl;
			return;
		}
	}
	cout << endl << ID << " does not exist." << endl;
	return;
}

void people::addSpouse(string spousefirst, string spouselast, string ID)
{
	if(duplicate(spousefirst, spouselast) == 1)
	{
		for(iter = ppl.begin(); iter != ppl.end(); iter++)
		{
			if(ID == iter->getID())
			{	
				iter->setSpouse(spousefirst, spouselast);
				return;
			}
		}
		cout << endl << ID << " does not exist." << endl;		
		
		return;// won't add if there is a duplicate, but will set spouse
	}
	else // not a duplicate, need to add to list
	{		
		for(iter = ppl.begin(); iter != ppl.end(); iter++)
		{
			if(ID == iter->getID())
			{
				iter->setSpouse(spousefirst, spouselast);
				addName(spousefirst, spouselast);
				return;
			}
		}
		cout << endl << ID << " does not exist." << endl;
		return;		
	}
}

void people::addChild(string childfirst, string childlast, string ID)
{
	if(duplicate(childfirst, childlast) == 1)
	{
		return;// won't add if there is a duplicate
	}
	else
	{
		for(iter = ppl.begin(); iter != ppl.end(); iter++)
		{
			if(ID == iter->getID())
			{
				iter->setChild(&p, childfirst, childlast);
				addName(childfirst, childlast);	
				return;
			}
		}
		cout << endl << ID << " does not exist." << endl;
		return;		
	}		
}

void people::search(string first, string last)
{
	for(iter = ppl.begin(); iter != ppl.end(); iter++)
	{
		if(convert(first) == iter->getFirst() && convert(last) == iter->getLast())
		{
			cout << endl << "FOUND: " << convert(first) << " " << convert(last) << " UID: " << iter->getID() << endl;
			return;
		}
		else
		{
			;
		}
	}
	cout << endl << "NOT FOUND: " << convert(first) << " " << convert(last) << endl;
	return;
}

void people::printAll()
{
	cout << endl;
	for(iter = ppl.begin(); iter != ppl.end(); iter++)
	{
		cout << setw(10) << left << iter->getFirst() << " ";
		cout << setw(10) << left << iter->getLast() << " ";
		cout << "UID: " << iter->getID() << endl;
	}
}

void people::printID(string ID)
{
	cout << endl;
	for(iter = ppl.begin(); iter != ppl.end(); iter++)
	{
		if(ID == iter->getID())
		{
			cout << "UID: " << iter->getID() << endl;
			cout << "NAME: " << iter->getFirst() << " " << iter->getLast() << endl;
			cout << "ADDRESS1: " << iter->getAddress() << endl;
			cout << "CITY: " << iter->getCity() << endl;
			cout << "STATE: " << iter->getState() << endl;
			cout << "ZIP: " << iter->getZip() << endl;
			cout << "DATE_BIRTH: " << iter->getBirth() << endl;
			cout << "DATE_DEATH: " << iter->getDeath() << endl;
			cout << "DATE_WEDDING: " << iter->getWed() << endl;
			cout << "SPOUSE: " << iter->getSpouseFirst() << " " << iter->getSpouseLast() << endl;
			iter->showChildren(); // for some reason this is printing out addresses
			cout << "CHILD: " << iter->getChildFirst() << " " << iter->getChildLast() << endl; // not right, only works for one then replaces it
			
			return;
		}
		else
		{
			;
		}
	}
	cout << ID << " does not exist." << endl;
	return;
}

void people::file(string filename)
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
		int commaPos1 = str.find(','); // find 1st comma
		string arg1 = str.substr(0, commaPos1); // from beginning to 1st comma
		string str2 = str.substr(commaPos1 + 1); // from 1st comma to the end
		int commaPos2 = str2.find(','); // find 2nd comma
		string arg2 = str2.substr(0, commaPos2); // from 1st comma to the 2nd comma
		string str3 = str2.substr(commaPos2 + 1); // from 2nd comma to the end
		int commaPos3 = str3.find(','); // find 3rd comma
		string arg3 = str3.substr(0, commaPos3); // from 2nd comma to 3rd comma
		string arg4 = str3.substr(commaPos3 + 1); // from 3rd comma to end
		
		string temp, prefix, suffix;
		int spacePos;
		
		arg1 = lowercase(arg1);
		if(arg1 == "add")
		{
			arg2 = lowercase(arg2);
			if(arg2 == "name")
			{
				temp = arg3;
				spacePos = temp.find(' ');
				prefix = temp.substr(0, spacePos); // from beginning to space
				suffix = temp.substr(spacePos+1); // the rest of the line			
				
				prefix = convert(prefix);
				suffix = convert(suffix);
				
				addName(prefix, suffix);
			}
			else if(arg2 == "spouse")
			{
				arg3 = capitalize(arg3);
				temp = arg4;
				spacePos = temp.find(' ');
				prefix = temp.substr(0, spacePos); // from beginning to space
				suffix = temp.substr(spacePos+1); // the rest of the line
				
				prefix = convert(prefix);
				suffix = convert(suffix);
				
				addSpouse(prefix, suffix, arg3);
			}
			else if(arg2 == "child")
			{
				arg3 = capitalize(arg3);
				temp = arg4;
				spacePos = temp.find(' ');
				prefix = temp.substr(0, spacePos); // from beginning to space
				suffix = temp.substr(spacePos+1); // the rest of the line
				
				prefix = convert(prefix);
				suffix = convert(suffix);

				addChild(prefix, suffix, arg3);
			}
			else if(arg2 == "address1")
			{
				arg3 = capitalize(arg3);
				addAddress(arg4, arg3);
			}
			else if(arg2 == "city")
			{
				arg3 = capitalize(arg3);
				addCity(arg4, arg3);
			}
			else if(arg2 == "state")
			{
				arg3 = capitalize(arg3);
				addState(arg4, arg3);
			}
			else if(arg2 == "zip")
			{
				arg3 = capitalize(arg3);
				addZip(arg4, arg3);
			}
			else if(arg2 == "date_birth")
			{
				arg3 = capitalize(arg3);
				addBirth(arg4, arg3);
			}
			else if(arg2 == "date_wedding")
			{
				arg3 = capitalize(arg3);
				addWed(arg4, arg3);
			}
			else if(arg2 == "date_death")
			{
				arg3 = capitalize(arg3);
				addDeath(arg4, arg3);
			}
			else
			{
				cout << endl << arg2 << " is not a valid command." << endl;				
			}
		}
		else if(arg1 == "search")
		{
			temp = arg2;
			spacePos = temp.find(' ');
			prefix = temp.substr(0, spacePos); // from beginning to space
			suffix = temp.substr(spacePos+1); // the rest of the line
			
			search(prefix, suffix);
		}
		else if(arg1 == "print")
		{
			arg2 = capitalize(arg2);
			if(arg2 == "ALL")
			{
				printAll();
			}
			else
			{
				printID(arg2);
			}
		}
		else
		{
			cout << endl  << arg1 << " is not a valid command." << endl;			
		}
	}
	input.close();
}