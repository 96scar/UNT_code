//example code from online

#include <iostream>
using namespace std;


class patron
{
private:
    string name;
    int pID;
    string classification;
    patron *next;
public:
    
    patron(string nm, int id, string cls)
    {
        name = nm;
        pID = id;
        classification = cls;
    }
    
    string getName() { return name; }
    int getID() {return pID;}
    string getCls() {return classification;}
    
    void setNext (patron *n)  {next = n; }
    patron *getNext() {return next; }
};


class patrons
{
    
private:
    int pcnt;
    patron *top;
    patron *bottom;
    
public:
    patrons()
    {
        pcnt = 0;
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
        string nm, cls;
        int id, i=0;
        patron *temp, *temp2;
        temp2 = top;
        
	cout << endl << "Enter patron name ";
        cin >> nm;
        cout << endl << "Enter patron ID ";
        cin >> id;
        cout << endl << "Enter patron classification ";
        cin >> cls;
        
        temp = new patron (nm, id, cls);
        if (pcnt == 0)
        {
             top = bottom = temp;
             temp->setNext(NULL);
             pcnt++;
             }
             
             else
             {
                 bottom->setNext(temp);
                 bottom = temp;
                 temp->setNext(NULL);
                 pcnt++;
             }
             
    }
             
             void printPatrons()
             {
                 patron *now = top;
                 while (now != NULL)
                 {
                     cout << "Patron: " << now->getName() << endl;
                     cout << "ID: " << now->getID() << endl;
                     cout << "Classification: " << now->getCls() << endl;
                     now = now->getNext();
                 }
                 
             }
             
};
             
             
             
int main ()
{
     patrons mypatrons;
  
     mypatrons.addPatron();
     mypatrons.addPatron();
     mypatrons.addPatron();
    
    mypatrons.printPatrons();
}

