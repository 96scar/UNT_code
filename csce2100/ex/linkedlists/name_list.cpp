#include <iostream>
#include <list>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
	string name;
	list<string> L;
	list<string>::iterator iter;
	
	//adding name
	for(int i=0; i<5; i++)
	{
		cout << "\n\n Enter Name: ";
		getline(cin, name);
		L.push_back(name);
	}
	
	//printing list of names
	
	cout << "\n\nList Contains: " << endl;
	for(iter = L.begin(); iter != L.end(); iter++)
	{
		cout << *iter << endl;
	}
	
	L.sort(); // sorts list
	
	//prints, hopefully alphabetized
	cout << "\n\nList Contains: " << endl;
	for(iter = L.begin(); iter != L.end(); iter++)
	{
		cout << *iter << endl;
	}	
	
/*	
	//remove name? and search??
	for(int j=0; j<5; j++)
	{
		cout << "\n\nRemove which element: ";
		getline(cin, name);
	
	
	
		for(iter = L.begin(); iter != L.end(); iter++)
		{
			if(*iter == name)
			{
				cout << *iter;
				iter = L.erase(iter); //used http://www.cplusplus.com/reference/list/list/erase/
			}
			else
			{
				;
			}
		}
	}
	
		//printing list of names
	cout << "\n\nList Contains: " << endl;
	for(iter = L.begin(); iter != L.end(); iter++)
	{
		cout << *iter << endl;
	}
	
*/	
	cout << endl;
	
	return 0;
}