#include "Department.h"

class Ui
{
private:
	Hospital *hospital;
public:
	Ui(Hospital *hos);
	void start();
	void printTheOptionsForTheUser() const;
	void addDep(Hospital& hospital);
	char*inputDepName();

};