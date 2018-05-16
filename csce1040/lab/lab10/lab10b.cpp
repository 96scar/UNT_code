/*
Name: Scarlett Jones (ScarlettJones@my.unt.edu)
Teacher: Keathly
Date: 4/7/15
Description: banking system
*/

#include <iostream>
#include "header.h"

using namespace std;

int main()
{
	string word; // string type in C++
	int n, v, from, to; // n is account number, v is dollar amount, from is from account number, to to to account number

	Bank MyBank; // how to access the class Bank members

	while(word != "quit") // if word is quit, then exit loop
	{

		cout << "bank> ";
	
		cin >> word; // get input
	
		if(word == "deposit") // DEPOSIT
		{			
			cin >> n >> v;
			
			if(n >= 0 && n < 10)
			{			
				MyBank.deposit(n, v);
			}
			else
			{
				cout << "Not an account number" << endl;
			}
		}
		else if(word == "withdraw") // WITHDRAW
		{	
			cin >> n >> v;
			
			if(n >= 0 && n < 10)
			{
				MyBank.withdraw(n, v);
			}
			else
			{
				cout << "Not an account number" << endl;
			}
		}
		else if(word == "balance") // BALANCE
		{
			cin >> n;

			if(n >= 0 && n < 10)
			{
				MyBank.balance(n);
			}
			else
			{
				cout << "Not an account number" << endl;
			}
			
		}
		else if(word == "transfer") // TRANSFER
		{	
			cin >> from >> to >> v;

			if(from >= 0 && from < 10 && to >= 0 && to < 10)
			{
				MyBank.transfer(from, to, v);
			}
			else
			{
				cout << "Either the from or to account number is not an account number" << endl;
			}

			
		}
		else if(word == "quit") // QUIT
		{
			;
		}
		else // INCORRECT INPUT
		{
			cout << "Incorrect input." << endl;
		}

		
	}

	return 0;
}

