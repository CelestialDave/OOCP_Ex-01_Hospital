#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "ConstantsAndGenFuncs.h"
#include "doctor.h"
#include "nurse.h"
#include "Patient.h"

class Department
{
private:
	char* name;
	Doctor** docArr;
	int logSizeOfDocs;
	int phySizeOfDocs;
	Nurse** nurseArr;
	int logSizeOfNurses;
	int phySizeOfNurses;
	Patient** patientsArr;
	int logSizeOfPatients;
	int phySizeOfPatients;


public:
	// C'tor:
	Department(const char* inName);
	// Department(const char* inName, Doctor** inDocArr, Nurse** inNurseArr, Patient** inPatientArr);
	// Copy C'tor:
	Department(const Department& other) = delete;
	// D'tor:
	~Department();

	// -- Methods --
	void showPatients() const;
	void showStaffMembers() const;

	// Allocation of memory to Array:
	bool allocPatientsArr();
	bool allocDocArr();
	bool allocNursesArr();

	// Add doctor to the list of doctors:
	bool addDoctor(Doctor& doc);
	// Add nurse to the list of nurses:
	bool addNurse(Nurse& nurse);
	// Add patient to the department list of patients:
	bool addPatient(Patient& patient);
};

#endif