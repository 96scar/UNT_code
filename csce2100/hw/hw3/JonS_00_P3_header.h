using namespace std;

void commands();
string convert(string word);
string capitalize(string word);
string lowercase(string word);

class person // single person class
{
private:
	string first; //first name
	string last; //last name
	string address1; //address1
	string city; //city
	string state;//state
	string zip; //zip
	string date_birth; //date_birth
	string date_death; //date_death
	string date_wedding; //date_wedding
	string spousefirst; //spouse
	string spouselast;
	string childfirst; //child
	string childlast;
	string ID; //id

	int childcount;
	person *child[3];
	
public:
	person();
	string getFirst();
	string getLast();
	string getAddress();
	string getCity();
	string getState();
	string getZip();
	string getBirth();
	string getDeath();
	string getWed();
	string getSpouseFirst();
	string getSpouseLast();
	string getChildFirst();
	string getChildLast(); 
	string getID();
	
	void showChildren();
	
	void setName(string fs, string ls);
	void setAddress(string adr);
	void setCity(string c);
	void setState(string st);
	void setZip(string z);
	void setBirth(string birth);
	void setDeath(string death);
	void setWed(string wed);
	void setSpouse(string sfs, string sls);
	void setChild(person *c, string cfs, string cls);
	void setID(string id);	
	
};

class people // collection of person people class
{
private:
	person p;
	list<person> ppl; // list
	list<person>::iterator iter; // iterator
	int count; // count of people, used for id's
public:

	people(); // constructor
	~people(); // destructor
	void addName(string first, string last);
	void addAddress(string address, string ID);
	void addCity(string city, string ID);
	void addState(string state, string ID);
	void addZip(string zip, string ID);
	void addBirth(string date_birth, string ID);
	void addDeath(string date_death, string ID);
	void addWed(string date_wed, string ID);
	void addSpouse(string spousefirst, string spouselast, string ID);
	void addChild(string childfirst, string childlast, string ID);
	void search(string first, string last);
	void printAll();
	void printID(string ID);
	void file(string filename);
	int duplicate(string first, string last);
};
