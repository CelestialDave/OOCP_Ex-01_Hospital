
#include "Date.h"

Date::Date(int inDay, int inMonth, int inYear) 
{
	/*if (day > MAX_DAY || month > MAX_MONTH || year > MAX_YEAR || year < MIN_YEAR)
		throw DateException();
	else
	{*/
		day = inDay;
		month = inMonth;
		year = inYear;
	//}
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
