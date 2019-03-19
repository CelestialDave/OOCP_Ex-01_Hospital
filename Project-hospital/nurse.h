#ifndef Nurse__H
#define Nurse__H

class Nurse
{
private:
	char*name;
	int employeeIDNumber;
	int yearsOfExperience;

public:
	Nurse(char* name, int IDNum, int yearExp);
	Nurse(const Nurse&) = delete;
	~Nurse();
};
#endif 