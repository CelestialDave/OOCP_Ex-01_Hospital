#ifndef PATIENT_H
#define PATIENT_H
#include "Visitation_Record.h"
#include "Date.h"
#include "ConstantsAndGenFuncs.h"


class Patient
{
private:
	char* name;
	eGender gender;
	char* ID;
	char*  yearOfBirth;
	VisitationRecord** visits;
	int logSizeOfVisits;
	int phySizeOfVisits;
	char** departmentsVisited;
	int logsizeOfDepartments;
	int phySizeOfDepartments;


public:
	// C'tor:
	Patient(const char* inName,const char*id, enum eGender inGender, char* inYearOBirth);
	// Copy C'tor:
	Patient(const Patient& other) = delete;
	// D'tor:
	~Patient();

	// Methods:
	bool addVistation(VisitationRecord& newVisit);
	void reallocationVisitationRecordArr();
	void reallocationDepartmentsVisitedNameArr();
	bool addDepatrtmentToDepList(const char* DepartmentName);
	char* getName()const;
	char* getId()const;
	void showGender() const;
	char * getYearOfBirth() const;
	void showVisits() const;
};

#endif
