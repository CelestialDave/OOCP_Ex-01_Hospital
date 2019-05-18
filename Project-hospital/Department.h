#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "ConstantsAndGenFuncs.h"
#include "doctor.h"
#include "nurse.h"
#include "Patient.h"
#include "StaffMember.h"

class Department
{
private:
	char* name;
	StaffMember** staffArr;
	int logSizeOfStaff;
	int phySizeOfStaff;
	int numOfSurgeons;

	/*Doctor** docsArr;
	int logSizeOfDocs;
	int phySizeOfDocs;
	Nurse** nursesArr;
	int logSizeOfNurses;
	int phySizeOfNurses;*/

	Patient** patientsArr;
	int logSizeOfPatients;
	int phySizeOfPatients;


public:
	// Default C'tor:
	//Department() = default;
	// C'tor:
	Department(const char* inName);
	// Department(const char* inName, Doctor** inDocArr, Nurse** inNurseArr, Patient** inPatientArr);
	// Copy C'tor:
	Department(const Department& other) = delete;
	// D'tor:
	~Department();

	// -- Methods --
	void showPatients() const;

	// Allocation of memory to Array:
	void allocPatientsArr();
	void allocStaffArr();
	/*void allocDocArr();
	void allocNursesArr();*/

	// Add doctor to the list of doctors:
	// Add staff memver to list of Staff Members:
	void addStaffMember(StaffMember* staffMember);
	//void addDoctor(Doctor& doc);
	//// Add nurse to the list of nurses:
	//void addNurse(Nurse& nurse);
	// Add patient to the department list of patients:
	void addPatient(Patient& patient);
	StaffMember** operator+=(StaffMember* staffMember);
	const char* getName() const; 
	int getNumOfSurgeons() const;
	
};

#endif