/*****************************************************************************/
//
//  Set.C --- supplied by Phil Sweany, 1/23/2017
//
//  No rights reserved                           
//
/*****************************************************************************/

#include "Set.h"

	Set::Set() //constructor will create list of 160 nodes
    {
		cout << "constructor" << endl;
		head = NULL;
		tail = NULL;
//		cout << "constructor " << endl;	
//		cout << __LINE__ << endl;
//		int i;		
//		cout << __LINE__ << endl;
//		node *walk = head;		
//		cout << __LINE__ << endl;
	//	walk->bit  = 0; //segmentation fault before here		
		//walk->item = 0;		
		//cout << walk->bit << " ";	
//		walk = head;
 //       for(i = 0; i < 160; i++)
//		{
//			walk->next = new node;
//			cout << walk->bit << " ";
//			walk->bit = 0;
//			//cout << __LINE__ << endl;
		//	walk->item = i;
	//		walk = walk->next;//go to next item in list
//		}
     }


//copy constructor
	Set::Set(const Set& s)
        {
			cout << "copy constructor" << endl;
//			int i;
	///		node *walk = head;
		//	for(i=0; i<160; i++)
			//{
				
			//}
//		int i;
   //             for(i = 0; i < NUM_WORDS; i++)
	//		bitString[i] = s.bitString[i];
        }

	
	Set::~Set() //deconstructor
        {
			cout << "destructor" << endl;
//			int i;
//			node *walk = head;
//			for(i=0; i<160; i++)
//			{
//				delete walk;
				
	//			walk = walk->next;
//			}
//		int i;
  //      for(i = 0; i < NUM_WORDS; i++)
	//		bitString[i] = 0;
        }

	void Set::clear() //clears the set
        {
			int i;
			node *walk;
			walk = head;
			for(i=0; i < 160; i++)
			{
				walk->bit = 0;
				walk->item = i;
				walk = walk->next;
			}
			return;
        }

	void Set::addToSet(int i) //add element to set
        {
			int j;
			node *walk = head;
			
			cout << "add to set function" << endl;
			//if(walk == NULL) {cout << "walk is NULL" << endl;}
			while(walk != NULL)
			{
				if(walk->item == i)
				{
					cout << endl << walk->item << endl;
					walk->bit = 1;
					cout << walk->bit << endl;
					return;
				}
				
				walk = walk->next;
			}

			cout << "end of addtoset function" << endl;
				return;
        }


	void Set::removeFromSet(int i)
        {
			int j;
			node *walk;
			walk = head;
			while(walk != NULL)
			{
				if(walk->item == i)
				{
					walk->bit = 0;
					return;
				}
				walk = walk->next;
			}
			
			return;
        }


	int Set::cardinality()
        {
		int i;
                int ones = 0;
/*                for( i = 0; i < NUM_WORDS * 32; i++)
                {
                 	if( is_member(i) )
                        {
				ones++;
                	}
                }
				*/

		return ones; 
        }


	int Set::is_member(int i)
        {
			int j;
			node *walk;
			walk = head;
			while(walk != NULL)
			{
				if(walk->bit == i)
				{
					return 1;
				}
			}
		return 0;
        }


	void Set::operator=(const Set& s) // set 1st equal to 2nd
        {
			int i;
			node *walk1, *walk2;
			walk1 = head;
			walk2 = s.head;
			for(i=0; i<160; i++)
			{
				walk2->bit = walk1->bit;
				walk2->item = walk1->item;
				walk1 = walk1->next;
				walk2 = walk2->next;
			}
//		int i;
 //               for(i = 0; i < NUM_WORDS; i++)
//			bitString[i] = s.bitString[i];
        }

   
	Set Set::operator&(const Set& s)
        {
		Set result;
//		int i;
  //              for(i = 0; i < NUM_WORDS; i++)
	//		result.bitString[i] = bitString[i] & s.bitString[i];
		return result;
        }

	
	Set Set::operator|(const Set& s)
        {
		Set result;
//		int i;
   //             for(i = 0; i < NUM_WORDS; i++)
	//		result.bitString[i] = bitString[i] | s.bitString[i];
		return result;
        }

	
	Set Set::operator^(const Set& s)
        {
		Set result;
	//	int i;
       //         for(i = 0; i < NUM_WORDS; i++)
		//	result.bitString[i] = bitString[i] ^ s.bitString[i];
		return result;
        }

	
	Set Set::operator-(const Set& s)
        {
                Set result;
	//	int i;

       //         for(i = 0; i < 5; i++)
		//	result.bitString[i] = bitString[i] - s.bitString[i];
	
		return result;	
        }

	void Set::printSet()
        {
			int i;
			node *walk;
			walk = head;
			if(walk == NULL) { cout << "EMPTY" << endl; }
			//cout << walk->bit;
			cout << "in function" << endl;
			//cout << walk->bit;
			cout << endl << "{";
			while(walk != NULL)
			{
				if(walk->bit != 0)
				{
					cout << walk->item << " ,";
				}
				walk = walk->next;
			}
			cout << "}" << endl;
			return;
        }


	void Set::debug()
        {
	/*
		printf("Word 0 = %X\n",bitString[0]);
		printf("Word 1 = %X\n",bitString[1]);
		printf("Word 2 = %X\n",bitString[2]);
		printf("Word 3 = %X\n",bitString[3]);
		printf("Word 4 = %X\n",bitString[4]);
*/
        }
