#ifndef  ResearcherDoctor__H
#define	 ResearcherDoctor__H

#include "researcher.h"
#include "doctor.h"

class ResearcherDoctor : public Researcher, public Doctor
{
public:
	ResearcherDoctor(const Researcher & researcher, const Doctor& doctor);
	ResearcherDoctor(ifstream& inFile);
	virtual void print(ostream& os) const;
	virtual void toOs(ostream& os) const;

};

#endif // ! ResearcherDoctor__H