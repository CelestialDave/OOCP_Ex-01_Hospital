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
	
	vector<VisitationRecord*> visits;
	vector<Department*> departmentsVisited;


public:
	// C'tor:
	Patient(const string inName,const string id, enum eGender inGender, string inYearOBirth) throw(StringException);
	// Copy C'tor:
	Patient(const Patient& other) = delete;
	// D'tor:
	~Patient();

	// Methods:
	void addVisitiaionRecord(VisitationRecord* inVisitiaionRecord);
	int getIndexForVisitiationInsertion(Date & date); //the index to insert Visitiation record
	void insertVisitToArrInIndex(VisitationRecord* visitationRecord, int index);
	void allocVisitsArr();

	void allocDepartmentsVisitedArr();
	void addDepatrtmentToPatient(Department& department);
	const string getName()const;
	int getSizeVisits() const;
	VisitationRecord* getVisitByIndex(int index) const;
	const string getId()const;
	void showGender() const;
	const string getYearOfBirth() const;
	void showVisits() const;


	bool hasVisitedDepartment(Department& department) const;
};

#endif
