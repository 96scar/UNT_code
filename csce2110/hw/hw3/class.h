/*
Scarlett Jones
CSCE 2110
Program 3
4/29/16
*/

// classes and function prototypes

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class DAGNode // certain # in list of nodes
{
private:
	// list of predecessors
//	int pre_count;
//	int *pre_top;
//	int *pre_bottom;
//	int *pre_next;
	// list of successors
//	int *suc_count;
//	int *suc_top;
//	int *suc_bottom;
//	int *suc_next;
	int weight; // delay/weight of arc
	DAGNode *next; // access specific nodes
public:
	DAGNode();
	~DAGNode();
	void addPredecessor(); // add predecessor
	void addSuccessor(); // add successor
	int setWeight(int w); // set weight
	//void getPredecessors(); // get predecessors
	//void setNextPre(int *n);
	//int *getNextPre() {return pre_next;}
	//void getSuccessors(); // get successors
	//void setNextSuc(int *n);
	//int *getNextSuc() {return suc_next;}
	int getWeight(); // get weight
	void setNext(DAGNode *n); // set the next node
	DAGNode *getNext() {return next;}
};

class DAG // collection of nodes
{
private:
	int node_count; // node count
	// node #
	// list of nodes
	DAGNode *top;
	DAGNode *bottom;
	// set of sources
	// sink
public:
	DAG(); // constructor
	~DAG(); // desconstructor
	void addNode();
};

class DataReadySet
{
private:
	//a set. like set class from earlier in term???
public:
};