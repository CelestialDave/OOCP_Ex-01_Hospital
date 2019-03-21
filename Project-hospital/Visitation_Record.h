#ifndef VISITATION_H
#define VISITATION_H
#include "Date.h"
#include "Patient.h"
#include "ConstantsAndGenFuncs.h"

class VisitationRecord
{
private:
	char* name;
	char* id;
	eGender gender;
	Date dateOBirth;
	char* staffMemInChargeName;
	Date arrivalDate;
	char* visitationPurpose;
	// char* department;

public:
	// C'tor:
	VisitationRecord(const char* inName, const char* id, const eGender inGender, const Date inDateOBirth, 
		const char* inStaffMemInChargeName, const Date arrivalDate, const char* inVisitPurpose="N/A");
	// Copy C'tor:
	VisitationRecord(const VisitationRecord& other);
	// D'tor:
	~VisitationRecord();
};

#endif