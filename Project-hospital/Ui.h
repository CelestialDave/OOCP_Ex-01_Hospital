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
	VisitationRecord* createVisit(Patient & patient, Date* arrivalDate,int choice) throw(StringException,FormatException,SurgeonException);
	void compare2Researchers() const throw(HospitalException);

	// UI Flows:
	Results addNewDepartment();
	void addNewNurse() throw(HospitalException);
	Results addNewDoctor();
	void addNewVisitation() throw (HospitalException); //throw(DepartmentException, PatientException, FormatException, StringException,SurgeonException, DateException);
	void addNewResearcher();
	void addArticleToResearcher() throw(HospitalException);
	Results showPatientsInDepartment();

	// UI Warnings:
	void warnings(Results result);
};