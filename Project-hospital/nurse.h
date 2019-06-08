#ifndef Nurse__H
#define Nurse__H

#include "ConstantsAndGenFuncs.h"
#include "StaffMember.h"
#include "hospitalException.h"

class Nurse : virtual public StaffMember
{
private:
	int yearsOfExperience;
	
protected:
	// Copy C'tor:
	Nurse(const Nurse& other) = delete;

public:
	// C'tor:
	Nurse(const string name, int inYearExp) throw(StringException);
	// D'tor:
	~Nurse();
	
	int getYearsOfExp()const;

	virtual void print(ostream& os) const;
};
#endif 