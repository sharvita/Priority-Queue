//sharvita 
using namespace std;
#include "Store.h"


Store::Store() {}//left blank on purpose

/*
this is used to input from file,
uses string stream to taken in numbers and puts them in the 
correct variable 
*/
void Store::inputFile() {

	ifstream infile("input.txt");
	char identity = 'A';//different identities for people

	if (infile)
	{
		while (!infile.eof())
		{
			stringstream ss;
			int timeOfEntry, timeOfWaiting ;

			string readString;

			getline(infile, readString, '\n');

			ss << readString;
			
			ss >> timeOfEntry >> timeOfWaiting; //sets varuabkes 

			if (ss.fail())
			{
				cout << "Invalid data in the file\n";
				
				ss.clear();
			}

			//notes arrival in the directory
			Directory takeInLine(timeOfEntry, timeOfWaiting, identity);
			//priority queue is used 
			priorityQueue.push(takeInLine);

			//next customer 
			numOfCustomers++;
			identity++;
		}
		infile.close();
	}
	else
		cout << "There is no file with this name\n";
}

/*
this was taken from the book on page 406 and people have helped me on this as well. My bain hurts. 
this controls the whole program and checks if priority queue is empty.
If not, then goes through it to check arrivals and departures.
*/
void Store::simulate() {
	
	cashier.setAvailable(true);

	while (!priorityQueue.empty())
	{
		
		Directory direct;
		direct = priorityQueue.top();

		currentTime = direct.getTime();
		
		if (direct.getType() == 'A') //checks type and calls the functions accordingly 
			processArrival(direct);
		
		else if (direct.getType() == 'D')
			processDeparture();
	}
}
/*
this was taken from the book on page 406 and people have helped me on this as well. this 
is called when arrival has happened and notes the info in the directory.
*/
void Store::processArrival(Directory& arrive) {

	priorityQueue.pop();//taken out

	if (line.empty() && cashier.isAvailable())//checks if cashier is available
	{
		Directory newLeavingTime = arrive; //creates time for departure of customer 
		int time1 = (currentTime + newLeavingTime.getSaleTime()); //calculates time 

		newLeavingTime.setTime(time1); //enters into directory
		newLeavingTime.setType('D'); //changes to leaving time 

		priorityQueue.push(newLeavingTime); //recorded in priority queue 

		cashier.setAvailable(false); //cashier is now busy because he/she is helping the customer 

		cout << "Processing an arrival event at time:      ";
		cout << currentTime << endl;
	}
	else
	{
		line.push(arrive); // the customer has arrived 

		cout << "Processing an arrival event at time:      ";
		cout << right << currentTime << endl;
	}
}
/*
this was taken from the book on page 406 and people have helped me on this as well. This is only called 
when a customer is leaving 
*/
void Store::processDeparture() {
	priorityQueue.pop(); // pops the first one from priority queue 

	if (!line.empty())
	{
		Directory newLeavingTime = line.front(); //sets new leaving time 
		line.pop();

		
		if (newLeavingTime.getTime() <= currentTime)//Set wait time for moved customer
		{
			
			newLeavingTime.setWaitTime(currentTime - newLeavingTime.getTime());//Set wait time
			
			waitTime += newLeavingTime.getWaitTime();//calculates wait time
		}

		//Create departure event for current customer, use time and transaction time
		int newLeavingTimeTime = currentTime + newLeavingTime.getSaleTime();
		newLeavingTime.setTime(newLeavingTimeTime);
		newLeavingTime.setType('D');
		//Push new leaving time to priority queue
		priorityQueue.push(newLeavingTime);

		cout << "Processing a departure event at time:     ";
		cout << currentTime << endl;
	}
	else
	{
	
		cashier.setAvailable(true);

		cout << "Processing a departure event at time:     ";
		cout << currentTime << endl;
	}
}
int Store::getNumOfCustomers() {
	return numOfCustomers;
}
int Store::getWaitTime() {
	return waitTime;
}