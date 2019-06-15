#ifndef Surgeon__H
#define Surgeon__H

#include "doctor.h"

class Surgeon : virtual public Doctor
{
protected:
	int numSurgeries;
public:
	Surgeon(const Doctor& doctor, int numSurgeries);
	Surgeon(ifstream& inFile);

	virtual ~Surgeon();

	int getNumSurgeries() const;
	virtual void print(ostream& os) const;
	virtual void toOs(ostream& os) const;
	void addSurgery();
	friend ifstream& operator >> (ifstream& inFile, Surgeon& surgeon);

};

#endif
