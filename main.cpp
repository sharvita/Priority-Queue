//Sharvita Paithankar 

#include <iomanip>
#include <iostream>
#include "Store.h"
using namespace std;

int main()
{
	Store store;
	store.inputFile();
	store.simulate();

	cout << "Final Statistics:\n";

	cout << "Number of customers: " << store.getNumOfCustomers() << endl;

	cout << "Average waiting time: " << (static_cast<double>(store.getWaitTime()) / store.getNumOfCustomers()) << endl;

	//system("pause");
	return 0;
	//system("pause");
}