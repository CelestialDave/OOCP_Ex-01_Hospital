#include "ConstantsAndGenFuncs.h"
#include "Date.h"

Date::Date(int inDay, int inMonth, int inYear)
{
	day = inDay;
	month = inMonth;
	year = inYear;
}

const void Date::showDate() const
{
	cout << ((day < 10) ? "0" : "") << day << "/" <<
		((month < 10) ? "0" : "") << month << "/" << year;
}

int Date::getYear() const
{
	return year;
}
int Date::getMonth() const
{
	return month;
}
int Date::getDay() const
{
	return day;
}

ostream& operator<<(ostream& os, const Date& date)
{
	os << ((date.day < 10) ? "0" : "") << date.day << "/" <<
		((date.month < 10) ? "0" : "") << date.month << "/" << date.year;
	return os;
}
