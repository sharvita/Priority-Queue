//sharvita 
#ifndef Cashier_h
#define Cashier_h

class Cashier
{
private:
	bool isAvail;
public:
	bool isAvailable() { return isAvail; };
	void setAvailable(bool _available) { isAvail = _available; };
};

#endif 
