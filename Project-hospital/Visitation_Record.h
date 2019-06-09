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
	string staffMemInChargeName;
	Date arrivalDate;
	string visitationPurpose;

public:
	// C'tor:
	VisitationRecord(Patient& inPatient,string inStaffMemInChargeName, Date& inArrivalDate, string inVisitPurpose);
	// Copy C'tor:
	VisitationRecord(const VisitationRecord& other);
	// D'tor:
	virtual ~VisitationRecord();

	const string getstaffMemInChargeName() const;
	Date getArrivalDate() const;
	const string getVisitationDescription() const;
};

#endif