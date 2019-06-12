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
	Nurse(const string name, int inYearExp);
	Nurse(ifstream& inFile);
	// D'tor:
	~Nurse();
	
	int getYearsOfExp()const;
	virtual void toOs(ostream& os) const;
	virtual void print(ostream& os) const;
	friend ifstream& operator >> (ifstream& inFile, Nurse& nurse);
};
#endif 