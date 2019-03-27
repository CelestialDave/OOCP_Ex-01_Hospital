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
	void printTheOptionsForTheUser() const;
	//void displayDepartmentsList() const;
	int inputYearsOfExprience() const;
	bool checkIfItFirstTimeInHospital() const;
	enum eGender inputGender();
	char* getString(const char* prompt);
	Patient* createPatient();
	Doctor* createDoctor(bool& ok, int& indexInDepArr);
	int getInt(const char* str);
	Nurse*createNurse(bool& ok, int& indexOfTheRightInDepArr);
};