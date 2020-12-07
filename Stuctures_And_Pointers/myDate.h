// Isaiah Guardado
// CECS 282-05
// Prog 3 - Structs and Pointers
// October 15th 2019

#ifndef myDate_h
#define myDate_h
#include <string>


using namespace std;

class myDate {
private:
	int day;
	int month;
	int year;

public:
	myDate(); //default constructor. This will set the date to May 11, 1959

	myDate(int M, int D, int Y); // overload constructor. This will set the date to the values passed in through the
								 // parameters list represented by Month, Day, and Year

	void display(); // display the date in the following format (May 11, 1959) Do NOT print a linefeed after the date

	void increaseDate(int days); // increment the date by the amount of "days"

	void decreaseDate(int days); // decrease the date by the amount of "days"

	int daysBetween(myDate D); // return the number of days between this date and the date "days". If date "days"
								  // is a future date, the return value will be a positive int. Vice versa

	int getDay(); // return the day of the month

	int getMonth(); // return the month in integer form

	int getYear(); // return the year

	int dayOfYear(); // return the number of days since the current year began. Example Jan 1 is 1, Feb 1 is 32

	string dayName(); // returns Monday, Tuesday, etc. according to the day of the week
};

#endif
