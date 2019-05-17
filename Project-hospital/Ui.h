#include "Department.h"
#include "Hospital.h"
#include "Patient.h"

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
	enum eGender inputGender();
	char* getString(const char* prompt);
	Patient* createPatient(char* id);
	Doctor* createDoctor();
	int getInt(const char* str);
	Nurse* createNurse();
	Article* createArticle(Date*date);
	void printSpaceLine() const;
	void printVisitationPorpuse(Patient* patient) const;
	VisitationRecord* createVisit(Patient & patient, Date* arrivalDate,int choice,bool& ok);
	void compare2Researchers() const;

	// UI Flows:
	Results addNewDepartment();
	Results addNewNurse();
	Results addNewDoctor();
	Results addNewVisitation();
	void addNewResearcher();
	Results addArticleToResearcher();
	Results showPatientsInDepartment();

	// UI Warnings:
	void warnings(Results result);
};