#include "ConstantsAndGenFuncs.h"
#include "Date.h"
#include "Utils.h"

//vector<string> Utils:: split(string s, string delimiter) {
//	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
//	string token;
//	vector<string> res;
//
//	while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
//		token = s.substr(pos_start, pos_end - pos_start);
//		pos_start = pos_end + delim_len;
//		res.push_back(token);
//	}
//
//	res.push_back(s.substr(pos_start));
//	return res;
//}
//
//bool Utils::convertStrDateToDateObj(string strDate, Date** resDate) 
//{
//	int day;
//	int month;
//	int year;
//	string str = strtok(strDate, "/");
//	vector<string> str = split(strDate, "/ .");
//	if (str.size() == 3)
//	{
//		day = stoi(str[0]);
//		month = stoi(str[1]);
//		year = stoi(str[2]);
//		*resDate = new Date(day, month, year);
//	}
//	/*if ((day<=0)||(day > MAX_DAY) || (month <= 0) || (month > MAX_MONTH) || (year < MIN_YEAR) || (year > MAX_YEAR))
//		throw DateException();
//	else*/
//	else
//		throw FormatException();
//	
//	return true;
//}

bool Utils:: ifIndexInRange(const int&index, const int& logSize)
{
	if (index >= 0 && index < logSize)
		return true;
	else
		return false;
}

bool Utils::isValidString(string input)
{
	return ((input.length() > 0) && (input != " "));
}