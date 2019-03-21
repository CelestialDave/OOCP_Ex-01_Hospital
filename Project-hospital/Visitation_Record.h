#ifndef VISITATION_H
#define VISITATION_H
#include "Date.h"
#include "ConstantsAndGenFuncs.h"

enum eGender { Male, Female, N_A };

class VisitationRecord
{
private:
	char* name;
	char* id;
	eGender gender;
	Date dateOfBirth;
	char* staffMemInChargeName;
	Date arrivalDate;
	char* visitationPurpose;

public:
	// C'tor:
	VisitationRecord(const char* inStaffMemInChargeName, const Date inArrivalDate, const char* inVisitPurpose);
	// Copy C'tor:
	VisitationRecord(const VisitationRecord& other);
	// D'tor:
	~VisitationRecord();

	char* getstaffMemInChargeName() const;
	void showDate() const;
	void  printVisitationPurpose() const;
};

#endif