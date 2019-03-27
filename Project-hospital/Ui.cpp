#include "Ui.h"
#include "ConstantsAndGenFuncs.h"
#include "Hospital.h"


Ui::Ui(Hospital *hos)
{
	hospital = hos;
}

void Ui::start()
{
	printTheOptionsForTheUser();
	int num;
	cin >> num;
	while (num <= 10)
	{
		switch (num)
		{
		case 1:  //add a department to the hospital
		{
			char* name = getString("Please enter the name of department you want to create");
			Department* department = new Department(name);
			hospital->addDepartment(*department); //add to the departments array
			delete[] name;
			break;
		}
		case 2:   //add a nurse
		{
			bool ok;
			int indexOfTheRightInDepArr;
			Nurse* nurse=createNurse(ok, indexOfTheRightInDepArr);
			if(ok)
			{
			hospital->addNurse(*nurse); //add the nurse to the array of nurses in the hospital
			hospital->addNurseToSpecificDepartment(*nurse, indexOfTheRightInDepArr);
				//add the nurse to specific department
			}
			else
				cout << "Error, This department doesn't exist" << endl;
			break;
		}
		case 3: //add doctor to the hospital
		{
			bool ok;
			int indexInDepArr;
			Doctor*doctor =createDoctor(ok,indexInDepArr);
			if (ok) // if we really create new doctor
			{
				hospital->addDoctor(*doctor);   //add doctor to the hospital
				hospital->addDoctorToSpecificDepartment(*doctor, indexInDepArr);
				//add doctor to specific department
			}		
			break;
		}
		case 4:	// Add Visitation
		{
			Patient* patient = nullptr;
			Department* department = nullptr;
			char* inID = getString("Please provide the Patient's ID number: ");
			bool isFirstTime = checkIfItFirstTimeInHospital();
			bool isExists = hospital->getPatientByID(inID, patient);

			if (isFirstTime) //this is the first visit in the hospital
			{
				if (isExists) // Shouldn't exist
				{ 
					cout << "Error: A Patient with the given ID number already in the system." << endl;
					delete[] inID;
					break;
				}
				else {
					patient = createPatient();
				}
			}
			else //it is not the first visit
			{
				if (!isExists) // Should exist
				{
					cout << "Error: A Patient with the given ID number is not available." << endl;
					delete[] inID;
					break;
				}
			}

			char* inDepartment = getString("Please enter the Department for the patient: ");
			if (!patient->hasVisitedDepartment(inDepartment)) // Patient hasn't visited in this department
			{
				
			}
		}


		}
		printTheOptionsForTheUser();
		cin >> num;
	}
	hospital->showStaffMembers();
}

Nurse* Ui::createNurse(bool& ok,int& indexOfTheRightInDepArr)
{
	char*name = getString("Please enter the name of nurse");
	int employeeID = getInt("choose your employeeID number");
	int yearsExprience = getInt("How many years of exprience the nurse has?");
	char*whichDep = getString("which department she belongs?");
	indexOfTheRightInDepArr = hospital->findTheIndexOfDepNameInDepArr(whichDep);
	if (indexOfTheRightInDepArr == -1)
	{
		ok = false;
		delete[]name;
		delete[]whichDep;
		return NULL;
	}
	else
	{
		ok = true;
		Nurse* nurse = new Nurse(name, employeeID, yearsExprience);
		delete[]name;
		delete[]whichDep;
		return nurse;
	}

}
int Ui::getInt(const char* str)
{
	int num;
	cout << str << endl;
	cin >> num;
	cin.ignore(5, '\n');
	return num;

}
Doctor* Ui::createDoctor(bool& ok,int& indexInDepArr)
{
	char* name = getString("Please enter the name of doctor");
	int employeeID = getInt("choose your employeeID number");
	char* specialty = getString("Please enter the specialty of the doctor(name of department");
	indexInDepArr = hospital->findTheIndexOfDepNameInDepArr(specialty);
	if (indexInDepArr == -1)
	{
		cout << "Error, There in no department like doctor's specialy" << endl;
		ok = false;
		delete[]name;
		delete[]specialty;
		return NULL;
	}
	else
	{
		ok = true;
		Doctor* doctor = new Doctor(name, employeeID, specialty);
		delete[]name;
		delete[]specialty;
		return doctor;
	}
Patient* Ui::createPatient()
{
	const char* name = getString("Please enter the Patient's name: ");
	eGender gen = inputGender();
	const char* id = getString("Please enter the Patient's ID number: ");
	char* yearOfBirth = getString("Please enter the Patient's year of birth: ");
	return (new Patient(name, id, gen, yearOfBirth));
}

char* Ui::getString(const char* prompt)
{
	char temp[MAX_NAME];
	cout << prompt << endl;
	cin.clear();
	cin.ignore(5, '\n');
	cin.getline(temp, MAX_NAME);
 	char* str = new char[strlen(temp) + 1];
	strcpy(str, temp);
	return str;
}

enum eGender Ui::inputGender()
{
	int gen;
	enum eGender gender;
	cout << "please enter your male: male-press 1, female-press 0" << endl;
	cin >> gen;
	gender = (eGender)gen;
	return gender;
}


bool Ui::checkIfItFirstTimeInHospital() const
{
	bool res;
	cout << "Is this your first visit in the hospital?  yes-press 1,no-press 0" << endl;
	cin >> res;
	return res;
}




int Ui::inputYearsOfExprience()const
{
	int yearsExp;
	cout << "how many years of exprience she has?" << endl;
	cin >> yearsExp;
	return yearsExp;
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




