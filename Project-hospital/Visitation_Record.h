#ifndef VISITATION_H
#define VISITATION_H

#include "Date.h"
#include "ConstantsAndGenFuncs.h"

class Patient;

enum eGender { Male, Female};

class VisitationRecord
{
protected:
	Patient* patient;
	char* staffMemInChargeName;
	Date arrivalDate;
	char* visitationPurpose;

public:
	// C'tor:
	VisitationRecord(Patient& inPatient,char* inStaffMemInChargeName, Date& inArrivalDate, char* inVisitPurpose);
	// Copy C'tor:
	VisitationRecord(const VisitationRecord& other);
	// D'tor:
	virtual ~VisitationRecord();

	const char* getstaffMemInChargeName() const;
	Date getArrivalDate() const;
	const char* getVisitationDescription() const;
	////void  printVisitationPurpose() const;
};

#endif