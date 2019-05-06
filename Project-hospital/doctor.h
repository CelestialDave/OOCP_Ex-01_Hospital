#ifndef Doctor__H
#define Doctor__H

#include "ConstantsAndGenFuncs.h"
#include "StaffMember.h"


class Doctor : virtual public StaffMember
{
protected:
	char* specialty; //name of exist department
	// C'tor:
	Doctor(const StaffMember& staffMember, const char* inSpecialty);
	// Copy C'tor:
	Doctor(const Doctor& other);

public:
	
	// D'tor:
	~Doctor();

	const char* getSpciality()const;
};

#endif // !Doctor__H