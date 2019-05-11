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
