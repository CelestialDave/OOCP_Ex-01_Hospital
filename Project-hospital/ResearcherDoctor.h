#ifndef  ResearcherDoctor__H
#define	 ResearcherDoctor__H

#include "researcher.h"
#include "doctor.h"

class ResearcherDoctor : public Researcher, public Doctor
{
public:
	ResearcherDoctor(const Researcher & researcher, const Doctor& doctor);
};

#endif // ! ResearcherDoctor__H