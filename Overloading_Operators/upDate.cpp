// Isaiah Guardado
// CECS 282-05
// Prog 4 - upDate Project
// Ocotber 1st 2019

#include "upDate.h"
#include <iostream>

using namespace std;

int upDate::count = 0;


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

int Greg2Julian(int month, int day, int year) {


	int JD;
	int i = year;
	int j = month;
	int k = day;

	JD = k - 32075 + 1461 * (i + 4800 + (j - 14) / 12) / 4 + 367 * (j - 2 - (j - 14) / 12 * 12) / 12 - 3 * ((i + 4900 + (j - 14) / 12) / 100) / 4;

	return JD;

}

upDate::upDate() {
	count++;
	pointer = new int [3];
	pointer[0] = 5;
	pointer[1] = 11;
	pointer[2] = 1959;
}

upDate::upDate(int M, int D, int Y) {
	count++;
	pointer = new int[3];
	pointer[0] = M;
	pointer[1] = D;
	pointer[2] = Y;
}

upDate::upDate(int JD) {
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

	count++;
	pointer = new int[3];
	pointer[0] = J;
	pointer[1] = K;
	pointer[2] = I;
}


upDate::upDate(const upDate& theDate) {
	
	count++;
	pointer = new int[3];
	pointer[0] = theDate.pointer[0];
	pointer[1] = theDate.pointer[1];
	pointer[2] = theDate.pointer[2];
}



upDate::~upDate() {
	count--;
	delete[]pointer;
}

void upDate::setDate(int M, int D, int Y) {
	pointer = new int[3];
	pointer[0] = M;
	pointer[1] = D;
	pointer[2] = Y;
}

int upDate::getDay() {
	return pointer[1];
}

int upDate::getMonth() {
	return pointer[0];
}

int upDate::getYear() {
	return pointer[2];
}

string upDate::getMonthName() {
	string totalMonths[12] = { "January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December" };

	return totalMonths[pointer[0] - 1];
}

int upDate::operator-(upDate date) {
	int x = Greg2Julian(date.getMonth(), date.getDay(), date.getYear());
	int y = Greg2Julian(getMonth(), getDay(), getYear());
	int newTotal = y - x;
	return newTotal;
}

upDate upDate::operator+=(int num) {
	int x = Greg2Julian(getMonth(), getDay(), getYear());
	int newTotal = x + num;
	int m;
	int d;
	int y;
	Julian2Greg(newTotal, m, d, y);
	pointer[0] = m;
	pointer[1] = d;
	pointer[2] = y;
	upDate newDate(getMonth(), getDay(), getYear());
	return newDate;
}

upDate upDate::operator-=(int num) {
	int x = Greg2Julian(getMonth(), getDay(), getYear());
	int newTotal = x - num;
	int m;
	int d;
	int y;
	Julian2Greg(newTotal, m, d, y);
	pointer[0] = m;
	pointer[1] = d;
	pointer[2] = y;
	upDate newDate(getMonth(), getDay(), getYear());
	return newDate;
}

upDate upDate::operator+(int num) {
	int x = Greg2Julian(getMonth(), getDay(), getYear());
	int newTotal = x + num;
	int m;
	int d;
	int y;
	Julian2Greg(newTotal, m, d, y);
	upDate newDate(m, d, y);
	return newDate;
}

upDate upDate::operator-(int num) {
	int x = Greg2Julian(getMonth(), getDay(), getYear());
	int newTotal = x - num;
	int m;
	int d;
	int y;
	Julian2Greg(newTotal, m, d, y);
	upDate newDate(m, d, y);
	return newDate;
}

upDate operator+(int num, upDate theDate) {
	int x = Greg2Julian(theDate.getMonth(), theDate.getDay(), theDate.getYear());
	int newTotal = num + x;
	int m;
	int d;
	int y;
	Julian2Greg(newTotal, m, d, y);
	upDate newDate(m, d, y);
	return newDate;
}

ostream& operator << (ostream& out, upDate theDate) {
	out << theDate.getMonth();
	out << "/" << theDate.getDay();
	out << "/" << theDate.getYear();
	return out;
}

upDate upDate::operator++() { // prefix operator
	*this += 1;
	return *this;
}

upDate upDate::operator++(int num) { // postfix operator
	upDate temp(*this);
	*this += 1;
	return temp;
}

int upDate::julian() {
	int x = Greg2Julian(getMonth(), getDay(), getYear());
	return x;
}

upDate upDate::operator=(upDate theDate) {
	pointer[0] = theDate.pointer[0];
	pointer[1] = theDate.pointer[1];
	pointer[2] = theDate.pointer[2];
	upDate newDate(pointer[0], pointer[1], pointer[2]);
	return newDate;
}

upDate upDate::operator--() {
	*this -= 1;
	return *this;
}

upDate upDate::operator--(int num){
	upDate temp(*this);
	*this -= 1;
	return temp;
}

bool upDate::operator==(upDate theDate) {
	int a = Greg2Julian(getMonth(), getDay(), getYear());
	int b = Greg2Julian(theDate.getMonth(), theDate.getDay(), theDate.getYear());
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

bool upDate::operator<(upDate theDate) {
	int a = Greg2Julian(getMonth(), getDay(), getYear());
	int b = Greg2Julian(theDate.getMonth(), theDate.getDay(), theDate.getYear());
	if (a < b) {
		return true;
	}
	else {
		return false;
	}
}

bool upDate::operator>(upDate theDate) {
	int a = Greg2Julian(getMonth(), getDay(), getYear());
	int b = Greg2Julian(theDate.getMonth(), theDate.getDay(), theDate.getYear());
	if (a > b) {
		return true;
	}
	else {
		return false;
	}
}


int upDate::GetDateCount() {
	return count;
}
