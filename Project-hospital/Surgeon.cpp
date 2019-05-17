#include "Surgeon.h"
#include "ConstantsAndGenFuncs.h"

Surgeon::Surgeon(const Doctor& doctor, int numSurgeries) :
	StaffMember(doctor.getName()), Doctor(doctor)
{
	this->numSurgeries = numSurgeries;
}
Surgeon::~Surgeon() {}

int Surgeon:: getNumSurgeries() const
{
	return numSurgeries;
}

void Surgeon::addSurgery()
{
	numSurgeries++;
}

void Surgeon::print(ostream& os) const
{
	StaffMember::print(os);
	os << "\tRole: Surgeon." << "\n\tSpecialty: " << this->specialty
		<< "\n\tNumber of Surgeries Performed: " << this->numSurgeries;
}

//ostream& operator<<(ostream& os, const Surgeon& surgeon)
//{
//	surgeon.print(os);
//	return os;
//}