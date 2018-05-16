/*
Name: Scarlett Jones
ID: 11026836
euid: srj0101
email: ScarlettJones@my.unt.edu
Teacher: Patrick Burke
Program 2
Due Date: October 12, 2015
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
#include <string>
#include <cctype>
#include <list>
#include <iomanip>
#include "JonS_00_P2_header.h"
using namespace std;

int main()
{	
	int loop=1;
	int length1, length2;
	string command[2];

	people myPpl;
	
	cout << endl << "Scarlett's Address Book" << endl;
	cout << "Available Commands" << endl;
	cout << " add <name> \n search <name> \n remove <name> \n print \n file <filename> NOTE: filename includes pathname if necessary \n quit \n" << endl;
	cout << "NOTE: Commands must be in all lowercase or all uppercase." << endl << endl;
	
	while(loop != 0)
	{
		cout << endl << "cmd> ";
		
		for(int x = 0; x < 2; x++) // getting the input
		{
			cin >> command[x];
			if(command[0] == "print" || command[0] == "PRINT") //only needs 1 input
			{
				command[1] = '\n';
				break;
			}
			else if(command[0] == "quit" || command[0] == "QUIT") // only needs 1 input
			{
				command[1] = '\n';
				break;
			}
			else
			{
				; // need 2 input
			}
		}

	/*	This is how I tested the commands.

		length1 = command[0].length();
		cout << endl << "length1: "<< length1;
		length2 = command[1].length();
		cout << endl << "length2: " << length2;
		
		cout << endl << "Command: " ;
		for(int i = 0; i < length1; i++)
		{
			cout << command[0].at(i);
		}
		
		cout << endl << "2nd Word: ";
		for(int j = 0; j < length2; j++)
		{
			cout << command[1].at(j);
		}	
	*/
	
		if(command[0] == "add" || command[0] == "ADD")
		{
			for(int j = 0; j < command[1].length(); j++) // convert name to correct format
			{
				if(j == 0)
				{
					command[1].at(j) = toupper(command[1].at(j)); //first letter to uppercase
				}
				else
				{
					command[1].at(j) = tolower(command[1].at(j)); // the rest of the letters to lowercase
				}		
			}

			myPpl.add(command[1]);
		}
		else if(command[0] == "search" || command[0] == "SEARCH")
		{
			for(int j = 0; j < command[1].length(); j++) // convert name to correct format
			{
				if(j == 0)
				{
					command[1].at(j) = toupper(command[1].at(j)); //first letter to uppercase
				}
				else
				{
					command[1].at(j) = tolower(command[1].at(j)); // the rest of the letters to lowercase
				}		
			}
			
			myPpl.search(command[1]);
		}
		else if(command[0] == "remove" || command[0] == "REMOVE")
		{
			for(int j = 0; j < command[1].length(); j++) // convert name to correct format
			{
				if(j == 0)
				{
					command[1].at(j) = toupper(command[1].at(j)); //first letter to uppercase
				}
				else
				{
					command[1].at(j) = tolower(command[1].at(j)); // the rest of the letters to lowercase
				}		
			}
			
			myPpl.remove(command[1]);
		}
		else if(command[0] == "print" || command[0] == "PRINT")
		{
			myPpl.print();
		}
		else if(command[0] == "file" || command[0] == "FILE")
		{
			myPpl.file(command[1]);
		}
		else if(command[0] == "quit" || command[0] == "QUIT")
		{
			cout << endl << "Quitting. Goodbye!" << endl;
			loop = 0;
		}
		else if(command[0] == "error") // wanted to use this to print that there was an error from not enough input
		{
			cout << "Error: Not enough command line input." << endl;
		}
		else
		{
			cout << endl  << command[0] << " is not a valid command." << endl;
		}
	}
	

	return 0;
}