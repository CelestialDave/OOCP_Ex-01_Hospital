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
	char* nurseName,*whichDep,*specialty,*docName, *depName;
	printTheOptionsForTheUser();
	cin >> num;
	while (num <= 10)
	{
		switch (num)
		{
		case 1:  //add a department to the hospital

			depName = inputDepName();   //department name
			hospital->addDepartment(new Department(depName)); //add to the departments array
			delete[] depName;
			break;

		case 2:   //add a nurse
			nurseName = inputNurseName(); //nurse name
			yearsExprience = inputYearsOfExprience(); //years of exprience
			whichDep = inputWhichDep(); //the departments she belongs
			indexOfcurrDepInArr = hospital->findTheIndexOfDepNameInDepArr(whichDep);
			//find the place of the department the nurse belongs in the departments array
			if (indexOfcurrDepInArr != -1) //if the department exist
			{
				Nurse* nurse = new Nurse(nurseName, yearsExprience);
				hospital->addNurse(nurse); //add the nurse to the array of nurses in the hospital
				hospital->addNurseToSpecificDepartment(*nurse, indexOfcurrDepInArr);
				//add the nurse to specific department
			}
			else 
				cout<<"Error, This department doesn't exist"<<endl;
			delete[]nurseName;
			delete[]whichDep;
			break;
		case 3:
			docName = inputDocName(); //doctor name
			specialty = inputWhichDep();  //the speciality of the doctor(name of exist department)
			indexOfdepAccordingToSpecialtyInDepArr= hospital->findTheIndexOfDepNameInDepArr(specialty);
			if (indexOfdepAccordingToSpecialtyInDepArr == -1)
				cout << "Error, There in no department like doctor's specialy" << endl;
			else
			{
				Doctor*doctor = new Doctor(docName, specialty);  
				hospital->addDoctor(doctor);   //add doctor to the hospital
				hospital->addDoctorToSpecificDepartment(*doctor, indexOfdepAccordingToSpecialtyInDepArr);
				//add doctor to specific department
			}
			delete[]docName;
			delete[]specialty;
			break;


		}
		printTheOptionsForTheUser();
		cin >> num;
	}
	hospital->showStaffMembers();
}


char* Ui::inputDocName()
{
	char temp[MAX_NAME];
	cout << "please enter the name of the doctor" << endl;
	cin >> temp;
	char* docName = new char[strlen(temp) + 1];
	strcpy(docName, temp);
	return docName;
}

char*  Ui::inputWhichDep()
{
	char temp[MAX_NAME];
	cout << "which department do you belong? " << endl;
	cin >> temp;
	char* depName = new char[strlen(temp) + 1];
	strcpy(depName, temp);
	return depName;
}


int Ui::inputYearsOfExprience()const
{
	int yearsExp;
	cout << "how many years of exprience she has?" << endl;
	cin >> yearsExp;
	return yearsExp;
}
char* Ui::inputNurseName()
{
	char temp[MAX_NAME];
	cout << "please enter the name of the nurse" << endl;
	cin >> temp;
	char* nurseName = new char[strlen(temp) + 1];
	strcpy(nurseName, temp);
	return nurseName;

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


char* Ui::inputDepName()
{
	char tempName[MAX_NAME];
	cout << "please enter the name of the department" << endl;
	cin >> tempName;
	char *depName = new char[strlen(tempName) + 1];
	strcpy(depName, tempName);
	return depName;
}

