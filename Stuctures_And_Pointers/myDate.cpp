// Isaiah Guardado
// CECS 282-05
// Prog 3 - Structs and Pointers
// October 15th 2019

#include "myDate.h"
#include <iostream>
#include "myDate.h"


int Greg2Julian(int month, int day, int year) {


	int JD;
	int i = year;
	int j = month;
	int k = day;

	JD = k - 32075 + 1461 * (i + 4800 + (j - 14) / 12) / 4 + 367 * (j - 2 - (j - 14) / 12 * 12) / 12 - 3 * ((i + 4900 + (j - 14) / 12) / 100) / 4;

	return JD;

}

void Julian2Greg(int JD, int& month, int& day, int& year) {
	int L, N, I, J, K;


	L = JD + 68569;
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80; // DAY
	L = J / 11;
	J = J + 2 - 12 * L; // MONTH
	I = 100 * (N - 49) + I + L; // YEAR

	year = I;
	month = J;
	day = K;

}

myDate::myDate() {
	month = 5;
	day = 11;
	year = 1959;
}

myDate::myDate(int M, int D, int Y) {
	if (M > 12) {
		month = 5;
		day = 11;
		year = 1959;
	}
	else {
		month = M;
		day = D;
		year = Y;
	}
}

void myDate::display() {
	string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September",
					"October", "November", "December" };
	string theDate = months[month - 1] + " " + to_string(day) + ", " + to_string(year);
	cout << theDate;
}

void myDate::increaseDate(int days) {
	int x = Greg2Julian(month, day, year);
	//cout << x << endl;
	int total = days + x;
	Julian2Greg(total, month, day, year);
}

void myDate::decreaseDate(int days) {
	int x = Greg2Julian(month, day, year);
	int total = x - days;
	Julian2Greg(total, month, day, year);
}

int myDate::daysBetween(myDate newDate) {
	int newOne = Greg2Julian(newDate.month, newDate.day, newDate.year);
	int original = Greg2Julian(month, day, year);

	int difference;
	difference = newOne - original;

	return difference;
}

int myDate::getDay() {
	return day;
}


int myDate::getMonth() {
	return month;
}


int myDate::getYear() {
	return year;
}

int myDate::dayOfYear() {
	int y = Greg2Julian(month, day, year);
	int x = Greg2Julian(1, 1, year);
	int day = (y - x) + 1;

	return day;
}



string myDate::dayName() {
	int x = Greg2Julian(month, day, year);
	int whichDay = x % 7;
	if (whichDay == 0) {
		return "Monday";
	}
	else if (whichDay == 1) {
		return "Tuesday";
	}
	else if (whichDay == 2) {
		return "Wednesday";
	}
	else if (whichDay == 3) {
		return "Thursday";
	}
	else if (whichDay == 4) {
		return "Friday";
	}
	else if (whichDay == 5) {
		return "Saturday";
	}
	else {
		return "Sunday";
	}
}
