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

	Patient** patientsArr;
	int logSizeOfPatients;
	int phySizeOfPatients;


public:
	// C'tor:
	Department(const char* inName);
	// Copy C'tor:
	Department(const Department& other) = delete;
	// D'tor:
	~Department();

	// Allocation of memory to Array:
	void allocPatientsArr();
	void allocStaffArr();

	// Add staff member to list of Staff Members:
	void addStaffMember(StaffMember* staffMember);
	StaffMember** operator+=(StaffMember* staffMember);

	// Add patient to the department list of patients:
	void addPatient(Patient& patient);

	// Geters:
	const char* getName() const; 
	int getNumOfSurgeons() const;
	
	// Show Methods:
	void showPatients() const;
};

#endif