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
