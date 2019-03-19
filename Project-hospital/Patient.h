#ifndef PATIENT_H
#define PATIENT_H
#include "Visitation_Record.h"
#include "Date.h"

enum eGender {Male, Female};

// Move to show function: const char* gender[] = {"Male", "Female"};

class Patient
{

private:
	char* name;
	eGender gender;
	char* ID;
	Date dateOfBirth;
	VisitationRecord* visits;
	int numVisits;
	char** departmentsVisited;
	int numOfDepartments;

public:
	// C'tor:
	//Patient(const char* inName, eGender inGender, Date inDateOBirth);
	Patient(const char* inName, eGender inGender, Date inDateOBirth);
	// Copy C'tor:
	Patient(const Patient& other) = delete;
	// D'tor:
	~Patient();

	// Methods:
	addVistation(VisitationRecord& newVisit);

};

#endif
