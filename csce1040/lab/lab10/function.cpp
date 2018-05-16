/*
Name: Scarlett Jones (ScarlettJones@my.unt.edu)
Teacher: Keathly
Date: 4/7/15
Description: functions
*/

#include <iostream>
#include "header.h"

using namespace std;

// constructor that initializes all accounts to 0
Bank::Bank()
{
	for(int i=0; i < 10 ; i++)
	{
		account[i] = 0;
	}
}

/*
Name: deposit
Parameters: an int representing the account number, an int representing dollar amount
Returns: nothing
Description: goes to account number, adds the dollar amount to the current balance
*/
void Bank::deposit(int num, int value)
{
	account[num] += value;

	return;
}

/*
Name: withdraw
Parameters: an int representing the account number, an int representing dollar amount
Returns: nothing
Description: goes to account number, subtracts the dollar amount from the current balance, unless the amount exceeds the available balance
*/
void Bank::withdraw(int num, int value)
{
	if(value <= account[num])
	{
		account[num] -= value;
	}
	else
	{
		cout << "Insufficient funds" << endl;
	}

	return;
}

/*
Name: balance
Parameters: an int representing the account number
Returns: nothing
Description: goes to account number, prints out the balance
*/
void Bank::balance(int num)
{
	cout << account[num] << endl;

	return;
}

/*
Name: transfer
Parameters: an int representing the from account number, an int representing the to account number, an int representing the dollar amount
Returns: nothing
Description: goes to the from account, checks available balance. If requested dollar amount does not exceed available balance, then transfer that amount to the to account number and subtract the amount from the from account.
*/
void Bank::transfer(int num1, int num2, int value)
{
	if(value <= account[num1])
	{
		account[num1] -= value;
		account[num2] += value;
	}
	else
	{
		cout << "Insufficient funds" << endl;
	}

	return;
}

