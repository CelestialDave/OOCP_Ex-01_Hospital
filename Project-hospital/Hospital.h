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
	
	StaffMember** staffArr;
	int logSizeOfStaff;
	int phySizeOfStaff;
	/*Doctor** allDoctors;
	int logSizeDoctors;
	int phySizeDoctors;
	Nurse** allNurses;
	int logSizeNurses;
	int phySizeNurses;*/
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
	/*void allocDocArr();
	void allocNursesArr();*/

	void addResearcher(Researcher* inResearcher);
	
	void addStaffMemberToDepartment(StaffMember* staffMember, int indexToIn);
	/*void addNurseToSpecificDepartment(Nurse & nurse, int indexToIn);
	void addDoctorToSpecificDepartment(Doctor & doctor, int indexToIn);*/

	bool getDepartmentByName(char* depName, Department* resDepartment);
	Department* getDepartmentByIndex(int ind);
	bool verifyEmployeeIDNumber(const int& employeeID);
	bool verifyStaffMemberEmployeeIDBinSearch(StaffMember** arr, int size, const int& employeeID);
	/*bool veryfactionDoctorEmployeeIdBinSearch(Doctor**arr,int size, const int& employeeID);
	bool veryfactionNurseEmployeeIdBinSearch(Nurse**arr, int size, const int& employeeID);*/
	bool isDepartmentsEmpty() const;

	const char * getDepartmentNameByIndex(int ind);
	int getNumOfDepartments();
	bool binDepartmentByName(Department** arr, int size, char* depName, Department* resDep);

	void addDepartment(Department& inDepartment);
	int binSearchDepartmentByName(const char*name);
	int getIndexForDepartmentInsertion(const char*name);
	void pushDepartmentsFwdFromIndex(int index);
	void insertDepartmentToArrInIndex(Department& newDepartment, int index);

	void addStaffMember(StaffMember* inStaffMember);
	void inserStaffMemberToArrInIndex(StaffMember* newStaffMember, int index);
	void pushStaffMembersFwdFromIndex(int index);
	int getIndexForStaffMemberInsertion(int id);
	int binSearchStaffMemberByID(int inID);

	/*void insertNurseToArrInIndex(Nurse& newNurse, int index);
	void pushNursesFwdFromIndex(int index); 
	int getIndexForNurseInsertion(int id);
	int binSearchNurseByID(int inID);
	void addNurse(Nurse& inNurse);

	void addDoctor(Doctor& inDoctor);
	int binSearchDoctorByID(int inID);
	int getIndexForDoctorInsertion(int id);
	void insertDoctorToArrInIndex(Doctor& newDoctor, int index);
	void pushDoctorsFwdFromIndex(int index);*/

	void addPatient(Patient& inPatient);
	Patient* getPatientByID(char* inID, bool* isFound);
	int binSearchPatientByID(char* inID);
	int getIndexForPatientInsertion(const char* id);
	void insertPatientToArrInIndex(Patient& newPatient, int index);
	void pushPatientsFwdFromIndex(int index);

	Researcher* getResearcherByIndex(int index) const;
	Researcher* findResearcherAccordingToName(const char*name,bool&exist);
	void addArticleToResearcher(Article & art, Researcher*researcher);
	const int getSizeOfResearchers() const;

	void showPatientInSpecificDep(const int & index) const;
	void showMedicalStaffMembers() const;
	void showResearchers() const;
	void showDepartments() const;

	int findTheIndexOfDepNameInDepArr(char*str) const;
};

#endif