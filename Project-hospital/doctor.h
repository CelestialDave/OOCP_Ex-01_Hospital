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
	Doctor(const char* name,const char* inSpecialty);
	// D'tor:
	virtual ~Doctor();

	const char* getSpciality()const;
	virtual void print(ostream& os) const;
	//friend ostream& operator<<(ostream& os, const Doctor& doctor);
};

#endif // !Doctor__H