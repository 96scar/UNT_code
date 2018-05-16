#include <iostream>
#include <stdio.h>
//#include <functional>
#include <ctime>
#include <vector>
//#include <list>
#define SIZE 100

using namespace std;

int hash(string u, string p, string s, int size);
void CheckHash(string u, string p, string s);

int main()
{
	time_t t = time(0);
	struct tm * now = localtime(&t);
	string username, password;
	char salt [14];
	int value;
	vector<string> hashtable;
	hashtable.resize(SIZE);
	
	cout << "username? ";
	cin >> username;
	cout << "password? ";
	cin >> password;
	sprintf(salt, "%d%d%d%d%d%d", (now->tm_year + 1900), (now->tm_mon + 1), (now->tm_mday), (now->tm_hour), (now->tm_min), (now->tm_sec));
	cout << "salt: " << salt << endl;

	value = hash(username, password, salt, hashtable.size());
	cout << value << endl;
	cout << hashtable.size() << endl;

	hashtable.at(value) = username;
	
	cout << "username? ";
	cin >> username;
	cout << "password? ";
	cin >> password;
	cout << salt << endl;
	
	value = hash(username, password, salt, hashtable.size());
	cout << value << endl;
	cout << hashtable.size() << endl;
	
	if(hashtable.at(value) == username)
	{
		cout << "Correct username & password!" << endl;
	}
	else
	{
		cout << "Incorrect username or password." << endl;
	}
	
	return 0;
}

int hash(string u, string p, string s, int size)
{
	int value=0;
	string send;
	send = p + s;
	
	for(int i=0; i<send.length(); i++)
	{
		value += (int) send.at(i);
	}
	cout << value << endl;
	
	value = value % size;
	
	return value;
}

void CheckHash(string u, string p, string s)
{
	
	
	return;
}