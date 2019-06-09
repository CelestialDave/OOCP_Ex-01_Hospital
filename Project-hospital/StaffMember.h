#ifndef __STAFF_MEMBER_H
#define __STAFF_MEMBER_H

#include "ConstantsAndGenFuncs.h"
#include "hospitalException.h"
//#include <ostream>


class StaffMember
{
protected: 
	static int counterEmployeeID;
	//string name;
	string name;
	int employeeIDNumber;
	// C'tor:
	StaffMember(const string inName) throw(HospitalException);
	// Copy C'tor:
	StaffMember(const StaffMember& other);

public:
	// D'tor:
	virtual ~StaffMember();

	const string getName()const;
	const int getEmployeeIDNumber()const;

	virtual void print(ostream& os) const =0;
	//friend ostream& operator<<(ostream& os, const StaffMember& staffmember);
	friend ostream& operator<<(ostream& os, const StaffMember& staffmember);
};



#endif // __STAFF_MEMBER_H

