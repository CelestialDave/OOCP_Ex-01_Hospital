#ifndef Nurse__H
#define Nurse__H

#include "ConstantsAndGenFuncs.h"
#include "StaffMember.h"

class Nurse : virtual public StaffMember
{
private:
	int yearsOfExperience;

protected:
	// C'tor:
	Nurse(const StaffMember& staffMember, int inYearExp);
	// Copy C'tor:
	Nurse(const Nurse& other);

public:
	// D'tor:
	~Nurse();
	
	int getYearsOfExp()const;
};
#endif 