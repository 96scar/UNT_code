/*
  Set.cpp

  No rights reserved                           

  Author: Scarlett Jones
  EUID: srj0101
  Email: ScarlettJones@my.unt.edu
  ID: 11026836
  Date: 2/12/16
  Description: Made a set.cpp file to go with the main.cpp and set.h files.
  This took a while to figure out what I was actually supposed to do.
  This is supposed to reflect what we are learning in class about sets, unions, intersections,
  set difference, and more. It was an okay program once I understood the instructions.
*/

#include <iostream>
#include "Set.h"

using namespace std;

Set::Set() // constructor initializes
{
	int i;
	for(i = 0; i < 4; i++)
	{
		bitString[i] = 0;
	}		
}

Set::Set(const Set& s) // copy constructor
{		
}

Set::~Set() // deconstructor
{
}

void Set::add(int i) // add a 1 to a bit position, or a number to the set
{
	unsigned int mask;
	int bit, word;

	word = i / 32;    // find out which word of the bitstring array 
					   // contains "bit" i
	bit = i % 32;     // and which bit IN word, is the ith bit

	mask = 1 << bit;

	bitString[word] |= mask;
}

void Set::remove(int i) // remove a 1 from bit position, or remove number from set
{
	unsigned int mask;
	int bit, word;

	word = i / 32;    // find out which word of the bitstring array 
					   // contains "bit" i
	bit = i % 32;     // and which bit IN word, is the ith bit

	mask = 1 << bit;
	
	bitString[word] &= ~mask;
} 

int Set::size() // tells how many 1's are in the bitstring or numbers in the set
{
	unsigned int result;
	int i, j, count;
	count = 0;
	
	for(i=0; i<4; i++)
	{		
		for(j=0; j<32; j++)
		{	
			result = bitString[i] >> j;
			result = result & 1;
			
			if(result == 1) // increase count when there is a 1 found
			{
				count++;
			}
			else
			{
				;
			}
		}
	}	
	return count;
} 

int Set::is_member(int i) // tells if a bit position is in the set
{
	int bit, word, result;

	word = i / 32;    // find out which word of the bitstring array 
					   // contains "bit" i
	bit = i % 32;     // and which bit IN word, is the ith bit
	
	result = bitString[word] >> bit;
	result = result & 1;

	if(result == 1)
	{
		return 1; // true
	}
	else
	{
		;
	}		
	return 0; // false
} 

void Set::operator=(const Set& s) // sets 2 strings equal
{
	Set result;
	int i;
	
	for(i=0; i<4; i++)
	{
		result.bitString[i] = bitString[i] = s.bitString[i];
	}
} 

// intersection of 2 strings
Set Set::operator&(const Set& s)
{
	Set result;
	int i;
	
	for(i=0; i<4; i++)
	{
		result.bitString[i] = bitString[i] & s.bitString[i];
	}
	
	return result;
} 


// union of 2 strings
Set Set::operator|(const Set& s)
{
	Set result;
	int i;

	for(i=0; i<4; i++)
	{
		result.bitString[i] = bitString[i] | s.bitString[i];
	}		
	
	return result;
} 
	

// exclusive OR of 2 strings
Set Set::operator^(const Set& s)
{
	Set result;
	int i;
	
	for(i=0; i<4; i++)
	{
		result.bitString[i] = bitString[i] ^ s.bitString[i];
	}
	
	return result;
} 
	

// set difference........this one is more complicated than just subtract operator
Set Set::operator-(const Set& s)
{
	Set result;
	int i;
	
	for(i=0; i<4; i++)
	{
		result.bitString[i] = bitString[i] & ~s.bitString[i];
	}	
	
	return result;
} 

void Set::printSet() // prints out the items in the set, meaning the 1 positions in the bitstring
{
	unsigned int result;
	int i, j;
	
	cout << "{";
	
	for(i=0; i<4; i++)
	{		
		for(j=0; j<32; j++)
		{	
			result = bitString[i] >> j;
			result = result & 1;
			
			if(result == 1)
			{
				cout << " " << i*32+j << " ";
			}
			else
			{
				;
			}
		}
	}

	cout << "}" << endl;
}

