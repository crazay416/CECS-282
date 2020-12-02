#include "Employee.h"
#include <iostream>
using namespace std;


Employee::Employee() {
	firstName = "N/A";
	lastName = "N/A";
	companyName = "N/A";

}

Employee::Employee(string fName, string lName) {
	firstName = fName;
	lastName = lName;
}


void Employee::setFirstName(string fName) {
	firstName = fName;
}

void Employee::setLastName(string lName) {
	lastName = lName;
}

void Employee::setCompanyName(string cName) {
	companyName = cName;
}


string Employee::getFirstName() {
	return firstName;
}

string Employee::getLastName() {
	return lastName;
}

string Employee::getCompanyName() {
	return companyName;
}

