#ifndef Surgeon__H
#define Surgeon__H

#include "doctor.h"

class Surgeon : virtual public Doctor
{
protected:
	int numSurgeries;
public:
	Surgeon(const Doctor & other, int numSurgeries);
	int getNumSurgeries() const;

};

#endif