#ifndef Doctor__H
#define Doctor__H

#include "ConstantsAndGenFuncs.h"
#include "StaffMember.h"


class Doctor : virtual public StaffMember
{
protected:
	char* specialty; //name of exist department
	// Copy C'tor:
	Doctor(const Doctor& other);

public:
	// C'tor:
	Doctor(const char* name, int employeeIDNumber, const char* inSpecialty);
	// D'tor:
	virtual ~Doctor();

	const char* getSpciality()const;
};

#endif // !Doctor__H