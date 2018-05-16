#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main()
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
	
	char special = ' ';
	for(int i=0; i<95; i++)
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
	
	cout << "Password: " << password << endl;
	return 0;
}