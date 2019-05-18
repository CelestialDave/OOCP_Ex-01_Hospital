#ifndef DATE_H
#define DATE_H

#include "ConstantsAndGenFuncs.h"


class Date
{
private:
	int day;
	int month;
	int year;

public:
	//C'tor
	Date()=default;
	Date(int inDay, int inMonth, int inYear);
	//copy C'tor
	//Date(const Date &other);     ***

	int getYear() const;
	int getMonth() const;
	int getDay() const;
	friend ostream& operator<<(ostream& os, const Date& date);
};
#endif