#include "Patient.h"

Patient::Patient(const char* inName, eGender inGender, Date inDateOBirth)
{
	copyName(inName, name);
	gender = inGender;
	dateOfBirth = inDateOBirth;
	visits = nullptr;
	logSizeOfVisits = 0;
	phySizeOfVisits = 0;
	departmentsVisited = nullptr;
	logsizeOfDepartments = 0;
	phySizeOfDepartments = 0;

}

Patient::~Patient()
{
	delete[]name;
	int i;
	for (i = 0; i < logSizeOfVisits; i++)
		delete[]visits[i];
	delete[]visits;
	for (i = 0; i < logsizeOfDepartments; i++)
		delete[]departmentsVisited[i];
	delete[]departmentsVisited;
}

bool Patient::addVistation(VisitationRecord& newVisit)
{
		if (phySizeOfVisits == 0) //if the first researcher
		{
			visits = new VisitationRecord*;
			phySizeOfVisits++;
		}
		else if (logSizeOfVisits == phySizeOfVisits) //if there is no place in the array
		{
			phySizeOfVisits *= 2;
			reallocationArr();  //to reallocte the array to the new size
		}
		if (logSizeOfVisits < phySizeOfVisits)
		{
			visits[logSizeOfVisits] = &newVisit;
			logSizeOfVisits++;
		}
		return true;
	}
}

