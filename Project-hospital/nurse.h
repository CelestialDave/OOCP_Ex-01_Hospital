#ifndef Nurse__H
#define Nurse__H

#include "ConstantsAndGenFuncs.h"

class Nurse
{
private:
	char* name;
	int employeeIDNumber;
	int yearsOfExperience;

public:
	// C'tor:
	Nurse(char* inName,int inYearExp);
	// Copy C'tor:
	Nurse(const Nurse& other) = delete;
	// D'tor:
	~Nurse();
};
#endif 