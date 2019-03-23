#include "Department.h"
#include "Hospital.h"

class Ui
{
private:
	Hospital *hospital;
public:
	Ui(Hospital *hos);
	void start();
	void printTheOptionsForTheUser() const;
	char* inputDepName();
	char* inputNurseName();
	int inputYearsOfExprience() const;
	char*  inputWhichDep();




};