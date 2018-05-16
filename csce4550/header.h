/*
Author: Scarlett Jones
Class: CSCE 4550
File: Project header file
Description: This contains classes and function prototypes. Load user information here when they log in.
					Pull user information from here when they log out to store in encrypted file.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <vector>
#define SIZE 100

using namespace std;

//functions for the main program
void StartMenu(); //print out the start menu, before anyone has logged in
void UserMenu(); //print out the user menu, after a user has logged in
void CreateUser(vector<string> &hashtable); //create a new user file, add username and password to hash of stored users
void encrypt(string username, string password); //encrypt the temp file, store to username file
void decrypt(string username, string password); //decrypt the username file, store to temp file
void hash(string u, string p, string s, int size, vector<string> &table); //hash the username into hashtable based on password+salt
int checkHash(string u, string p, string s, int size, vector<string> &table); //check the hash. return 1 if correct, -1 if incorrect



class Account //account that the user wants to store password for
{
	private:
		string sitename; //the website name
		string siteUsername; //the user's username on the website
		string sitePassword; //the user's password on the website
		
	public:
		void setSitename(string mySitename); //set the site name for the account
		void setSiteUsername(string mySiteUsername); //set the user's username for the website
		void setSitePassword(); //create password for the website, created by password manager	
		void setSitePassword2(string password); //enter password for website
		//void addCurrentAccount(); //add a new account	
		//void deleteCurrentAccount(User myUser, string mySitename); //delete this account on password manager			
		string getSitename(); //get the website name
		string getSiteUsername(); //get the website username
		string getSitePassword(); //get the website password
		void printSiteInfo(); //print out the info stored about the site
};

class User //the User logged in to the password manager
{
	private:
		string username; //user's username for password manager
		string password; //user's password for password manager, used to decrypt their file of account information
		vector <Account> myAccounts; //list of the user's accounts
		int num_accounts;
		
	public:
		void setUsername(string myUsername); //set username for password manager
		void setPassword(string myPassword); //set password for password manager
		//void decrementNum(); //decrement num_accounts by 1
		void addAccount(); //add a new account
		int searchAccount(string mySitename); //search for sitename, return position in list or -1 if not in list
		void deleteOneAccount(string mySitename); //delete a specific account if it exists
		void deleteAccount(); //delete all of the user's stored password information		
		string getUsername(); //return the username for password manager
		string getPassword(); //return the password for password manager
		void printSitenames(); //print all sitenames for user
		void printAccounts(); //print all of the user's stored password information	
		void login(string username, string password); //log the user in, load file
		void logout(string username, string password); //log the user out, store to file
		
};



/*class AccountsList
{
	private:
		list<Account> myAccounts;
	
	public:
		void deleteAllAccounts();
		void printAccounts();
};*/

