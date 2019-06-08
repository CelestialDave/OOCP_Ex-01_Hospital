#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <typeinfo.h>
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
	
	StaffMember** staffArr;
	int logSizeOfStaff;
	int phySizeOfStaff;
	int numOfSurgeons;
	
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
	void allocDepartmentsArr();
	void allocPatientsArr();
	void allocStaffArr();

	void addResearcher(Researcher* inResearcher);
	
	void addStaffMemberToDepartment(StaffMember* staffMember, int indexToIn);

	Department* getDepartmentByIndex(int ind);
	bool verifyEmployeeIDNumber(const int& employeeID);
	bool verifyStaffMemberEmployeeIDBinSearch(StaffMember** arr, int size, const int& employeeID);

	bool isDepartmentsEmpty() const;

	int getNumOfDepartments();
	int getNumOfSurgeons();

	void addDepartment(Department& inDepartment);
	int binSearchDepartmentByName(const string name) throw(StringException);
	int getIndexForDepartmentInsertion(const string name);
	void pushDepartmentsFwdFromIndex(int index);
	void insertDepartmentToArrInIndex(Department& newDepartment, int index);

	void addStaffMember(StaffMember* inStaffMember);
	void inserStaffMemberToArrInIndex(StaffMember* newStaffMember, int index);
	void pushStaffMembersFwdFromIndex(int index);
	int getIndexForStaffMemberInsertion(int id);
	int binSearchStaffMemberByID(int inID);

	void addPatient(Patient& inPatient);
	Patient* getPatientByID(string inID, bool* isFound);
	int binSearchPatientByID(string inID);
	int getIndexForPatientInsertion(const string id);
	void insertPatientToArrInIndex(Patient& newPatient, int index);
	void pushPatientsFwdFromIndex(int index);

	StaffMember* getStaffMemberByIndex(int index) const;
	Researcher* getResearcherByIndex(int index) const;
	Researcher* findResearcherAccordingToName(const string name,bool&exist);
	void addArticleToResearcher(Article & art, Researcher*researcher);
	const int getSizeOfResearchers() const;


	void showPatientInSpecificDep(const int & index) const;
	Results showMedicalStaffMembers() const;
	void showResearchers() const;
	void showResearchersName() const;
	Results showSurgeons() const;
	void showDoctorResearchers() const;
	void showDepartments() const;


	int findTheIndexOfDepNameInDepArr(string str) const;
};

#endif