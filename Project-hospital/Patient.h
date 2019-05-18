#ifndef PATIENT_H
#define PATIENT_H
#include "Visitation_Record.h"
#include "Visit_Surgery.h"
#include "ConstantsAndGenFuncs.h"

class Department;

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
	const Department** departmentsVisited;
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
	void addVisitiaionRecord(VisitationRecord* inVisitiaionRecord);
	int getIndexForVisitiationInsertion(Date & date); //the index to insert Visitiation record
	void insertVisitToArrInIndex(VisitationRecord* visitationRecord, int index);
	void pushVisitsFwdFromIndex(int index);
	void allocVisitsArr();

	void allocDepartmentsVisitedArr();
	void addDepatrtmentToPatient(const Department& pDepartment);
	const char* getName()const;
	int getSizeVisits() const;
	VisitationRecord* getVisitByIndex(int index) const;
	const char* getId()const;
	void showGender() const;
	const char * getYearOfBirth() const;
	void showVisits() const;


	bool hasVisitedDepartment(Department& pDepartment) const;
};

#endif
