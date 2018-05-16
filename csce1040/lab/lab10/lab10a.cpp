/*
Name: Scarlett Jones (ScarlettJones@my.unt.edu)
Teacher: Keathly
Date: 4/7/15
Description: input output file
*/

#include <iostream>

using namespace std;

int main()
{
	string word;

	while(word != "quit")
	{

		cout << "bank> ";
	
		cin >> word;
	
		if(word == "deposit")
		{
			cout << "DEPOSIT SELECTED" << endl;
		}
		else if(word == "withdraw")
		{
			cout << "WITHDRAW SELECTED" << endl;
		}
		else if(word == "balance")
		{
			cout << "BALANCE SELECTED" << endl;
		}
		else if(word == "quit")
		{
		}
		else
		{
			cout << "Incorrect input." << endl;
		}

		
	}

	return 0;
}
