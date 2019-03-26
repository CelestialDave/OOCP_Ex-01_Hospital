#ifndef Doctor__H
#define Doctor__H

#include "ConstantsAndGenFuncs.h"


class Doctor
{
private:
	char* name;
	int employeeIDNumber;
	char* specialty; //name of exist department

public:
	// C'tor:
	Doctor(const char* inName,int inEmployeeIDNumber,const char* inSpecialty);
	// Copy C'tor:
	Doctor(const Doctor& other) = delete;
	// D'tor:
	~Doctor();

	const char*getName()const;
	const int getEmployeeIDNum()const;
	const char* getSpciality()const;
};

#endif // !Doctor__H