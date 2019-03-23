#ifndef Doctor__H
#define Doctor__H

#include "ConstantsAndGenFuncs.h"


class Doctor
{
private:
	char* name;
	int employeeIDNumber;
	char* specialty;

public:
	// C'tor:
	Doctor(const char* inName, char* inSpecialty);
	// Copy C'tor:
	Doctor(const Doctor& other) = delete;
	// D'tor:
	~Doctor();

	char*getName()const;
	int getEmployeeIDNum()const;
	char* getSpciality()const;
};

#endif // !Doctor__H