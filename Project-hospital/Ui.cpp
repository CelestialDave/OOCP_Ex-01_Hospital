#include "Ui.h"
#include "ConstantsAndGenFuncs.h"
#include "Date.h"
#include "Hospital.h"
#include "Utils.h"


Ui::Ui(Hospital *hos)
{
	hospital = hos;
}

void Ui::start()
{
	printTheOptionsForTheUser();
	int choise;
	cin >> choise;
	//
	cin.ignore();
	while (choise != MAX_MENU_OPTIONS)
	{
		switch (choise)
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
			int employeeID = getInt("choose your employeeID number");
			bool existID = hospital->validationEmployeeId(employeeID);
			if (!existID)
			{
				int depNum;
				cout << "Please choose the Department number from the following list: " << endl;
				hospital->showDepartments();
				cin >> depNum;
				cin.ignore();
				int depInd = depNum - 1;
				bool exist = Utils::ifIndexInRange(depInd, hospital->getNumOfDepartments());
				if (exist)
				{
					Nurse*nurse = createNurse(employeeID);
					hospital->addNurse(*nurse);
					hospital->addNurseToSpecificDepartment(*nurse, depInd);
				}
				else
					cout << "Error, This department doesn't exist" << endl;
			}
			else
				cout << "Error,this employee ID number already exist" << endl;
					break;
		}
		case 3: //add doctor to the hospital
		{
			int employeeID = getInt("choose your employeeID number");
			bool existID = hospital->validationEmployeeId(employeeID);
			if (!existID)
			{ 
				int depNum;
				cout << "Please choose the Department number from the following list: " << endl;
				hospital->showDepartments();
				cin >> depNum;
				cin.ignore();
				int depInd = depNum - 1;
				bool exist = Utils::ifIndexInRange(depInd, hospital->getNumOfDepartments());
				if (exist)
				{
					Doctor*doctor=createDoctor(employeeID);
					hospital->addDoctor(*doctor);
					hospital->addDoctorToSpecificDepartment(*doctor,depInd);


				}
				else
					cout << "Error, This department doesn't exist" << endl;
			}
			else
				cout << "Error,this employee ID number already exist" << endl;
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
				if (isExists) // 1st time = Shouldn't exist
				{ 
					cout << "Error: A Patient with the given ID number already in the system." << endl;
					delete[] inID;
					break;
				}
				else {
					patient = createPatient(inID);
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

			int depNum;
			cout << "Please choose the Department number from the following list: " << endl;
			hospital->showDepartments();
			cin >> depNum;
			cin.ignore();
			int depInd = depNum - 1;
			bool exist = Utils::ifIndexInRange(depInd, hospital->getNumOfDepartments());
			if (!exist)
			{
				cout << "Error: The Department number chosen is invalid!" << endl;
				delete[] inID;
				if (!isExists)
					delete patient;
				break;
			}

			Department* inDep = nullptr;
			inDep = hospital->getDepartmentByIndex(depInd);

			char* inDate = getString("Please provide the Patient's arrival date [DD/MM/YYYY]): ");
			Date* arrivalDate = nullptr;
			bool isValidDateInput = Utils::convertStrDateToDateObj(inDate, &arrivalDate);
			if (!isValidDateInput)
			{
				cout << "Error: The input date is invalid!" << endl;
				delete[] inID;
				delete[] inDate;
				if (!isExists)
					delete patient;
				break;
			}

			char* staffMemIncharge = getString("Please provide the staff member in charge for the Patient: ");
			// char* staffMemIncharge = getString("Please provide the staff member in charge for the Patient: ", MAX_VISITATION_PURPOSE);
			char* visitPurpose = getString("Please provide the purpose of the Patient's Visit: ");

			VisitationRecord* newVisit = new VisitationRecord(*patient, staffMemIncharge, *arrivalDate, visitPurpose);
			patient->addVistation(*newVisit);

			// Adding Patient to relevant DB if required:
			if (!patient->hasVisitedDepartment(*inDep)) // Patient hasn't visited in this department
			{
				inDep->addPatient(*patient);
				patient->addDepatrtmentToPatient(*inDep);
			}
			if (isFirstTime)
				hospital->addPatient(*patient);

			cout << "Your visitation has been added successfully." << endl;
		}
		case 5:
		{
			char*name = getString("Please enter the name of the researcher");
			Researcher* researcher = new Researcher(name);
			hospital->addResearcher(*researcher);
			delete[]name;
			break;
		}
		case 6:
		{
			char*researcherName = getString("Which researcher would you like to add an article to?");
			Researcher* researcher = nullptr;
			bool exist = hospital->findResearcherAccordingToName(researcherName, researcher);
			if (exist)
			{
				Article * article = createArticle();
				hospital->addArticleToResearcher(*article, researcher);
			}
			else
				cout << "Error,this researcher doesn't exist in the Research Institute" << endl;
			break;
		}
		case 7:
		{
			cout << "Please choose the Department number from the following list: " << endl;
			hospital->showDepartments();
			int depNum;
			cin >> depNum;
			cin.ignore();
			int depInd = depNum - 1;
			bool ok = Utils::ifIndexInRange(depInd, hospital->getNumOfDepartments());
			if (ok)
				hospital->showPatientInSpecificDep(depInd);
			else
				cout << "Error: The Department number chosen is invalid!" << endl;
			break;
		}
		case 8:
		{
			hospital->showStaffMembers(); 
			break;
		}
		case 9:
		{
			hospital->showResearchers();
			break;
		}
		case 10:
		{
			char*id = getString("Please enter the ID of the patient");
			Patient* patient = nullptr;
			bool exist = hospital->getPatientByID(id, patient);
			if (exist)
			{
				cout << "The name of the patient is: " << patient->getName() << endl;
				patient->showDepatmentsVisited();
			}
			else
				cout << "Error, there is no patient with this id" << endl;
			cout << "********************************" << endl;
			break;
		}
		default:
		{
			cout << "Error: Invalid input, please try again..." << endl;
			break;
		}
		}
		printTheOptionsForTheUser();
		cin >> choise;
		cin.ignore();
	}

	cout << "Thank you very much! Hope you enjoyed ;)" << endl;
}

