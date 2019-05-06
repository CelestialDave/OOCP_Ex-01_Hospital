#ifndef __STAFF_MEMBER_H
#define __STAFF_MEMBER_H

#include "ConstantsAndGenFuncs.h"


class StaffMember
{
protected: 
	char* name;
	int employeeIDNumber;
	// C'tor:
	StaffMember(const char* inName, int inEmployeeIDNumber);
	// Copy C'tor:
	StaffMember(const StaffMember& other);

public:
	// D'tor:
	~StaffMember();

	const char*getName()const;
	const int getEmployeeIDNumber()const;
};

#endif // __STAFF_MEMBER_H