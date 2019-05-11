#ifndef Nurse__H
#define Nurse__H

#include "ConstantsAndGenFuncs.h"
#include "StaffMember.h"

class Nurse : virtual public StaffMember
{
private:
	int yearsOfExperience;

protected:
	// ???
	// Copy C'tor:
	//Nurse(const Nurse& other);

public:
	// C'tor:
	Nurse(const char* name, int employeeIDNumber, int inYearExp);
	// D'tor:
	~Nurse();
	
	int getYearsOfExp()const;
	friend ostream& operator<<(ostream& os, const Nurse& nurse);
};
#endif 