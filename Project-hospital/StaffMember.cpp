#include "StaffMember.h"

// C'tor:
StaffMember::StaffMember(const char* name, int employeeIDNumber)
{
	this->name = strdup(name);
	this->employeeIDNumber = employeeIDNumber;
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

const char* StaffMember::getName()const
{
	return name;
}

const int StaffMember::getEmployeeIDNumber() const
{
	return employeeIDNumber;
}

ostream& operator<<(ostream& os, const StaffMember& staffmember)
{
	os << "Employee-ID Number: " << staffmember.employeeIDNumber << "\n\tName: " << staffmember.name;
	return os;
}