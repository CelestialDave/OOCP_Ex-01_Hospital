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
	void allocDepartmentsArr();
	void allocPatientsArr();
	void allocDocArr();
	void allocNursesArr();

	bool addDepartment(Department& inDep);
	bool addResearcher(Researcher& inResearcher);
	bool addDoctor(Doctor& inDoc);
	bool addNurse(Nurse& inNurse);

	bool addNurseToSpecificDepartment(Nurse & nurse, int indexToIn);
	bool addDoctorToSpecificDepartment(Doctor & doctor, int indexToIn);

	bool getDepartmentByName(char* depName, Department* resDepartment);
	Department* getDepartmentByIndex(int ind);
	bool validationEmployeeId(const int& employeeID);
	bool veryfactionDoctorEmployeeIdBinSearch(Doctor**arr,int size, const int& employeeID);
	bool veryfactionNurseEmployeeIdBinSearch(Nurse**arr, int size, const int& employeeID);


	//
	const char * getDepartmentNameByIndex(int ind);
	//
	int getNumOfDepartments();
	bool binDepartmentByName(Department** arr, int size, char* depName, Department* resDep);

	void addPatient(Patient& inPatient);
	Patient* getPatientByID(char* inID, bool* isFound);
	//bool binSearchPatientByID(Patient** arr, int size,const char* id, Patient* resPat);
	int binSearchPatientByID(char* inID);
	//Patient* binSearchPatientByID(Patient** arr, int size, const char* id, bool* isFound);
	int getIndexForPatientInsertion(const char* id);
	void insertPatientToArrInIndex(Patient& newPatient, int index);
	void pushPatientsFwdFromIndex(int index);

	Researcher* findResearcherAccordingToName(const char*name,bool&exist);
	bool addArticleToResearcher(Article & art, Researcher*researcher);

	//void showPatient() const;
	void showPatientInSpecificDep(const int & index) const;
	void showStaffMembers() const;
	void showResearchers() const;
	//void showPatientByID(char* inID) const;
	void showDepartments() const;

	int findTheIndexOfDepNameInDepArr(char*str) const;
};

#endif