#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "Department.h"
#include "Patient.h"
#include "Research_institute.h"
#include "Constants.h"

class Hospital
{
private:
	char* name;
	Department* departments;
	int logSizeOfDepartments;
	int phySizeOfDepartments;
	Doctor*doctors;
	int logSizeDoctors;
	int phySizeDoctors;
	Nurse*nurses;
	int logSizeNurses;
	int phySizeNurses;
	Patient** patientList;
	int logSizeOfPatients;
	int phySizeOfpatient;

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