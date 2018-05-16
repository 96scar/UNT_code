/*
Author: Scarlett Jones
Class: CSCE 4550
File: Project function file 
Description: This contains function definitions.
*/

#include "header.h"
#include <fstream>
using namespace std;

/*
Function: StartMenu
Parameters: Nothing
Returns:  Nothing
Description: Prints out the start menu options.
*/
void StartMenu()
{
	cout << "Please select a menu option." << endl; 
	cout << "1. Create a new user" << endl << "2. Login" << endl << "3. Exit" << endl;
	cout << "Selection: ";
	return;
}

/*
Function: UserMenu
Parameters: Nothing
Returns: Nothing
Description: Prints out the user menu options.
*/
void UserMenu()
{
	cout << "Please select a menu option." << endl;
	cout << "1. Add new account" << endl << "2. Show account info" << endl << "3. Delete a specific account" << endl << "4. Exit" << endl;
	cout << "Selection: ";
	return;
}

/*
Function: CreateUser
Parameters: hashtable
Returns: Nothing
Description: Creates a new user.
*/
void CreateUser(vector<string> &hashtable)
{
	string tempU, username, tempP, password;
	int user = 1;
	int pass = 1;
	string path;
	char salt[14];
	time_t t=time(0);
	struct tm * now = localtime(&t);
	sprintf(salt, "%d%d%d%d%d%d", (now->tm_year + 1900), (now->tm_mon + 1), (now->tm_mday), (now->tm_hour), (now->tm_min), (now->tm_sec));
	//cout << "salt: " << salt << endl;
	
	while(user)
	{
		cout << "Username: ";
		cin >> tempU;
		//check if username already exits
		ifstream file(tempU.c_str());
		if((bool) file)
		{
			cout << "Username already exists." << endl;
			file.close();
		}
		else
		{
			username = tempU;
			user = 0;
			cout << "Your username is " << username << endl;
			ofstream file(tempU.c_str());
			file.close();
			//path = "touch "+username;
			//system(path.c_str());
		}
	}
	while(pass)
	{
		cout << "Password: ";
		cin >> tempP;
		//check if password was entered
		if(tempP.length() < 8)
		{
			cout << "Password must be at least 8 characters long." << endl;
		}
		else
		{
			password = tempP;
			pass = 0;
			cout << "Your password has been set" << endl;
		}
	}
	
	string sendsalt = "";
	
	for(int i=0; i<14; i++)
	{
		sendsalt += salt[i];
	}
	
	hash(username, password, sendsalt, SIZE, hashtable);

	return;
}

void encrypt(string username, string password)
{
	int key=0, i=0;
	char c;
	//open temp file to read from
	ifstream input;
	input.open("temp");
	
	//open username file to write to
	ofstream output;
	output.open(username.c_str());
	
	while(input.get(c))
	{
		if(i < password.length())
		{
			key = (int) password.at(i);
		}
		else
		{
			i=0;
			key = (int) password.at(i);
		}
		output << (char) (c + key);
		//cout << (char) (c + key);
		i++;
	}
	
	input.close();
	output.close();
	return;
}

void decrypt(string username, string password)
{
	//cout << "in the decrypt function" << endl;
	int key=0, i=0;
	char c;
	//open username file to read from
	ifstream input;
	input.open(username.c_str());
	
	//open temp file to write to
	ofstream output;
	output.open("temp");
	
	while(input.get(c))
	{
		if(i < password.length())
		{
			key = (int) password.at(i);
		}
		else
		{
			i=0;
			key = (int) password.at(i);
		}		
		output << (char) (c - key);
		//cout << (char) (c - key);
		i++;
	}
	
	input.close();
	output.close();
	return;
}


