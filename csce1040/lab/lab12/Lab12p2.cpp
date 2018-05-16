/*
Scarlett Jones
Keathly 
4/21/15
shows class hierarchy and declaration of the base class
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Employee 
{
	char name[20];
public:
	char *getName() { return name; }
	//constructors
	Employee(char temp[20])
	{
		//using strcpy() function, assign value to name variable

		strcpy(name, temp);		
	}
	

	//virual function
	virtual void show_info()
	{
		cout << getName();
	}
};

class Manager : public Employee
{
public:
	//constructor
	Manager(char name[20]) : Employee(name)
	{
//		strcpy(name, getName());
	}

	void show_info()
	{
		cout << getName();
	}
};

class Worker : public Employee
{
public:
	//constructor
	Worker(char name[20]) : Employee(name)
	{
//		strcpy(name, getName());
	}

	void show_info()
	{
		cout << getName();
	}
};

class Officer : public Employee
{
public:
	//constuctor
	Officer(char name[20]) : Employee(name)
	{
//		strcpy(name, getName());
	}

	void show_info()
	{
		cout << getName();
	}
};

class Technician : public Employee
{
public:
	//constructor
	Technician(char name[20]) : Employee(name)
	{
//		strcpy(name, getName());
	}

	void show_info()
	{
		cout << getName();
	}
};

int main()
{
	Employee Rafa((char*)"Rafa\n");
	Manager Mario((char*)"Mario\n");
	Worker Anton((char*)"Anton\n");
	Officer Luis((char*)"Luis\n");
	Technician Pablo((char*)"Pablo\n");

	//The type of object pointed by a pointer to the base class
	//determines the function that is being called
	Employee *pe;
	cout << "\nInheritance and Polymorphism:\n" << endl;

	pe = &Rafa;
	pe->show_info();
	pe = &Mario;
	pe->show_info();
	pe = &Anton;
	pe->show_info();
	pe = &Luis;
	pe->show_info();
	pe = &Pablo;
	pe->show_info();

	cout << "Ya he terminado." << endl;
}
