#include "Surgeon.h"
#include "ConstantsAndGenFuncs.h"

Surgeon::Surgeon(const Doctor & other, int numSurgeries) :StaffMember(other),Doctor(other)
{
	this->numSurgeries = numSurgeries;
}
int Surgeon:: getNumSurgeries() const
{
	return numSurgeries;
}
