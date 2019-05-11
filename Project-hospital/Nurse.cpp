#include "nurse.h"

Nurse::Nurse(const char* name, int employeeIDNumber, int inYearExp)
	: StaffMember(name, employeeIDNumber)
{
	yearsOfExperience = inYearExp; 
}

//Nurse::Nurse(const Nurse& other)
//	// ???
//	: StaffMember(other)
//{
//	if (this->yearsOfExperience != other.yearsOfExperience)
//		this->yearsOfExperience = other.yearsOfExperience;
//}

Nurse::~Nurse()
{}

int Nurse::getYearsOfExp()const
{
	return yearsOfExperience;
}

ostream& operator<<(ostream& os, const Nurse& nurse)
{
	os << (StaffMember&)nurse << "\tRole: Nurse." << "\n\tYears Of Experience: " << nurse.yearsOfExperience;
	return os;
}