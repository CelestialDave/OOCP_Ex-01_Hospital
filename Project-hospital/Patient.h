#ifndef PATIENT_H
#define PATIENT_H
#include "Visitation_Record.h"
#include "Visit_Surgery.h"
#include "ConstantsAndGenFuncs.h"

class Department;

class Patient
{
private:
	string name;
	eGender gender;
	string ID;
	string  yearOfBirth;
	VisitationRecord** visits;
	int logSizeOfVisits;
	int phySizeOfVisits;
	const Department** departmentsVisited;
	int logsizeOfDepartments;
	int phySizeOfDepartments;


public:
	// C'tor:
	Patient(const string inName,const string id, enum eGender inGender, string inYearOBirth) throw(NameException);
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
	const string getName()const;
	int getSizeVisits() const;
	VisitationRecord* getVisitByIndex(int index) const;
	const string getId()const;
	void showGender() const;
	const string getYearOfBirth() const;
	void showVisits() const;


	bool hasVisitedDepartment(Department& pDepartment) const;
};

#endif
