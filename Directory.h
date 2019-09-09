#ifndef Directory_h
#define Directory_h

class Directory
{
private:
	char type;             
	char customerID;       
	int time;            
	int salesTime;        
	int waitTime;              

public:
	Directory();
	Directory(int, int, char);
	void setType(char);
	char getType() const;
	void setCustomerID(char&);
	char getCustomerID() const;
	void setTime(int&);
	int getTime() const;
	void setSaleTime(int&);
	int getSaleTime() const;
	void setWaitTime(int);
	int getWaitTime() const;
	bool operator < (const Directory&) const;
};

#endif
