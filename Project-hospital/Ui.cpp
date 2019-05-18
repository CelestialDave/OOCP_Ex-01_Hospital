#include "Ui.h"
#include "ConstantsAndGenFuncs.h"
#include "Date.h"
#include "Hospital.h"
#include "Utils.h"
#include "Visit_Surgery.h"



Ui::Ui(Hospital *hos)
{
	hospital = hos;
}

void Ui::start()
{
	printMainMenu();
	int choise;
	bool exit = false;
	cin >> choise;
	cin.ignore();
	while (!exit)
	{
		bool askToContinue = false;
		switch (choise)
		{
		case 1:  //add a department to the hospital
		{
			Results res;
			res = addNewDepartment();
			if (res != SUCCESS)
			{
				warnings(res);
				askToContinue = true;
			}
			break;
		}
		case 2:   //add a nurse
		{
			Results res;
			res = addNewNurse();
			if (res != SUCCESS)
			{
				warnings(res);
				askToContinue = true;
			}
			break;
		}
		case 3: //add doctor to the hospital
		{
			Results res;
			res = addNewDoctor();
			if (res != SUCCESS)
			{
				warnings(res);
				askToContinue = true;
			}
			break;
		}
		case 4:	// Add Visitation
		{
			Results res;
			res = addNewVisitation();
			if (res != SUCCESS)
			{
				warnings(res);
				askToContinue = true;
			}
			break;

		}
		case 5: //add researcher to the researcher insistute
		{
			addNewResearcher();
			break;
		}
		case 6:   //add article to specific researcher
		{
			Results res;
			res = addArticleToResearcher();
			if (res != SUCCESS)
			{
				warnings(res);
				askToContinue = true;
			}
			//printSpaceLine();
			break;
		}
		case 7: //show patients in specific department
		{
			Results res;
			res = showPatientsInDepartment();
			if (res != SUCCESS)
			{
				warnings(res);
				askToContinue = true;
			}
			break;
		}
		case 8: //show medical staff members
		{
			hospital->showMedicalStaffMembers(); 
			break;
		}
		case 9: // Show all researchers in Research Institute
		{
			hospital->showResearchers();
			break;
		}
		case 10: // Show all Researchers that are Doctors in the Research Institute
		{
			hospital->showDoctorResearchers();
			break;
		}
		case 11: //search patient by ID number
		{
			char*id = getString("Patient's ID number: ");
			bool isExists = false;
			Patient* patient = hospital->getPatientByID(id, &isExists);
			if (isExists)  //the ID numebr input of patient is exist
			{
				cout << "Patient's name: " << patient->getName() << endl;
				printVisitationPorpuse(patient);
				//patient->showDepatmentsVisited();
			}
			else
				cout << "Error: Patient's ID was not found." << endl;
			break;
		}
		case 12:// Which researcher has more articles
		{
			compare2Researchers();
			break;
		}
		case 13:
			exit = true;
			break;
		default:
		{
			cout << "Error: Invalid input, please try again..." << endl;
			break;
		}
		}

		printSpaceLine();
		if (askToContinue) {
			char* reply = getString("Would you like to continue? [y/n]");
			while ((strcmp(reply, "y") != 0) && (strcmp(reply, "n") != 0))
			{
				cout << "Error: invalid input. please enter 'y' for \"Yes\", 'n' for \"No\"..." << endl;
				reply = getString("Would you like to continue? [y/n]");
			}
			if (strcmp(reply, "n") == 0)
			{
				exit = true;
				printSpaceLine();
			}
			else
			{
				printMainMenu();
				cin >> choise;
				cin.ignore();
			}
		}
		else if (!exit)
		{
			printSpaceLine();
			printMainMenu();
			cin >> choise;
			cin.ignore();
		}
	}

	cout << "\n\nFarewell... \n\nAnd remember; \"Medicus curat, natura sanat\".\n" << endl;
}

void Ui::printSpaceLine() const
{
	cout << "\n==================================================================\n" << endl;
}


