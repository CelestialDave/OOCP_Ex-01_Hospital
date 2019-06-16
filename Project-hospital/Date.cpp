
#include "Date.h"
#include "Utils.h"

Date::Date(int inDay, int inMonth, int inYear) throw(DateException)
{
	if (inDay > MAX_DAY || inDay<=0 || inMonth<=0 || inMonth > MAX_MONTH || inYear > MAX_YEAR || inYear < MIN_YEAR)
		throw DateException();
	else
	{
		day = inDay;
		month = inMonth;
		year = inYear;
	}
}

Date::Date(string strDate) throw(HospitalException)
{
	vector<string> temp = Utils::split(strDate, "/");
	if (temp.size() != 3)
		throw FormatException();
	else 
	{
		int day = stoi(temp[0]);
		int month = stoi(temp[1]);
		int year = stoi(temp[2]);
		if (day > MAX_DAY || day <= 0 || month <= 0 || month > MAX_MONTH || year > MAX_YEAR || year < MIN_YEAR)
			throw DateException();
		this->day = day;
		this->month = month;
		this->year = year;
	}		
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