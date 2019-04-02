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
	int inputYearsOfExprience() const;
	bool checkIfItFirstTimeInHospital() const;
	enum eGender inputGender();
	char* getString(const char* prompt);
	Patient* createPatient();
	bool createDoctor(Doctor* doctor, int& indexInDepArr);
	int getInt(const char* str);
	bool createNurse(Nurse*nurse, int& indexOfTheRightInDepArr);
	Article* createArticle();


};