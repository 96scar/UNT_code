/*
Name: Scarlett Jones
Teacher: Keathly
Date: 4/16/15
Description: The header file for the library system
*/

//6 classes from my design

// need constructors?

class patron
{
 private:
	string name;
	string address;
	int pID;
	int cell;
	string email;
	int fines;
	patron *next;
 public:
	patron(string n, string a, int id, int c, string e, int f)
	{
		name = n;
		address = a;
		pID = id;
		cell = c;
		email = e;
		fines = f;
	}
	string getName() {return name;}
	string getAddress() {return address;}
	int getID() {return pID;}
	int getCell() {return cell;}
	string getEmail() {return email;}
	int getFines() {return fines;}

	void setNext(patron *n) {next = n;}
	patron *getNext() {return next;}

//	void addpinfo;
//	void editpinfo;
};


class pcollect
{
 private:
	int pcount;
	patron *top;
	patron *bottom;
 public:
	patrons()
	{
		pcount = 0;
		top = bottom = NULL;
	}
	~patrons()
	{
		patron * now = top;
		while (now != bottom)
		{
			patron * next = now->getNext();
			delete now;
			now = next;
		}
	}
	
	void addPatron()
	{
		string n, a, e;
		int id, c, i=0;
		patron *temp, *temp2;
		temp2 = top;
		
		cout << "Enter patron name: ";
		cin >> n;
		cout << "Enter patron's address: ";
		cin >> a;
		cout << "Enter patron id: ";
		cin >> id;
		cout << "Enter patron's phone number: ";
		cin >> c;
		cout << "Enter patron's email: ";
		cin >> e;
		cout << "Enter fines: ";
		cin >> f;

		temp = new patron(n, a, id, c, e, f);
		if(pcount == 0)
		{
			top = bottom = temp;
			temp->setNext(NULL);
			pcount++;
		}
		else
		{
			bottom->setNext(temp);
			bottom = temp;
			temp->setNext(NULL);
			pcount++;
		}
	}
	
	void printPatrons()
	{
		patron *now = top;
		while(now != NULL)
		{
			cout << "Patron: " << now->getName() << endl;
			cout << "Address: " << now->getAddress() << endl;
			cout << "ID: " << now->getID() << endl;
			cout << "Phone Number: " << now->getCell() << endl;
			cout << "Email: " << now->getEmail() << endl;
			cout << "Fines: " << now->getFines() << endl;
			now = now->getNext();
		}
	}	

	char *plist;
	void addp;
	void removep;
	void findp;
	void sortp;
	void printp;
	void printmail;
	void printfinedp;
};

class tcollect
{
	int tcount;
	char *tlist;
	void addt;
	void removet;
	void findt;
	void updatet;
	void printoverdue;
	void printt;
};

class bcollect
{
	int bcount;
	char *blist;
	void addb;
	void removeb;
	void findb;
};


class trans
{
	int checkoutdate;
	int timepass;
	void checkoutb;
	void returnb;
	void replaceb;
	void updatetime;
};

class book
{
	char *title;
	char *author;
	int number;
	bool bcheckout;
	bool blost;
	int duedate;
	int bcost;
	void addbinfo;
	void editbinfo;
};
