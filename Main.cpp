#include <iostream>
using namespace std;
#include "Employee.h"
#include <vector>



int main() {

	int choice = 0;
	string efirstName = "";
	string elastName = "";
	vector<Employee*> eList;
	vector<Employee*>::iterator it;






	while (choice != 5) {
		cout << "1.Add Record/2.Delete Record/3.Modify Record/4.List Record/5.Exit";
		cin >> choice;
		if (choice == 1) {
			cout << "FirstName: ";
			cin >> efirstName;
			cout << "\nLastName: ";
			cin >> elastName;
			Employee one(efirstName, elastName);
			Employee* e = new Employee(efirstName, elastName);
			eList.push_back(e);
		}
		else if (choice == 4) {
			for (it = eList.begin(); it != eList.end(); it++) {
				cout << "FirstName: ", (*it)->getFirstName(), "LastName: ", (*it)->getLastName();
				cout << endl;
			
			}
		
		}
	
	
	}

	cout << "Goodbye!" << endl;
	return 0;

}
