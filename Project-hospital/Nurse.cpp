#include "nurse.h"

Nurse::Nurse(const char* name,int inYearExp)
	: StaffMember(name)
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

void Nurse::print(ostream& os) const
{
	StaffMember::print(os);
	os << "\tRole: Nurse." << "\n\tYears Of Experience: " << this->yearsOfExperience;
}

//ostream& operator<<(ostream& os, const Nurse& nurse)
//{
//	nurse.print(os);
//	return os;
//}