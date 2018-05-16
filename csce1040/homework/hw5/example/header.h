/*Name: Scarlett Jones
Date: 4/16/15
Teacher: Keathly
Description: header file of library database
*/

using namespace std; // needed this to use string types

class patron
{
private:
	string name;
	int pID;
	string address;
	string cell;
	string email;
	patron *next;
public:
	patron(string nm, int id, string ad, string c, string e)
	{
		name = nm;
		pID = id;
		address = ad;
		cell = c;
		email = e;
	}
	string getName();
	int getID();
	string getad();
	string getCell();
	string getEmail();
	void setNext(patron *n);
	patron *getNext()
	{return next;}
};

class patrons
{
private:
	int pcnt;
	patron *top;
	patron *bottom;
public:
	patrons();
	~patrons();
	void addPatron();
	void printPatrons();
	void printAddresses();
	void deletePatron();
	void editPatron();
};

class book
{
private:
	string title;
	string author;
	int bID;
	double cost;
	book *next;
public:
	book(string t, string a, int bid, double c)
	{
		title = t;
		author = a;
		bID = bid;
		cost = c;
	}
	string getTitle();
	string getAuthor();
	int getID();
	double getCost();
	void setNext(book *n);
	book *getNext()
	{return next;}
};

class books
{
private:
	int bcnt;
	book *top;
	book *bottom;
public:
	books();
	~books();
	void addBook();
	void deleteBook();
	void editBook();
};

class transaction
{
private:
	int tID;
	int patron_loc;
	int book_loc;
	time_t start;
	time_t period;
	time_t end;
	transaction *next;
public:
	transaction(int tid, int pLOC, int bLOC, time_t s, time_t p, time_t e)
	{
		tID = tid;
		patron_loc = pLOC;
		book_loc = bLOC;
		start = s;
		period = p;
		end = e;
	}
	int getID();
	int getPLOC();
	int getBLOC();
	time_t getStart();
	time_t getPeriod();
	time_t getEnd();
	void setNext(transaction *n);
	transaction *getNext()
	{return next;}
};

class transactions
{
private:
	int tcnt;
	transaction *top;
	transaction *bottom;
public:
	transactions();
	~transactions();
	void addTran();
	void deleteTran();
};

void store(patrons p, books b, transactions t);
void load(patrons p, books b, transactions t);