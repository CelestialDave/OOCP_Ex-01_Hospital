#include "StaffMember.h"

// C'tor:
StaffMember::StaffMember(const string name) :employeeIDNumber(counterEmployeeID++)
{
	this->name = strdup(name);
	//this->employeeIDNumber = employeeIDNumber;
}

// Copy C'tor:
StaffMember::StaffMember(const StaffMember& other)
{
	if (this->employeeIDNumber != other.employeeIDNumber)
	{
		delete[] name;
		this->name = strdup(other.name);
		this->employeeIDNumber = employeeIDNumber;
	}
}

// D'tor:
StaffMember::~StaffMember()
{
	delete[] name;
}

const string StaffMember::getName()const
{
	return this->name;
}

const int StaffMember::getEmployeeIDNumber() const
{
	return this->employeeIDNumber;
}

void StaffMember::print(ostream& os) const
{
	os << "Employee-ID Number: " << this->employeeIDNumber << "\n\tName: " << this->name;
}

ostream& operator<<(ostream& os, const StaffMember& staffmember)
{
	staffmember.print(os);
	return os;
}

int StaffMember::counterEmployeeID = 1;