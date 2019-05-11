#include "Surgeon.h"
#include "ConstantsAndGenFuncs.h"

Surgeon::Surgeon(const Doctor& doctor, int numSurgeries) :
	StaffMember(doctor.getName(), doctor.getEmployeeIDNumber()), Doctor(doctor)
{
	this->numSurgeries = numSurgeries;
}
Surgeon::~Surgeon() {}

int Surgeon:: getNumSurgeries() const
{
	return numSurgeries;
}

ostream& operator<<(ostream& os, const Surgeon& surgeon)
{
	os << (StaffMember&)surgeon << "\tRole: Surgeon." << "\n\tSpecialty: " << surgeon.specialty
		<< "\n\tNumber of Surgeries Performed: " << surgeon.numSurgeries;
	return os;
}