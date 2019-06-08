#include "Department.h"
#include "Hospital.h"
#include "Patient.h"
#include <string>

class Ui
{
private:
	Hospital *hospital;
public:
	Ui(Hospital *hos);
	void start();
	void printMainMenu() const;
	int inputYearsOfExprience() const;
	bool checkIfItFirstTimeInHospital() const;
	enum eGender inputGender()throw(FormatException);
	string getString(const string prompt);
	Patient* createPatient(string id);
	Doctor* createDoctor();
	int getInt(const string str);
	Nurse* createNurse();
	Article* createArticle(Date*date) throw(StringException);
	void printSpaceLine() const;
	void printVisitationPorpuse(Patient* patient) const;
	VisitationRecord* createVisit(Patient & patient, Date* arrivalDate,int choice, Results& res) throw(StringException,FormatException);
	void compare2Researchers() const;

	// UI Flows:
	void addNewDepartment() throw(DepartmentExistException);
	Results addNewNurse();
	void addNewDoctor() throw(HospitalException);
	Results addNewVisitation() throw(DepartmentsEmptyException, PatientException, FormatException, StringException, DateException);
	void addNewResearcher();
	Results addArticleToResearcher() throw(ResearchersEmptyException);
	void showPatientsInDepartment() throw(HospitalException);

	// UI Warnings:
	void warnings(Results result);
};