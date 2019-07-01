#include "StaffMember.h"


// C'tor:
StaffMember::StaffMember(const string name) throw(StringException) :employeeIDNumber(counterEmployeeID++)
{
	if (!Utils::isValidString(name))
		throw StringException();
	else
		this->name = name;
}

StaffMember::StaffMember(ifstream& inFile)
{
	inFile >> *this;
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


 void StaffMember::setCounter(int num)
 {
	 counterEmployeeID = num;
 }

ostream& operator<<(ostream& os, const StaffMember& staffmember)
{
	if (typeid(os) == typeid(ofstream))
	{
		os << typeid(staffmember).name() + 6 << endl;
		os << staffmember.getName() << endl;
		os << staffmember.getEmployeeIDNumber() << endl;
		staffmember.toOs(os);
	}
	else
		staffmember.print(os);

	return os;
}

istream& operator>>(istream& inFile,StaffMember& staffmember)
{
	if (typeid(inFile) == typeid(ifstream))
	{
		getline(inFile, staffmember.name);
		string tempEmployeeID;
		getline(inFile, tempEmployeeID);
		staffmember.employeeIDNumber = stoi(tempEmployeeID);
	}
	return inFile;
}


int StaffMember::counterEmployeeID = 1;