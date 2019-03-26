#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "Department.h"
#include "Patient.h"
#include "Research_institute.h"
#include "ConstantsAndGenFuncs.h"

class Hospital
{
private:
	Department** allDepartments;
	int logSizeOfDepartments;
	int phySizeOfDepartments;
	Doctor** allDoctors;
	int logSizeDoctors;
	int phySizeDoctors;
	Nurse** allNurses;
	int logSizeNurses;
	int phySizeNurses;
	Patient** allPatients;
	int logSizeOfPatients;
	int phySizeOfPatients;
	ResearchInstitute researchInst;


public:
	// C'tor:
	Hospital();
	// Copy C'tor:
	Hospital(const Hospital& other) = delete;
	~Hospital();

	// Methods:
	// Allocation of memory to Array:
	bool allocDepartmentsArr();
	bool allocPatientsArr();
	bool allocDocArr();
	bool allocNursesArr();

	bool addDepartment(Department& inDep);
	bool addResearcher(Researcher& inResearcher);
	bool addDoctor(Doctor& inDoc);
	bool addNurse(Nurse& inNurse);

	bool addNurseToSpecificDepartment(Nurse & nurse, int indexToIn);
	bool addDoctorToSpecificDepartment(Doctor & doctor, int indexToIn);

	bool addPatient(Patient& inPatient, const char* inDep);

	void showStaffMembers() const;
	void showResearchers() const;
	void showPatientByID(char* inID) const;

	int findTheIndexOfDepNameInDepArr(char*str) const;
};

#endif