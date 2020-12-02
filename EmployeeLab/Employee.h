#ifndef Employee_h
#define Employee_h
#include <string>
using namespace std;


class Employee {

private:
	string firstName;
	string lastName;
	string companyName;

public:
	string getFirstName();
	string getLastName();
	string getCompanyName();

	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setCompanyName(string companyName);
	Employee();
	Employee(string fName, string lName);


};




#endif
