#include "StaffMember.h"
#include "Utils.h"


// C'tor:
StaffMember::StaffMember(const string name) throw(NameException) :employeeIDNumber(counterEmployeeID++)
{
	if (!Utils::isValidString(name))
		throw NameException();
	else
		this->name = name;
	//this->employeeIDNumber = employeeIDNumber;
}

// Copy C'tor:
StaffMember::StaffMember(const StaffMember& other)
{
	if (this->employeeIDNumber != other.employeeIDNumber)
	{
		this->name = other.name;
		this->employeeIDNumber = employeeIDNumber;
	}
}

// D'tor:
StaffMember::~StaffMember()
{
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