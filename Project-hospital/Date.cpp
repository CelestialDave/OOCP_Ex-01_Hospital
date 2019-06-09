
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

Date::Date(string strDate) throw(FormatException)
{
	vector<string> temp = Utils::split(strDate, "/");
	if (temp.size() == 3)
	{
		int day = stoi(temp[0]);
		int month = stoi(temp[1]);
		int year = stoi(temp[2]);
		new Date(day, month, year);
	}
	else
		throw FormatException();
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

////bool Date::convertStrDateToDateObj(string strDate, Date** resDate) throw(FormatException)
////{
////	int day;
////	int month;
////	int year;
////	vector<string> str = split(strDate, "/ .");
////	if (str.size() == 3)
////	{
////		day = stoi(str[0]);
////		month = stoi(str[1]);
////		year = stoi(str[2]);
////		*resDate = new Date(day, month, year);
////	}
////	else
////		throw FormatException();
////
////	return true;
////}

////vector<string> Date::split(string s, string delimiter) {
////	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
////	string token;
////	vector<string> res;
////
////	while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
////		token = s.substr(pos_start, pos_end - pos_start);
////		pos_start = pos_end + delim_len;
////		res.push_back(token);
////	}
////
////	res.push_back(s.substr(pos_start));
////	return res;
////}