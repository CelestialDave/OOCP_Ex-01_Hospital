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
	bool checkIfItFirstTimeInHospital() const throw(HospitalException);
	enum eGender inputGender()throw(HospitalException);
	string getString(const string prompt);
	Patient* createPatient(string id);
	Doctor* createDoctor();
	int getInt(const string str);
	Nurse* createNurse() throw(HospitalException);
	Article* createArticle(Date*date) throw(HospitalException);
	void printSpaceLine() const;
	void printVisitationPorpuse(Patient* patient) const;
	VisitationRecord* createVisit(Patient & patient, Date* arrivalDate,int choice) throw(HospitalException);
	void compare2Researchers() const throw(HospitalException);

	// UI Flows:
	void addNewDepartment() throw(HospitalException);
	void addNewNurse() throw(HospitalException);
	void  addNewDoctor() throw (HospitalException);
	void addNewVisitation() throw (HospitalException); //throw(DepartmentsEmptyException, PatientException, FormatException, StringException,SurgeonException, DateException);
	void addNewResearcher();
	void addArticleToResearcher() throw(ResearchersEmptyException);
	void showPatientsInDepartment() throw(HospitalException);
	void searchPatientByID() throw(PatientNotFoundException);
	bool toContinuePrompt();
	
	//// UI Warnings:
	////void warnings(Results result);
};