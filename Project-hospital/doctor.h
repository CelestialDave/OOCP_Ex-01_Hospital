#ifndef Doctor__H
#define Doctor__H

#include "ConstantsAndGenFuncs.h"
#include "StaffMember.h"


class Doctor : virtual public StaffMember
{
protected:
	string specialty; //name of exist department
	// Copy C'tor:
	Doctor(const Doctor& other);

public:
	// C'tor:
	Doctor(const string name,const string inSpecialty);
	// D'tor:
	virtual ~Doctor();

	const string getSpciality()const;
	virtual void print(ostream& os) const;
};

#endif // !Doctor__H