void Ui::compare2Researchers() const
{
	cout << "Choose 2 Researchers for article number comparison from the list below: " << endl;
	hospital->showResearchersName();
	int researcher1Ind, researcher2Ind;
	cin >> researcher1Ind >> researcher2Ind;
	researcher1Ind--;
	researcher2Ind--;
	bool ok1 = Utils::ifIndexInRange(researcher1Ind, hospital->getSizeOfResearchers());
	bool ok2 = Utils::ifIndexInRange(researcher2Ind, hospital->getSizeOfResearchers());
	if (ok1 && ok2)
	{
		Researcher* researcher1 = hospital->getResearcherByIndex(researcher1Ind);
		Researcher* researcher2 = hospital->getResearcherByIndex(researcher2Ind);

		if (researcher1 > researcher2)
		{
			cout << "True: " << researcher1->getName() <<
				" has more articles than " << researcher2->getName() << endl;
		}
		else
		{
			cout << "False: " << researcher1->getName() <<
				" has less or equal number of aritcles than " << researcher2->getName() << endl;
		}
	}
	else
		cout << "Error: invalid input" << endl;
}

VisitationRecord* Ui::createVisit(Patient & patient,Date* arrivalDate,int choice, Results& res)
{
	char* visitPurpose = getString("Visitation purpose: ");
	if (choice == CHECKUP)
	{
		char* staffMemIncharge = getString("Medical staff member in charge: ");
		VisitationRecord* visit=new VisitationRecord(patient, staffMemIncharge, *arrivalDate, visitPurpose);
		res = SUCCESS;
		delete[]staffMemIncharge;
		delete[]visitPurpose;
		return visit;
	}
	else if (choice == SURGERY)
	{
		cout << "Please provide the Employee-ID number of your surgeon from the following list: "
		<< endl;
		hospital->showSurgeons();
		if (hospital->getNumOfSurgeons() > 0)
		{
			int employeeIDNum;
			cin >> employeeIDNum;
			int  indexSurgeon = hospital->binSearchStaffMemberByID(employeeIDNum);
			if (indexSurgeon != -1)
			{
				Surgeon*surgeon = dynamic_cast<Surgeon*>(hospital->getStaffMemberByIndex(indexSurgeon));
				surgeon->addSurgery();
				char* staffMemIncharge = strdup(surgeon->getName());
				VisitationRecord* visit = new VisitationRecord(patient, staffMemIncharge, *arrivalDate, visitPurpose);
				int surgeryRoomNum = getInt("Surgery Room Number: ");
				int fasting = getInt("Has the Patient been fasting? \n\t1.Yes\t2. No.\n");

				if (fasting == 1 || fasting == 0)
				{
					bool isFasting = (bool)fasting;
					VisitSurgery* newVisit = new VisitSurgery(*visit, surgeryRoomNum, isFasting);
					delete[]staffMemIncharge;
					delete[]visitPurpose;
					delete visit;
					return newVisit;
				}
			}
			else
			{
				delete[]visitPurpose;
				res = BADINPUT;
				return nullptr;
			}

		}
		else
		{
			delete[]visitPurpose;
			res = NOSURGINDEP;
			return nullptr;
		}
	}
	else
	{
		delete[]visitPurpose;
		res = BADINPUT;
		return nullptr;
	}
}
Article* Ui::createArticle(Date* date)
{
	char *name = getString("Article's name: ");
	char *magazineName = getString("The magazine in which article was published:");
	return new Article(name, magazineName,*date);
}

Nurse* Ui::createNurse()
{
	char*name = getString("Nurse's name: ");
	int yearsExprience = getInt("Years of Experience: ");
 	return new Nurse(name, yearsExprience);
}


int Ui::getInt(const char* str)
{
	int num;
	cout << str << endl;
	cin >> num;
	cin.ignore();
	return num;

}
Doctor* Ui::createDoctor()
{
	char* name = getString("Doctor's name: ");
	char* specialty = getString("Doctor's speciality: ");
	return new Doctor(name,specialty);
}
	
