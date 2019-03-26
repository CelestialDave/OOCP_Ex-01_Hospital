#include "Ui.h"
#include "ConstantsAndGenFuncs.h"
#include "Hospital.h"


Ui::Ui(Hospital *hos)
{
	hospital = hos;
}

void Ui::start()
{
	int num, yearsExprience, indexOfcurrDepInArr, indexOfdepAccordingToSpecialtyInDepArr;
	char* name, *whichDep, *specialty, *id,*YearOfBirth;
	bool firstTime;
	enum eGender gender;
	printTheOptionsForTheUser();
	cin >> num;
	while (num <= 10)
	{
		switch (num)
		{
		case 1:  //add a department to the hospital
		{
			char* name = getString("Please enter your name");
			Department* department = new Department(name);
			hospital->addDepartment(*department); //add to the departments array
			delete[] name;
			break;
		}
		case 2:   //add a nurse
		{
			//name = inputName(); //nurse name
			char*name = getString("Please enter the name of nurse");
			int yearsExprience = inputYearsOfExprience(); //years of exprience
			char*whichDep = getString("which department she belongs? "); //the departments she belongs
			int indexOfcurrDepInArr = hospital->findTheIndexOfDepNameInDepArr(whichDep);
			//find the place of the department the nurse belongs in the departments array
			if (indexOfcurrDepInArr != -1) //if the department exist
			{
				Nurse* nurse = new Nurse(name, yearsExprience);
				hospital->addNurse(nurse); //add the nurse to the array of nurses in the hospital
				hospital->addNurseToSpecificDepartment(*nurse, indexOfcurrDepInArr);
				//add the nurse to specific department
			}
			else
				cout << "Error, This department doesn't exist" << endl;
			delete[]name;
			delete[]whichDep;
			break;
		}
		case 3: //add doctor to the hospital
		{
			char* name = getString("Please enter the name of doctor");
			int employeeID=getInt("choose your employeeID number")
			//specialty = inputWhichDep();  //the speciality of the doctor(name of exist department)
			char* specialty = getString("Please enter the specialty of the doctor(name of department");
			int indexOfdepAccordingToSpecialtyInDepArr = hospital->findTheIndexOfDepNameInDepArr(specialty);
			if (indexOfdepAccordingToSpecialtyInDepArr == -1)
				cout << "Error, There in no department like doctor's specialy" << endl;
			else
			{
				Doctor*doctor =new Doctor(name, ,specialty);
				hospital->addDoctor(*doctor);   //add doctor to the hospital
				hospital->addDoctorToSpecificDepartment(*doctor, indexOfdepAccordingToSpecialtyInDepArr);
				//add doctor to specific department
			}
			delete[]name;
			delete[]specialty;
			break;
		}
		case 4:
		{

			bool firstTime = checkIfItFirstTimeInHospital();
			if (firstTime) //this is the first visit in the hospital
			{
				Patient* patient = createPatient();
			}
			else //it is not the first visit
			{

			}

		}


		}
		printTheOptionsForTheUser();
		cin >> num;
	}
	hospital->showStaffMembers();
}
int Ui::getID(const char* str)
{
	int res;
	cout<<
}
Doctor* Ui::createDoctor()
{
	char*name= getString("Please enter your name");

}

Patient* Ui::createPatient()
{
	char*name = getString("Please enter your name: ");
}
char* Ui::getString(const char* prompt)
{
	char temp[MAX_NAME];
	cout << prompt << endl;
	cin.getline(temp,
	//cin.getline  /****************/
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




