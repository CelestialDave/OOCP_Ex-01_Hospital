#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "Department.h"
#include "Patient.h"
#include "Research_institute.h"

class Hospital
{
private:
	char* name;
	Patient** patientList;
	int numOfPatients;
	Department* departments;
	int numOfDepartments;
	ResearchInstitute researchInst;


public:
	// C'tor:
	Hospital(const char* inName);
	// Copy C'tor:
	Hospital(const Hospital& other) = delete;
	~Hospital();

	// Methods:
	bool addDepartment(Department& inDep);
	bool addDoctor(Doctor& inDoc);
	bool addNurse(Nurse& inNurse);
	bool addResearcher(Researcher& inResearcher);
	bool addPatient(Patient& inPatient);
	
	void showStaffMembers() const;
	void showResearchers() const;

	void showPatientByID(char* inID) const;
};

#endif