void hash(string u, string p, string s, int size, vector<string> &table)
{
	int value=0;
	string send = p + s;
	
	for(int i=0; i<send.length(); i++)
	{
		value += (int) send.at(i);
	}
	value = value % SIZE;
	
	table.at(value) = u;
	
	fstream fs;
	fs.open("hash.txt", fstream::in | fstream::out | fstream::app);
	fs << u << "  " << s << "  " << value << endl;
	fs.close();	
	
	return;
}

int checkHash(string u, string p, string s, int size, vector<string> &table)
{
	int value=0; 
	string send = p+s;
	for(int i=0; i<send.length(); i++)
	{
		value += (int) send.at(i);
	}
	value = value % SIZE;
	
	if(table.at(value) == u)
	{
		return 1;
	}
	
	return -1; //incorrect username or password
}


//Account class functions
void Account::setSitename(string mySitename)
{
	sitename = mySitename;
	return;
}

void Account::setSiteUsername(string mySiteUsername)
{
	siteUsername = mySiteUsername;
	return;
}

void Account::setSitePassword()
{
	vector<char> Lbank, Ubank, Nbank, Sbank, passbank;
	int min, max, minLC, maxLC, minUP, maxUP, minNum, maxNum, minSpecial, maxSpecial;
	string l, u, n, s;
	string password;
	min = 8;
	max = 20;
	srand(time(NULL));
	int numtype=0;
	
	char lowercase = 'a';
	for(int i=0; i<26; i++)
	{
		Lbank.push_back(lowercase);
		lowercase += 1;
	}	
	
	char upper = 'A';
	for(int i=0; i<26; i++)
	{
		Ubank.push_back(upper);
		upper += 1;
	}	
	
	char num = '0';
	for(int i=0; i<10; i++)
	{
		Nbank.push_back(num);
		num += 1;
	}	
	
	char special = '!';
	for(int i=0; i<94; i++)
	{
		if(  ( (int) special >= 48 && (int) special <=57 ) || ( (int) special >=65 && (int) special <=90 ) || ( (int) special >=97 && (int) special <=122 )  )
		{
			; //don't add these
		}
		else
		{
			Sbank.push_back(special);
		}
		special += 1;
	}	

	cout << "Min password length? ";
	cin >>  min;
	
	cout << "Lowercase letters allowed? (y/n): ";
	cin >> l;
	if(l == "y")
	{
		cout << "Min lowercase characters? ";
		cin >> minLC;
		numtype++;	
	}
	else
	{
		minLC=0;
		maxLC=0;
	}
	
	cout << "Uppercase letters allowed? (y/n): ";
	cin >> u;
	if(u == "y")
	{
		cout << "Min uppercase characters? ";
		cin >> minUP;
		numtype++;
	}
	else
	{
		minUP=0;
		maxUP=0;
	}
	
	cout << "Numbers allowed? (y/n): ";
	cin >> n;
	if(n == "y")
	{	
		cout << "Min numbers? ";
		cin >> minNum;
		numtype++;
	}
	else
	{
		minNum=0;
		maxNum=0;
	}
	
	cout << "Special characters allowed? (y/n): ";
	cin >> s;
	if(s == "y")
	{	
		cout << "Min special characters? ";
		cin >> minSpecial;
		numtype++;
	}
	else
	{
		minSpecial=0;
		maxSpecial=0;
	}
	
	if(l == "y")
	{
		if(minLC < min - minUP - minNum - minSpecial)
			minLC = min - minUP - minNum - minSpecial;	
	}
	
	if(u == "y")
	{
		if(minUP < min - minLC - minNum - minSpecial)
			minUP = min - minLC - minNum - minSpecial;				
	}
	
	if(n == "y")
	{
		if(minNum < min - minLC - minUP - minSpecial)
			minNum = min - minLC - minUP - minSpecial;			
	}
	
	if(s == "y")
	{
		if(minSpecial < min - minLC - minUP - minNum)
			minSpecial = min - minLC - minUP - minNum;			
	}
	
	max = minLC+minUP+minNum+minSpecial+4;
	maxLC = max - minUP - minNum - minSpecial;
	maxUP = max - minLC - minNum - minSpecial;
	maxNum = max - minLC - minUP - minSpecial;
	maxSpecial = max - minLC - minUP - minNum;
	
	while(maxLC+maxUP+maxNum+maxSpecial > max)
	{
		int choose = rand()%4;

		switch(choose)
		{
			case 0: 
				if(maxLC-1 != minLC)
				{
					maxLC--;
				}
				break;
			case 1: 
				if(maxUP-1 != minUP)
				{
					maxUP--;
				}
				break;
			case 2: 
				if(maxNum-1 != minNum)
				{
					maxNum--;
				}
				break;
			case 3: 
				if(maxSpecial-1 != minSpecial)
				{
					maxSpecial--;
				}
				break;
			default: cout << "Error in changing max values" << endl;
				break;
		}
	}
	
	int Llength;
	if(maxLC!=0 || minLC!=0)
	{
		Llength = rand() % (maxLC-minLC)+minLC;

		for(int i=0; i<Llength; i++)
		{
			int pos = rand() % Lbank.size();
			passbank.push_back(Lbank.at(pos));
		}
	}
	else
	{
		Llength = 0;
	}
	min -= Llength;
	max -= Llength;
	
	int Ulength;
	if(maxUP!=0 || minUP!=0)
	{
		Ulength = rand() % (maxUP-minUP)+minUP;

		for(int i=0; i<Ulength; i++)
		{
			int pos = rand() % Ubank.size();
			passbank.push_back(Ubank.at(pos));
		}
	}
	else
	{
		Ulength = 0;
	}	
	min -= Ulength;
	max -= Ulength;
	
	int Nlength;
	if(maxNum!=0 || minNum!=0)
	{
		Nlength = rand() % (maxNum-minNum)+minNum;

		for(int i=0; i<Nlength; i++)
		{
			int pos = rand() % Nbank.size();
			passbank.push_back(Nbank.at(pos));
		}	
	}
	else
	{
		Nlength = 0;
	}
	min -= Nlength;
	max -= Nlength;
	
	int Slength;
	if(maxSpecial!=0 || minSpecial !=0)
	{
		Slength = rand() % (maxSpecial-minSpecial)+minSpecial;

		for(int i=0; i<Slength; i++)
		{
			int pos = rand() % Sbank.size();
			passbank.push_back(Sbank.at(pos));
		}	
	}
	else
	{
		Slength = 0;
	}
	min -= Slength;
	max -= Slength;
	
	if(min > 0)
	{
		while(min > 0)
		{
			int pos = rand() % Lbank.size();
			passbank.push_back(Lbank.at(pos));
			Llength++;
			min--;
		}
	}
	
	int plength = passbank.size();

	while(!passbank.empty())
	{
		int pos = rand() % passbank.size();
		password += passbank.at(pos);
		passbank.erase(passbank.begin() + pos);
	}
	
	sitePassword = password;
	return;
}