Patient* Ui::createPatient(char* id)
{
	const char* name = getString("Patient's name: ");
	eGender gen = inputGender();
	char* yearOfBirth = getString("Patient's year of birth: ");
	return (new Patient(name, id, gen, yearOfBirth));
}

char* Ui::getString(const char* prompt)

{
	if (strlen(prompt) > 0)
		cout << prompt << endl;
	
	char temp[MAX_NAME];
	cin.getline(temp, MAX_NAME);
 	char* str = new char[strlen(temp) + 1];
	strcpy(str, temp);
	return str;
}

enum eGender Ui::inputGender()
{
	int gen;
	enum eGender gender;
	cout << "Patient's gender: \n\t1. Male.\n\t2. Female." << endl;
	cin >> gen;
	cin.ignore();
	gender = (eGender)(gen - 1);
	return gender;
}

bool Ui::checkIfItFirstTimeInHospital() const
{
	int input;
	cout << "Is this the Patient's first visit?\n\t1. No.\n\t2. Yes." << endl;
	cin >> input;
	cin.ignore();
	return (input == 2);
}


int Ui::inputYearsOfExprience()const
{
	int yearsExp;
	cout << "Years of experience: " << endl;
	cin >> yearsExp;
	cin.ignore();
	return yearsExp;
}

void Ui::printVisitationPorpuse(Patient* patient) const
{
	int numVisits = patient->getSizeVisits();
	numVisits--;
	/*The number of visit more than one because we know the patient is exist,
	we want to get the last visitation to check if it was for Surgery or checkup */
	VisitationRecord* lastVisit = patient->getVisitByIndex(numVisits);

	VisitSurgery* temp = dynamic_cast<VisitSurgery*>(lastVisit);
	if (temp)
		cout << "The last patient visitation was for surgery" << endl;
	else
		cout << "The last patient visitation was for checkup" << endl;
}


Results Ui::addNewDepartment()
{
	Results res = SUCCESS;
	char* name = getString("Department's name: ");
	Department* department = new Department(name);
	int index = hospital->binSearchDepartmentByName(department->getName());
	if (index == -1) //if this is new department name
		hospital->addDepartment(*department); //add to the departments array
	else
		res = DEPEXIST;
	delete[] name;
	return res;
}

Results Ui::addNewNurse()
{
	Results res = SUCCESS;
	if (hospital->isDepartmentsEmpty())
	{
		res = NODEPS;
	}
	else {
	/*	int employeeID = getInt("Nurse's Employee ID Number: [1-9 digits]");
		bool existID = hospital->verifyEmployeeIDNumber(employeeID);
		if (!existID)
		{*/
		int depNum;
		cout << "Please choose the Department number from the following list: " << endl;
		hospital->showDepartments();
		cin >> depNum;
		cin.ignore();
		int depInd = depNum - 1;
		bool existDep = Utils::ifIndexInRange(depInd, hospital->getNumOfDepartments());
		if (existDep)
		{
			Nurse*nurse = createNurse();
			hospital->addStaffMember(nurse);
			hospital->addStaffMemberToDepartment(nurse, depInd);
		}
		else
			res = BADINPUT;
	//	}
	/*	else
			res = EIDEXIST;*/
	}
	return res;
}

