#include "ConstantsAndGenFuncs.h"
#include "Date.h"
#include "Utils.h"

bool Utils::convertStrDateToDateObj(string strDate, Date** resDate)
{
	int day;
	int month;
	int year;

	string str = strtok(strDate, "/");
	day = stoi(str);
	str = strtok(NULL, "/");
	month = stoi(str);
	str = strtok(NULL, "/");
	year = stoi(str);
	str = strtok(NULL, "/");
	if (str != NULL)
		return false;
	if ((day < 0) || (day > MAX_DAY) || (month < 0) || (month > MAX_MONTH) || (year < MIN_YEAR) || (year > MAX_YEAR))
		return false;

	*resDate = new Date(day, month, year);
	return true;
}

bool Utils:: ifIndexInRange(const int&index, const int& logSize)
{
	if (index >= 0 && index < logSize)
		return true;
	else
		return false;
}
