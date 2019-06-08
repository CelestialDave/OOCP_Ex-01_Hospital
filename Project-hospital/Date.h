#ifndef DATE_H
#define DATE_H

#include "ConstantsAndGenFuncs.h"
#include "hospitalException.h"
#include <vector>



class Date
{
private:
	int day;
	int month;
	int year;

public:
	//C'tor
	Date()=default;
	Date(int inDay, int inMonth, int inYear) throw(HospitalException);
	//copy C'tor
	//Date(const Date &other);     ***

	int getYear() const;
	int getMonth() const;
	int getDay() const;
	friend ostream& operator<<(ostream& os, const Date& date);
	vector<string> split(string s, string delimiter);
	bool convertStrDateToDateObj(string strDate, Date** resDate) throw(FormatException);


};
#endif