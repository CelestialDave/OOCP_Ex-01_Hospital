#ifndef Surgeon__H
#define Surgeon__H

#include "doctor.h"

class Surgeon : virtual public Doctor
{
protected:
	int numSurgeries;
public:
	Surgeon(const Doctor& doctor, int numSurgeries);
	virtual ~Surgeon();
	int getNumSurgeries() const;

	virtual void print(ostream& os) const;
	friend ostream& operator<<(ostream& os, const Surgeon& surgeon);
	void addSurgery();


};

#endif
