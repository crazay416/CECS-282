// Isaiah Guardado
// CECS 282-05
// Prog 3 - Structs and Pointers
// October 15th 2019

#include "myDate.h";
#include <string>;
#include <iostream>;
#include <cstdlib>;
#include <ctime>;
#include <iomanip>

struct student {
	char name[20];
	int ID;
	myDate bday;
	string hometown;
	char grade;
};

void populate(student * stud[]);
void display(student * stud[]);
void sortID(student * stud[]);
void sortName(student* stud[]);
void sortHome(student* stud[]);
void sortGrade(student* stud[]);
void sortBirthday(student* stud[]);
void greet();

int main() {
	
	student * stud[9];
	student * copy[9];


	populate(stud);
	
	for (int i = 0; i < 9; i++) {
		copy[i] = new student;
		strcpy_s(copy[i]->name, stud[i]->name);
		copy[i]->grade = stud[i]->grade;
		copy[i]->bday = stud[i]->bday;
		copy[i]->ID = stud[i]->ID;
		copy[i]->hometown = stud[i]->hometown;
	}

	int choice;
	greet();
	cin >> choice;

	while (choice != 7) {
		if (choice == 1) {
			cout << "\n";
			display(stud);
			cout << "\n";
			greet();
			cin >> choice;
			cout << "\n";
		}
		else if (choice == 2) {
			cout << "\n";
			sortID(copy);
			display(copy);
			cout << "\n";
			greet();
			cin >> choice;
			cout << "\n";
		}
		else if (choice == 3) {
			cout << "\n";
			sortName(copy);
			display(copy);
			cout << "\n";
			greet();
			cin >> choice;
			cout << "\n";
		}
		else if (choice == 4) {
			cout << "\n";
			sortGrade(copy);
			display(copy);
			cout << "\n";
			greet();
			cin >> choice;
			cout << "\n";
		}
		else if (choice == 5) {
			cout << "\n";
			sortBirthday(copy);
			display(copy);
			cout << "\n";
			greet();
			cin >> choice;
			cout << "\n";
		}
		else if (choice == 6) {
			cout << "\n";
			sortHome(copy);
			display(copy);
			cout << "\n";
			greet();
			cin >> choice;
			cout << "\n";
		}
	}
	system("PAUSE");
}

void greet() {
	cout << "1) Display original list (in the order it was created)" << endl;
	cout << "2) Display list sorted by StudentID" << endl;
	cout << "3) Display list sorted by Name" << endl;
	cout << "4) Display list sorted by Grade" << endl;
	cout << "5) Display list sorted by Birthday" << endl;
	cout << "6) Display list sorted by Hometown" << endl;
	cout << "7) Exit" << endl;

}

void populate(student* s[]) {

	string names[10] = { "Isaiah", "Melanie", "Steve", "Ariana", "Adam", "Aaron", "Miranda", "Ernesto", "Cecy", "Teresa" };
	char grades[5] = { 'A', 'B', 'C', 'D', 'F' };
	int idArray[10];
	string hTown[] = { "Long Beach", "Los Angeles", "Carson", "Wilmington", "Torrance", "San Diego", "Malibu", "San Jose", "Las Vegas", "New York" };

	srand(time(0));

	for (int i = 0; i < 10; i++) {
		int x = rand() * 10;
		while (x < 99999) {
			x = rand() * 10;
		}
		idArray[i] = x;
	}

	for (int i = 0; i < 9; i++) {
		s[i] = new student;
		strcpy_s(s[i]->name, names[i].c_str());
		s[i]->grade = grades[rand() % 5];
		s[i]->bday.increaseDate(rand() % (16671 - 14480) + 14480); //January 1st 1999 = 14480 December 31st 2004 = 16671
		s[i]->ID = idArray[i];
		s[i]->hometown = hTown[i];
	}
}


void sortID(student * s[]) {

	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < 8; i++) {
			if (s[i]->ID > s[i + 1]->ID) {
				student * temp = s[i];
				s[i] = s[i+1];
				s[i + 1] = temp;
				sorted = false;
			}
		}
	
	}
}

void sortName(student* s[]) {
	
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		int v;
		for (int i = 0; i < 8; i++) {
			v = strcmp(s[i]->name, s[i + 1]->name);
			if (v > 0) {
				student* temp = s[i];
				s[i] = s[i + 1];
				s[i + 1] = temp;
				sorted = false;
			}

		}
	}
}

void sortHome(student* s[]) {
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < 8; i++) {
			if (s[i]->hometown > s[i + 1]->hometown) {
				student* temp = s[i];
				s[i] = s[i + 1];
				s[i + 1] = temp;
				sorted = false;
			}
		}
	}
}

void sortGrade(student * s[]) {
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < 8; i++) {
			if (s[i]->grade > s[i + 1]->grade) {
				student* temp = s[i];
				s[i] = s[i + 1];
				s[i + 1] = temp;
				sorted = false;
			}
		}
	}
}

void sortBirthday(student* s[]) {
	myDate compare(0,0,0);
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < 8; i++) {
			if (s[i]->bday.daysBetween(compare) < s[i + 1]->bday.daysBetween(compare)) {
				student* temp = s[i];
				s[i] = s[i + 1];
				s[i + 1] = temp;
				sorted = false;
			}
		}
	}
}

void display(student * s[]) {
	
	cout << left << setw(20) << "StudentID" << left << setw(20) << "Name" << left << setw(20) << "Grade \t" << left << setw(20) << "Birthday\t" << left << setw(20) << "Hometown\t" << endl;
	for (int i = 0; i < 9; i++) {
		cout << left << setw(20) << s[i]->ID;
		cout << left << setw(20) << s[i]->name;
		cout << left << setw(20) << s[i]->grade << left << setw(20);
		s[i]->bday.display();
		cout << left << setw(20);
		cout << left << s[i]->hometown << endl;
	}
}
