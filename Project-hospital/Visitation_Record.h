#ifndef VISITATION_H
#define VISITATION_H

#include "Date.h"
#include "ConstantsAndGenFuncs.h"
//#include "Patient.h"
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
	~VisitationRecord();

	const char* getstaffMemInChargeName() const;
	const void showDate() const;
	const Date& getArrivalDate() const;
	void  printVisitationPurpose() const;
};

#endif