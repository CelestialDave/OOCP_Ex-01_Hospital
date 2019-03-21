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
	Date(int inDay, int inMonth, int inYear);
	void showDate() const;
};

#endif