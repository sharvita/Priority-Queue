//sharvita 

#include <iostream>
#include <queue>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

#include "Directory.h"
#include "Cashier.h"

#ifndef Store_h
#define Store_h

class Store
{
private:
	queue<Directory> line;
	priority_queue<Directory> priorityQueue;
	int currentTime = 0;
	int numOfCustomers = 0;
	int waitTime = 0;
	Cashier cashier;                  \
public:
	Store();
	int getNumOfCustomers();
	int getWaitTime();
	void inputFile();
	void simulate();            
	void processArrival(Directory&);      
	void processDeparture();    
};

#endif
