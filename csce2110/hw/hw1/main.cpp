#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
    // *******************************************
    //   
    //  This file is meant to give you SOME idea   
    //  of how we'll test your code.  We WILL use
    //  this program as ONE of our tests.  But 
    //  there WILL be others.   
    //   
    // ******************************************* 

    /*   Commented out for now since I don't have a 
         Set.C to test.  That's YOUR job students!.
         However, don't be surprised if, when you
         uncomment this, that there are syntax errors.
         I'm sure you'll get them fixed and then email
         them to me.
	*/
	
    Set s1, s2, s3, s4;
    
	int b, i;
	
    s1.add(0);
    s1.add(1);
    s1.add(2);
    s1.add(48);
	
	cout << "s1 = ";
	s1.printSet();	
	
	s1.remove(0);
	
	cout << "s1 = ";
	s1.printSet();
	
    s2.add(27);
    s2.add(0);
    s2.add(109);
    s2.add(2);
	
	cout << "s2 = ";
	s2.printSet();	
	
	s2.remove(109);
	
	cout << "s2 = ";
	s2.printSet();	

    s3 = s1 & s2;
    cout << "\nThe intersection of s1 and s2 is \n";
    s3.printSet();
		
    s4 = s1 | s2;
    cout << endl << "\nThe union of s1 and s2 is \n";
    s4.printSet();
	
	s3 = s1 ^ s2;
	cout << endl << "Exclusive Or: ";
	s3.printSet();
	
	s3 = s1 - s2;
	cout << endl << "set difference: ";
	s3.printSet();
	
	s4 = s1;
	cout << endl << "s4: ";
	s4.printSet();
	
	
	cout << endl << "s1: ";
	s1.printSet();
	b = s1.is_member(2);
	
	if(b)
	{
		cout << endl << "Yes, it's a member" << endl;
	}
	else
	{
		cout << endl << "No, it's not a member" << endl;
	}
	
	i = s4.size();
	
	cout << endl << "Size: " << i << endl;
	
    return 0; 
}