void Account::setSitePassword2(string password)
{
	sitePassword = password;
}

/*Account::void addCurrentAccount()
{
	string temp;
	cout << endl << "What website is your account on? ";
	cin << temp;
	setSitename(temp);
	cout << endl << "What is your username? ";
	cin << temp;
	setSiteUsername(temp);
	cout << endl << "Setting a password";
	setSitePassword();
	cout << endl << "Make sure you change your account password for " << getSitename() << " to " << getSitePassword() << endl;
	return;
}*/

/*Account::void deleteCurrentAccount(User myUser, string mySitename)
{
	int position;
	//search list for sitename, get position
	//remove position from list
	myUser.decrementNum();
	string empty = "";
	cout << endl << "Deleting " << getSitename() << " account for " << getSiteUsername() << "." << endl;
	setSitename(empty);
	setSiteUsername(empty);
	setSitePassword(empty);
	//search list
	//remove from list
	return;
}*/

string Account::getSitename()
{
	return sitename;
}

string Account::getSiteUsername()
{
	return siteUsername;
}

string Account::getSitePassword()
{
	return sitePassword;
}

void Account::printSiteInfo()
{
	cout << endl;
	cout << "Site name: " << getSitename() << endl;
	cout << "Username: " << getSiteUsername() << endl;
	cout << "Password: " << getSitePassword() << endl;
	cout << endl;
	return;
}

