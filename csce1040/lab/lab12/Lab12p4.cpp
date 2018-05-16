/*
Scarlett Jones
Keathly 
4/21/15
shows class hierarchy and declaration of the base class
adds member variables to show difference between private and protected
*/

#include <iostream>
#include <string>
#include <cstring>

#define NUM_EMPLOYEES 6

using namespace std;

class Employee 
{
	char name[20];
	long salary;
public:
	char *getName() { return name; }
	long GetSalary() { return salary; }
	
	//constructors
	Employee(char tN[20], long tS)
	{
		//using strcpy() function, assign value to name variable

		strcpy(name, tN);
		salary = tS;
				
	}
	

	//virual function
	virtual void show_info()
	{
		cout << getName();
		cout << GetSalary();
	}
};

class Manager : public Employee
{
protected:
	char *degree;
public:


	//constructor
	Manager(char tN[20], long tS, char *D) : Employee(tN, tS)
	{
		degree = D;
	}

	void show_info()
	{
		cout << getName();
		cout << GetSalary();
		cout << degree;
	}
};

class Worker : public Employee
{
protected:
	char *position;
public:

	//constructor
	Worker(char tN[20], long tS, char *P) : Employee(tN, tS)
	{
		position = P;
	}


	void show_info()
	{
		cout << getName();
		cout << GetSalary();
		cout << position;
	}
};

class Officer : public Worker
{
public:
	//constuctor
	Officer(char tN[20], long tS, char *P) : Worker(tN, tS, P){}


	void show_info()
	{
		cout << getName();
		cout << GetSalary();
		cout << position;
	}

};

class Technician : public Worker
{
public:
	//constructor
	Technician(char tN[20], long tS, char *P) : Worker(tN, tS, P){}


	void show_info()
	{
		cout << getName();
		cout << GetSalary();
		cout << position;
	}

};

int main()
{
	int menu = 1;

	while(menu != 4)
	{
		cout << "Choose 1-4" << endl;
		cin >> menu;

		switch(menu)
		{
			case 1: break;
			case 2: break;
			case 3: break;
			case 4: cout << endl << "Exit" << endl; break;
			default: cout << endl << "Incorect input" << endl; break;
		}
	}

	Employee* EmployeeList[NUM_EMPLOYEES];

	EmployeeList[0] = new Manager((char*)"Carla Garcia ", 35000, (char*)" Economist");
	EmployeeList[1] = new Manager((char*)"Juan Perez ", 38000, (char*)" Ingineer");
	EmployeeList[2] = new Officer((char*)"Pedro Egia ", 18000, (char*)" Officer 1");
	EmployeeList[3] = new Officer((char*)"Luisa Penia ", 15000, (char*)" Officer 2");
	EmployeeList[4] = new Technician((char*)"Javier Ramos ", 19500, (char*)" Welder");
	EmployeeList[5] = new Technician((char*)"Amaia Bilbao ", 12000, (char*)" Electricist");

	for(int i=0;i<NUM_EMPLOYEES;i++)
	{
		EmployeeList[i]->show_info();
		cout << endl;
	}


}
