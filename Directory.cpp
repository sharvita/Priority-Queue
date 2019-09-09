//sharvita 
#include "Directory.h"
using namespace std;

Directory::Directory() {
	//intentionally left blank
}
Directory::Directory(int entrytime, int saleTime, char id) : time(entrytime), salesTime(saleTime), customerID(id), type('A')  {
	//intentionally left blank
}
void Directory::setType(char t) {
	type = t;
}
char Directory::getType() const {
	return type;
}
void Directory::setCustomerID(char& id) {
	customerID = id;
}
char Directory::getCustomerID() const {
	return customerID;
}
void Directory::setTime(int& t) {
	time = t;
}
int Directory::getTime() const {
	return time;
}
void Directory::setSaleTime(int& st) {
	salesTime = st;
}
int Directory::getSaleTime() const {
	return salesTime;
}
void Directory::setWaitTime(int wt) {
	waitTime = wt;
}
int Directory::getWaitTime() const {
	return waitTime;
}
/*
This overloaded operator helps to set the events of higher priority in front
*/
bool Directory :: operator < (const Directory& object) const {
	return ((10000 - time) < (10000 - object.time));
}