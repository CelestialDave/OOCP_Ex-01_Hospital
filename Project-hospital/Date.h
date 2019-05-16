#ifndef DATE_H
#define DATE_H

class Date
{
private:
	int day;
	int month;
	int year;

public:
	//C'tor
	Date()=default;
	Date(int inDay, int inMonth, int inYear);
	//copy C'tor
	//Date(const Date &other);     ***
	const void showDate() const;
	int getYear() const;
	int getMonth() const;
	int getDay() const;

};
#endif