Article* Ui::createArticle()
{
	char *name = getString("Please enter the name of the article");
	char *magazineName = getString("Please enter the name of the magazine where the article was published");
	char*strDate = getString("Please enter the date of the publication [DD/MM/YYYY]");
	Date* date = nullptr;
	bool ok = Utils::convertStrDateToDateObj(strDate, &date);
	delete[]strDate;
	if (ok)
	{
		delete[]name;
		delete[]magazineName;
		return new Article(name, magazineName, *date);
	}
	else
	{
		delete[]name;
		delete[]magazineName;
		cout << "Error,the date is Invalid" << endl;
		return nullptr;
	}
}

Nurse* Ui::createNurse(int employeeID)
{
	char*name = getString("Please enter the name of nurse");
	int yearsExprience = getInt("How many years of exprience the nurse has?");
	return new Nurse(name, employeeID, yearsExprience);
}


int Ui::getInt(const char* str)
{
	int num;
	cout << str << endl;
	cin >> num;
	//
	cin.ignore();
	return num;

}
Doctor* Ui::createDoctor(int employeeID)
{
	char* name = getString("Please enter the name of doctor");
	char* specialty = getString("Please enter the specialty of the doctor");
	return new Doctor(name, employeeID, specialty);
}
	
Patient* Ui::createPatient(char* id)
{
	const char* name = getString("Please enter the Patient's name: ");
	eGender gen = inputGender();
	//const char* id = getString("Please enter the Patient's ID number: ");
	char* yearOfBirth = getString("Please enter the Patient's year of birth: ");
	return (new Patient(name, id, gen, yearOfBirth));
}

char* Ui::getString(const char* prompt)

{
	if (strlen(prompt) > 0)
		cout << prompt << endl;
	
	//cin.clear();
	//cin.ignore(5, '\n');
	//char* temp = new char[MAX_NAME];
	char temp[MAX_NAME];
	cin.getline(temp, MAX_NAME);
	
 	char* str = new char[strlen(temp) + 1];
	strcpy(str, temp);
	//delete[] temp;
	return str;
}

enum eGender Ui::inputGender()
{
	int gen;
	enum eGender gender;
	cout << "please enter your male: male-press 1, female-press 0" << endl;
	cin >> gen;
	//
	cin.ignore();
	gender = (eGender)gen;
	return gender;
}


bool Ui::checkIfItFirstTimeInHospital() const
{
	bool res;
	cout << "Is this your first visit in the hospital?  yes-press 1,no-press 0" << endl;
	cin >> res;
	//
	cin.ignore();
	return res;
}




int Ui::inputYearsOfExprience()const
{
	int yearsExp;
	cout << "how many years of exprience she has?" << endl;
	cin >> yearsExp;
	//
	cin.ignore();
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


