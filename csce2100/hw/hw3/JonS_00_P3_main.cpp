/*
Name: Scarlett Jones
ID: 11026836
euid: srj0101
email: ScarlettJones@my.unt.edu
Teacher: Patrick Burke
Program 2
Due Date: November 4, 2015
Sources: I used my textbook from CSCE 1040 called Problem Solving with C++ by Walter Savitch for reference on
		the standard template library, file input/output, and other basic rules for C++ that I may have forgotten
		since last year. I also used www.cplusplus.com for information on the <cctype> header and how to use the
		function ispunct, as well as for more resources on the standard template library and file input/output.
		I talked about ideas for this program with my group members as well. Specifically, I talked with Gxara,
		Thanh, and Ethan.
		
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <list>
#include <iomanip>
#include "JonS_00_P3_header.h"
using namespace std;

int main()
{	
	int loop=1;
	string command, command2, homeid, num, temp, prefix, suffix;

	people myPpl;
	//myPpl.count = 1;
	commands();
	
	while(loop != 0) // keeps program running until quit
	{
		cout << endl << "cmd> ";
		
		cin >> command;
		command = lowercase(command);
		
		if(command == "add")
		{
			cin >> command2;
			command2 = lowercase(command2);
			if(command2 == "name")
			{
				cin.ignore();
				getline(cin, temp);
				int spacePos = temp.find(' ');   
				prefix = temp.substr(0,spacePos); // from beginning to comma
				suffix = temp.substr(spacePos+1); // the rest of the line
			
				prefix = convert(prefix);
				suffix = convert(suffix);

				myPpl.addName(prefix, suffix);
			
			}
			else if(command2 == "spouse")
			{
				cin >> homeid;
				homeid = capitalize(homeid);
				cin.ignore();
				getline(cin, temp);
				int spacePos = temp.find(' ');
				prefix = temp.substr(0, spacePos); // from beginning to comma
				suffix = temp.substr(spacePos+1); // the rest of the line

				prefix = convert(prefix);
				suffix = convert(suffix);
				
				myPpl.addSpouse(prefix, suffix, homeid);
			}
			else if(command2 == "child")
			{
				cin >> homeid;
				homeid = capitalize(homeid);
				cin.ignore();
				getline(cin, temp);

				int spacePos = temp.find(' ');
				prefix = temp.substr(0, spacePos); // from beginning to comma
				suffix = temp.substr(spacePos+1); // the rest of the line
				
				prefix = convert(prefix);
				suffix = convert(suffix);
				
				myPpl.addChild(prefix, suffix, homeid);
			}
			else if(command2 == "address1")
			{
				cin >> homeid;
				homeid = capitalize(homeid);
				cin.ignore();
				getline(cin, temp);
				myPpl.addAddress(temp, homeid);
			}
			else if(command2 == "city")
			{
				cin >> homeid;
				homeid = capitalize(homeid);
				cin.ignore();
				getline(cin, temp);
				myPpl.addCity(temp, homeid);
			}
			else if(command2 == "state")
			{
				cin >> homeid;
				homeid = capitalize(homeid);
				cin.ignore();
				getline(cin, temp);
				myPpl.addState(temp, homeid);
			}
			else if(command2 == "zip")
			{
				cin >> homeid;
				homeid = capitalize(homeid);
				cin >> num;
				myPpl.addZip(num, homeid);
			}
			else if (command2 == "date_birth")
			{
				cin >> homeid;
				homeid = capitalize(homeid);
				cin >> num;
				myPpl.addBirth(num, homeid);
			}
			else if (command2 == "date_wedding")
			{
				cin >> homeid;
				homeid = capitalize(homeid);
				cin >> num;
				myPpl.addWed(num, homeid);
			}
			else if (command2 == "date_death")
			{
				cin >> homeid;
				homeid = capitalize(homeid);
				cin >> num;
				myPpl.addDeath(num, homeid);
			}
			else
			{
				cout << endl << command2 << " is not a valid command" << endl;
			}
		}
		else if(command == "search")
		{
			cin.ignore();
			getline(cin, temp);
			int spacePos = temp.find(' ');
			string prefix = temp.substr(0, spacePos); // from beginning to comma
			string suffix = temp.substr(spacePos+1); // the rest of the line
			
			myPpl.search(prefix, suffix);
		}
		else if(command == "print")
		{
			cin >> command2;
			command2 = capitalize(command2);
			if(command2 == "ALL")
			{
				myPpl.printAll();
			}
			else
			{
				myPpl.printID(command2);
			}
			
		}
		else if(command == "file")
		{
			cin >> command2;
			myPpl.file(command2);
		}
		else if(command == "quit")
		{
			cout << endl << "Have a good day and a pleasant tomorrow! Good-bye." << endl;
			loop = 0;
		}
		else if(command == "commands")
		{
			system("clear");
			commands();
		}
		else
		{
			cout << endl  << command << " is not a valid command." << endl;
		}
	}
	

	return 0;
}