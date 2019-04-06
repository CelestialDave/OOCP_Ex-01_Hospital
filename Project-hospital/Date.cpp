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
	cout << ((day < 10) ? "0" : "") << "/" <<
		((month < 10) ? "0" : "") << "/" << year;
}

