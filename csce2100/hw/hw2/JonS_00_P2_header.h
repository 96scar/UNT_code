using namespace std;

class person // single person class
{
private:
	string name;
	int ID;
//later add addresses, spouses, kids, etc….
public:
	person();
	person(string n, int id);
	string getName();
	int getID();
};

class people // collection of person people class
{
private:
	int count; // count of people, used for id's
	person p;
	list<person> ppl; // list
	list<person>::iterator iter; // iterator
public:
	people(); // constructor
	~people(); // destructor
	void add(string name);
	void search(string name);
	void remove(string name);
	void print();
	void file(string filename);
};
