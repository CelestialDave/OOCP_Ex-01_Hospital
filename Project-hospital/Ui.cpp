#include "Ui.h"
#include "ConstantsAndGenFuncs.h"
#include "Hospital.h"


Ui::Ui(Hospital *hos)
{
	hospital = hos;
}
void Ui::start()
{
	int num;
	printTheOptionsForTheUser();
	cin >> num;
	while (num <= 10)
	{
		switch (num)
		{
		case 1:
			char*depName = inputDepName();
			Department dep(depName);
			hospital->addDepartment(dep);

		}
	}
}
}

void Ui::printTheOptionsForTheUser() const
{
	cout << "If you want to add a department to the hospital, press 1" << endl;
	cout << "If you want to add a nurse to the hospital, press 2" << endl;
	cout << "If you want to add a doctor to the hospital, press 3" << endl;
	cout << "If you want to get hospital treatment, press 4" << endl;
	cout << "If you want to add a researcher to the research institute, press 5" << endl;
	cout << "If you want to add an article to researcher, press 6" << endl;
	cout << "If you want to see all patients belonging to a particular department, press 7" << endl;
	cout << "If you want to see all the medical staff at the hospital, press 8" << endl;
	cout << "If you want to see all the researchers at the Research Institute, press 9" << endl;
	cout << "If you want to search for a patient by ID, press 10" << endl;
	cout << "If you are finished, press 11" << endl;
}

void Ui::addDep(Hospital& hospital)
{
	char* depName;
	cout << "please enter the name of the department" << endl;
	cin >> depName;
	Department dep(depName);
	hospital.addDepartment(dep);
	
}
char* Ui::inputDepName()
{
	char* depName;
	cout << "please enter the name of the department" << endl;
	cin >> depName;
	return depName;
}

