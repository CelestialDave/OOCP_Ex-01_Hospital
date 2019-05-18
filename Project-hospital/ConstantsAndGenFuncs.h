#pragma warning(disable: 4996)

#ifndef Constants__H
#define Constants__H

#include <string.h>
#include <iostream>
using namespace std;

enum Results {SUCCESS, NOTFOUND, BADINPUT, BADFORMAT, NODEPS, DEPEXIST, NOSTAFF, NOSURGINHOS, 
	NOSURGINDEP, EIDEXIST, PIDEXIST, EIDNOTFOUND, PIDNOTFOUND, RNONEXIST, RESINSTEMPTY};
enum VisitType {CHECKUP, SURGERY};

//#define MAX_MENU_OPTIONS 11
#define MAX_NAME 100
// Date MAX values:
#define MAX_DAY 31
#define MAX_MONTH 12
#define MIN_YEAR 2000
#define MAX_YEAR 2050
#define CHECKUP 1
#define SURGERY 2

//bool convertStrDateToDateObj(char* strDate, Date* resDate)
//{
//	int day;
//	int month;
//	int year;
//
//	char* str = strtok(strDate, "/");
//	day = atoi(str);
//	str = strtok(NULL, "/");
//	month = atoi(str);
//	str = strtok(NULL, "/");
//	year = atoi(str);
//	str = strtok(NULL, "/");
//	if (str != NULL)
//		return false;
//	if ((day < 0) || (day > MAX_DAY) || (month < 0) || (month > MAX_MONTH) || (year < MIN_YEAR) || (year > MAX_YEAR))
//		return false;
//
//	resDate = new Date(day, month, year);
//	return true;
//}


#endif // !Constants__H