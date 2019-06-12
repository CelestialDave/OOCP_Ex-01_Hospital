#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "ConstantsAndGenFuncs.h"
#include "StaffMember.h"
#include "doctor.h"
#include "nurse.h"
#include "Patient.h"

class Department
{
private:
	string name;
	vector<StaffMember*> staffArr;
	//StaffMember** staffArr;
	////int logSizeOfStaff;
	////int phySizeOfStaff;
	int numOfSurgeons;

	vector<Patient*> patientsArr;
	////Patient** patientsArr;
	////int logSizeOfPatients;
	////int phySizeOfPatients;


public:
	// C'tor:
	Department(const string inName) throw(HospitalException);
	Department(ifstream& in);

	// Copy C'tor:
	Department(const Department& other) = delete;
	// D'tor:
	~Department(); 
	

	// Allocation of memory to Array:
	void allocPatientsArr();
	void allocStaffArr();

	// Add staff member to list of Staff Members:
	void addStaffMember(StaffMember* staffMember);
	vector<StaffMember*> operator+=(StaffMember* staffMember);

	int getSizeOfStaffArr() const;

	StaffMember* getStaffMemberByIndex(int index)const ;
	// Add patient to the department list of patients:
	void addPatient(Patient& patient);

	// Geters:
	const string getName() const; 
	int getNumOfSurgeons() const;
	
	// Show Methods:
	void showPatients() const;
	friend ostream& operator<<(ostream& os,Department& dep);
	friend ifstream& operator >> (ifstream& in, Department& dep);

};

#endif