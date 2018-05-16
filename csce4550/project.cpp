#include "header.h"
using namespace std;


//hashtable.push_back("0");
//hashtable.resize(SIZE);

vector<string> hashtable(100, "0");

int main()
{
	User myUser;
	int logged_in = 0; //whether or not anyone is logged in
	int Sinput = 0; //start input 
	int Uinput = 0; //user input
	int start = 1; //start is true
	int Use = 1; //Use is true
	string username, password, sitename;
	string u, s, h;
	char answer;
	int value;
	cout << endl << "Password Manager by Scarlett Jones" << endl << endl;
	
	//open file to read
	ifstream htxt("hash.txt");
	if((bool) htxt)
	{	
		string line1;
		while(getline(htxt, line1))
		{
			int j=0;
			char * pch1;
			pch1 = strtok((char*) line1.c_str(), " ");
			while(pch1 != NULL)
			{
				if(j==0)
				{
					u = pch1;
					//cout << u << endl;
				}
				else if(j==1)
				{
					s = pch1;
					//cout << s << endl;
				}
				else if(j==2)
				{
					h = pch1;
					//cout << h << endl;
				}
				else
				{
					;
				}
				value = atoi(h.c_str())%SIZE;
				hashtable.at(value) = u;
				pch1 = strtok(NULL, " ");	
				//cout << "word: " << j << endl;
				j++;
			}
			//value = atoi(h.c_str())%SIZE;
			//cout << "hi" << endl;
		}
		//cin.ignore();
		htxt.close();
	}
	
	while(start)
	{
		StartMenu();
		cin >> Sinput;
		switch(Sinput)
		{
			case 1: //create new user
				CreateUser(hashtable);
				//make new file for user
				//add to hash of username/passwords
				//tell them to login to use their account now that it's created
				break;
			case 2: //login
				//check if already logged in
				if(logged_in == 1)
				{
					cout << "You are already logged in as " << username << "." << endl;
					cout << "Not " << username << "? Log out by selecting option 6." << endl;
				}
				else
				{
					cout << "Username: ";
					cin >> username;
					cout << "Password: ";
					cin >> password;
					ifstream input;
					input.open("hash.txt");
					string line;
					while(getline(input, line) && logged_in != 1)
					{
						int i=0;
						char * pch;
						pch = strtok((char *) line.c_str(), " ");
						while(pch != NULL)
						{
							if(i==0)
							{
								if(pch == username)
								{
									u = pch;
									pch = strtok(NULL, " ");
									s = pch;
									pch = strtok(NULL, " ");
									h = pch;
								}
							}
							pch = strtok(NULL, " ");
							i++;
						}
						//value = atoi(h.c_str())%SIZE;
						//string compvalstring = password + s;
						value = checkHash(username, password, s, SIZE, hashtable);
						if(value == 1)
						{
							cout << "Logged in" << endl;
							logged_in = 1;
							Use=1;
						}
						//else
						//{
						//	cout << "Wrong username or password." << endl;
						//}
					}
					//cin.ignore();
					//checkHash(username, password, salt, SIZE, hashtable);
					//check if password maps to username
					//Wrong username or password, try again
					//Log in if correct
					//logged_in = 1;
					//load user info from file named from username, decrypt with password
					//cout << "Before menu options" << endl;
					if(logged_in == 1)
					{
						myUser.login(username, password);
						remove("temp");
						//cout << "made it out of the login function" << endl;
						while(Use)
						{
							UserMenu();
							//cout << "Choose a menu option: ";
							cin >> Uinput;
							switch(Uinput)
							{
								case 1: //add new account
									myUser.addAccount();
									break;
								case 2: //show account info
									myUser.printAccounts();
									break;
								case 3: //delete specific account
									cout << "Which account?" << endl;
									myUser.printSitenames();
									cin >> sitename;
									cout << "Deleting " << sitename << endl;
									myUser.deleteOneAccount(sitename);
									break;
								case 4: //exit
									cout << "Logging you out . . ." << endl;
									//save user data in temp file
									//encrypt into their username file with their password, write over old username file
									//delete temp file
									myUser.logout(username, password);
									remove("temp");
									logged_in = 0;
									Use = 0; //Use is false, exit loop
									break;
								default: //incorrect input
									cout << "Incorrect input. Only enter numbers 1 through 4." << endl;
									break;
							}
						}
					}
					else
					{
						cout << "Wrong username or password" << endl;
					}
				}
				break;
			case 3: //exit
				cout << "Goodbye!" << endl;
				start = 0;
				//exit(1);
				break;
			default:  //incorrect input
				cout << "Incorrect input. Only enter numbers 1 through 3." << endl;
				break;
		}
	}
	
	return 0;
}