Results Ui::addNewDoctor()
{
	Results res = SUCCESS;
	if (hospital->isDepartmentsEmpty())
	{
		res = NODEPS;
	}
	else {
		int docType = getInt("Please choose whether the Doctor is also:\n\t1.Researcher.\n\t2.Surgeon.\n\t3.Surgeon - Researcher.\n\t4.None.\n");
		if ((docType < 1) || (docType > 4))
		{
			res = BADINPUT;
		}
		else
		{
			int depNum;
			cout << "Please choose the Department number from the following list: " << endl;
			hospital->showDepartments();
			cin >> depNum;
			cin.ignore();
			int depInd = depNum - 1;
			bool existDep = Utils::ifIndexInRange(depInd, hospital->getNumOfDepartments());
			if (!existDep)
			{
				res = BADINPUT;
			}
			else {
				Doctor* doctor = createDoctor();
				if (docType == 4)
				{
					hospital->addStaffMember(doctor);
					hospital->addStaffMemberToDepartment(doctor, depInd);
				}
				else if ((docType == 2) || (docType == 3))
				{
					int numSurgeries = getInt("Please provide number of Surgeries perfromed: ");
					Surgeon* surgeon = new Surgeon(*doctor, numSurgeries);
					if (docType == 3)
					{
						Researcher* researcher = new Researcher(doctor->getName());
						SurgeonResearcher* surgeonResearcher = new SurgeonResearcher(*surgeon, *researcher);
						hospital->addStaffMember(surgeonResearcher);
						hospital->addStaffMemberToDepartment(surgeonResearcher, depInd);
						hospital->addResearcher(surgeonResearcher);
						delete doctor;
						delete surgeon;
						delete researcher;
					}
					else // (docType == 2)
					{
						hospital->addStaffMember(surgeon);
						hospital->addStaffMemberToDepartment(surgeon, depInd);
						delete doctor;
					}
				}
				else // (docType == 1) -> ResearcherDoctor
				{
					Researcher* researcher = new Researcher(doctor->getName());
					ResearcherDoctor* researcherDoctor = new ResearcherDoctor(*researcher, *doctor);
					hospital->addStaffMember(researcherDoctor);
					hospital->addStaffMemberToDepartment(researcherDoctor, depInd);
					hospital->addResearcher(researcherDoctor);
					delete doctor;
				}
			}
		}
	}
	return res;
}

Results Ui::addNewVisitation()
{
	
	if (hospital->getNumOfDepartments() == 0)
		return NODEPS;
	Results res = SUCCESS;
	Department* department = nullptr;
	char* inID = getString("Patient's ID number: ");
	bool isFirstTime = checkIfItFirstTimeInHospital();
	bool isExists = false;
	Patient* patient = hospital->getPatientByID(inID, &isExists);

	if (isFirstTime) //this is the first visit in the hospital
	{
		if (isExists) // 1st time = Shouldn't exist
		{
			res = PIDEXIST;
			delete[] inID;
			return res;
		}
		else {
			patient = createPatient(inID);
		}
	}
	else //it is not the first visit
	{
		if (!isExists) // Should exist
		{
			res = PIDNOTFOUND;
			delete[] inID;
			return res;
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
		res = BADINPUT;
		delete[] inID;
		if (!isExists)
			delete patient;
		return res;
	}
	else
	{
		Department* inDep = nullptr;
		inDep = hospital->getDepartmentByIndex(depInd);

		char* inDate = getString("Patient's arrival date: [DD/MM/YYYY]");
		Date* arrivalDate = nullptr;
		bool isValidDateInput = Utils::convertStrDateToDateObj(inDate, &arrivalDate);
		if (!isValidDateInput)
		{
			res = BADFORMAT;
			delete[] inID;
			delete[] inDate;
			if (!isExists)
				delete patient;
			return res;
		}
		else
		{
			int visitChosen = getInt("Visitation purpose:\n\t1. Checkup.\n\t2. Surgery.\n");

			bool ok = true;
			if (visitChosen == SURGERY)
			{
				if (hospital->getNumOfSurgeons() == 0)
					res = NOSURGINHOS;
				else if (inDep->getNumOfSurgeons() == 0)
					res = NOSURGINDEP;
			}

			if (!res == SUCCESS)
				return res;

			VisitationRecord* newVisit = createVisit(*patient, arrivalDate, visitChosen, res);

			if (res == SUCCESS)
			{
				patient->addVisitiaionRecord(newVisit);
				// Adding Patient to relevant DB if required:
				if (!patient->hasVisitedDepartment(*inDep)) // Patient hasn't visited in this department
				{
					inDep->addPatient(*patient);
					patient->addDepatrtmentToPatient(*inDep);
				}
				if (isFirstTime)
					hospital->addPatient(*patient);
				cout << "Visitation added successfully." << endl;
			}
			else
			{
				//res = BADFORMAT;
				delete[] inID;
				delete[] inDate;
				if (!isExists)
					delete patient;
				return res;
			}
		}
	}
	//return res;
}

void Ui::addNewResearcher()
{
	char*name = getString("Researcher's name: ");
	Researcher* researcher = new Researcher(name);
	hospital->addResearcher(researcher);
	delete[]name;
}

Results Ui::addArticleToResearcher()
{
	Results res = SUCCESS;
	if (hospital->getSizeOfResearchers() > 0)
	{
		char*researcherName = getString("Which researcher would you like to add an article to?");
		bool exist = false;
		Researcher*researcher = hospital->findResearcherAccordingToName(researcherName, exist);
		if (exist) //if the researcher name input is ok
		{
			char*strDate = getString("Publication Date: [DD/MM/YYYY]");
			Date* date = nullptr;
			bool okDate = Utils::convertStrDateToDateObj(strDate, &date);
			if (okDate)
			{
				Article * article = createArticle(date);
				hospital->addArticleToResearcher(*article, researcher);
			}
			else
				res = BADFORMAT;
			delete[]strDate;
		}
		else
			res = RNONEXIST;
		delete[]researcherName;
	}
	else
		res = RESINSTEMPTY;
	return res;
}

Results Ui::showPatientsInDepartment()
{
	Results res = SUCCESS;
	if (hospital->getNumOfDepartments() > 0)
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
			// bad input1:
			res = BADINPUT;
	}
	else
		res = NODEPS;
	return res;
}