//User class functions

void User::setUsername(string myUsername)
{
	username = myUsername;
	return;
}

void User::setPassword(string myPassword)
{
	password = myPassword;
	return;
}

/*User::void decrementNum()
{
	num_accounts--;
	return;
}*/

void User::addAccount()
{
	Account temp1;
	string temp2;
	cout << endl << "Enter site name: ";
	cin >> temp2;
	temp1.setSitename(temp2);
	cout << endl << "Enter username: ";
	cin >> temp2;
	temp1.setSiteUsername(temp2);
	temp1.setSitePassword();
	//add to list
	myAccounts.push_back(temp1);
	num_accounts++;
	return;
}

int User::searchAccount(string mySitename)
{
	for(int i=0; i<num_accounts; i++)
	{
		if(myAccounts.at(i).getSitename() == mySitename)
		{
			return i;
		}
	}
	return -1; //doesn't exist
}

void User::deleteOneAccount(string mySitename)
{
	int position = searchAccount(mySitename);
	if(position != -1)
	{
		myAccounts.erase(myAccounts.begin()+position);
		num_accounts--;
		cout << "Deleted account under " << mySitename << endl;
	}
	else
	{
		cout << "Didn't find an account under " << mySitename << endl;
	}
	return;
}

void User::deleteAccount()
{
	string empty = "";
	//delete everything in list
	while(!myAccounts.empty())
	{
		myAccounts.pop_back();
		num_accounts--;
	}
	//delete username and password
	username = empty;
	password = empty;
	return;
}

string User::getUsername()
{
	return username;
}

string User::getPassword()
{
	return password;
}

void User::printSitenames()
{
	for(int i=0; i<num_accounts; i++)
	{
		cout << myAccounts.at(i).getSitename() << endl;
	}
}

void User::printAccounts()
{
	//print everything in list
	//Account temp;
	for(int i=0; i<num_accounts; i++)
	{
		//temp = myAccounts.at(i);
		myAccounts.at(i).printSiteInfo();
	}
	return;
}

void User::login(string username, string password)
{
	//cout << "in login function " << endl;
	decrypt(username, password);
	//cout << "made it out of decrypt function  " << endl;
	
	//open file to read from
	ifstream input;
	input.open("temp");
	string line;
	Account temp1;
	while(getline(input, line))
	{
		int i=0;
		char *pch;
		pch = strtok((char*) line.c_str(), " ");
		while(pch != NULL)
		{
			if(i==0)
			{
				temp1.setSitename(pch);
			}
			else if(i==1)
			{
				temp1.setSiteUsername(pch);
			}
			else if(i==2)
			{
				temp1.setSitePassword2(pch);
			}
			else
			{
				;
			}
			pch = strtok(NULL, " ");
			i++;
		}
		myAccounts.push_back(temp1);
		num_accounts++;
	}
	input.close();
	
	return;
}

void User::logout(string username, string password)
{
	//open file to write to
	ofstream output;
	output.open("temp");
	for(int i=0; i<num_accounts; i++)
	{
		output << myAccounts.at(i).getSitename() << " " << myAccounts.at(i).getSiteUsername() << " " << myAccounts.at(i).getSitePassword() << "\n";
	}
	output.close();

	encrypt(username, password);

	while(!myAccounts.empty())
	{
		myAccounts.pop_back();
		num_accounts--;
	}
	username="";
	password="";
	
	return;
}


/*
Function: 
Parameters: 
Returns: 
Description: 
*/