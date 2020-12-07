// Isaiah Guardado
// CECS 282-05
// Prog 4 - upDate Project
// Ocotber 1st 2019

#ifndef upDate_h
#include <string>

using namespace std;

class upDate {
private:
	int* pointer;
	static int count;

public:
	upDate();

	upDate(int month, int day, int year);

	upDate(int J);

	~upDate();

	void setDate(int month, int day, int year);

	int getMonth();

	int getDay();

	int getYear();

	string getMonthName();

	int operator-(upDate);

	upDate operator +=(int num);

	upDate operator -=(int num);

	upDate operator+(int num);

	upDate operator-(int num);

	friend upDate operator+(int num, upDate theDate);

	upDate operator++();

	upDate operator=(upDate theDate);

	friend ostream& operator << (ostream& out, upDate theDate);

	int julian();

	upDate(const upDate& theDate);

	upDate operator++(int num);

	upDate operator--();

	upDate operator--(int num);

	bool operator ==(upDate theDate);

	bool operator <(upDate theDate);

	bool operator >(upDate theDate);

	static int GetDateCount();
	
};

#endif