void Ui::warnings(Results result)
{
	if (result != SUCCESS)
	{
		switch (result) {
		case NOTFOUND:
			cout << "";
			break;
		case BADINPUT:
			cout << "Error: Invalid input." << endl;
			break;
		case BADFORMAT:
			cout << "Error: Invalid input or not according to format." << endl;
			break;
		case NODEPS:
			cout << "Error: No Departments availble in Hospital." << endl;
			break;
		case DEPEXIST:
			cout << "Error: A Department by the given name already exist." << endl;
			break;
		case NOSTAFF:
			cout << "Error: There are no Staff Members availavle in Hospital." << endl;
			break;
		case NOSURGINHOS:
			cout << "Error: There are no Surgeons available in Hospital." << endl;
			break;
		case NOSURGINDEP:
			cout << "Error: There are no Surgeons available in the chosen Department." << endl;
			break;
		case EIDEXIST:
			cout << "Error: An Employee with the given Employee-ID Number already exists." << endl;
			break;
		case PIDEXIST:
			cout << "Error: A Patient with the given ID number already exists." << endl;
			break;
		/*case EIDNOTFOUND:
			cout << "";
			break;*/
		case PIDNOTFOUND:
			cout << "Error: Patient's ID was not found." << endl;
			break;
		case RNONEXIST:
			cout << "Error: Researcher doesn't exist in the Research Institute" << endl;
			break;
		case RESINSTEMPTY:
			cout << "Error: No Researchers available in the Research Institute." << endl;
			break;
		default:
			break;
		}
	}

}


void Ui::printMainMenu() const
{
	cout << "\t\t::Hospital Management System::" << endl;
	cout << "\nPlease choose an option from the following list:\n" << endl;
	cout << "\t1. Add a Department to the Hospital." << endl;
	cout << "\t2. Add a Nurse to the Hospital." << endl;
	cout << "\t3. Add a Doctor to the Hospital." << endl;
	cout << "\t4. Add a Patient's Visitation." << endl;
	cout << "\t5. Add a Researcher to The Hospital's Research Institute." << endl;
	cout << "\t6. Add a Researcher's Article." << endl;
	cout << "\t7. Show all Patients by Department." << endl;
	cout << "\t8. Show all the Hospital's Medical Staff Members." << endl;
	cout << "\t9. Show all Researchers in the Research Institute." << endl;
	cout << "\t10. Show all Researchers that are Doctors in the Research Institute." << endl;
	cout << "\t11. Get a Patient information by ID." << endl;
	cout << "\t12. Compare Researchers (>): \n\t\tShow between 2 chosen researchers if left has \n\t\tgreater number of articles then the one on the right." << endl;
	cout << "\t13. Exit Program." << endl;
}


