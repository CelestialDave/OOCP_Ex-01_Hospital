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
			try {
				addNewDepartment();
			}
			catch (StringException& e)
			{
				e.show();
				askToContinue = true;
			}
			catch (DepartmentExistException& e)
			{
				e.show();
				askToContinue = true;
			}
			break;
		}
		case 2:   //add a nurse
		{
			Results res;
			try
			{
				res = addNewNurse();
			}
			catch (FormatException& e)
			{
				e.show();
				res = BADFORMAT;
			}
			catch (StringException& e)
			{
				e.show();
				res = BADINPUT;
			}
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
			try {
				addNewDoctor();
			}
			catch (StringException& e)
			{
				e.show();
				askToContinue = true;
			}
			catch (DepartmentsEmptyException& e)
			{
				e.show();
				askToContinue = true;
			}
			catch (FormatException& e)
			{
				e.show();
				askToContinue = true;
			}
			break;
		}
		case 4:	// Add Visitation
		{
			Results res=SUCCESS;
			try
			{
				res = addNewVisitation();
			}
			catch (DepartmentsEmptyException& e)
			{
				e.show();
			}
			catch (PatientException& e)
			{
				e.show();
			}
			catch (FormatException& e)
			{
				e.show();
			}
			catch (StringException& e)
			{
				e.show();
			}
			catch (DateException& e)
			{
				e.show();
			}
			if (res != SUCCESS)
			{
				warnings(res);
				askToContinue = true;
			}
			break;

		}
		case 5: //add researcher to the researcher insistute
		{
			try {
				addNewResearcher();
			}
			catch (StringException& e)
			{
				e.show();
			}
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
			try {
				showPatientsInDepartment();
			}
			catch (StringException& e)
			{
				e.show();
				askToContinue = true;
			}
			catch (DepartmentsEmptyException& e)
			{
				e.show();
				askToContinue = true;
			}
			break;
		}
		case 8: //show medical staff members
		{
			Results res = SUCCESS;
			res=hospital->showMedicalStaffMembers(); 
			if (res != SUCCESS)
			{
				warnings(res);
				askToContinue = true;
			}
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
			string id = getString("Patient's ID number: ");
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
			string reply = getString("Would you like to continue? [y/n]");
			while ((reply != "y") && (reply != "n"))
			{
				cout << "\nError: invalid input. please enter 'y' for \"Yes\", 'n' for \"No\"...\n" << endl;
				reply = getString("Would you like to continue? [y/n]");
			}
			if (reply == "n")
			{
				exit = true;
				printSpaceLine();
			}
			else // (reply == "y")
			{
				printSpaceLine();
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

		if (*researcher1 > *researcher2)
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

VisitationRecord* Ui::createVisit(Patient & patient,Date* arrivalDate,int choice, Results& res) throw(StringException,FormatException)
{
	string visitPurpose = getString("Visitation Description: ");
	if (choice == CHECKUP)
	{
		string staffMemIncharge = getString("Medical staff member in charge: ");
		if (!Utils::isValidString(staffMemIncharge))
			throw StringException();
		VisitationRecord* visit = new VisitationRecord(patient, staffMemIncharge, *arrivalDate, visitPurpose);
		res = SUCCESS;
		return visit;
	}
	else if (choice == SURGERY)
	{
		cout << "Please provide the Employee-ID number of your surgeon from the following list: "
		<< endl;
		hospital->showSurgeons();
		int employeeIDNum;
		cin >> employeeIDNum;
		int  indexSurgeon = hospital->binSearchStaffMemberByID(employeeIDNum);
		if (indexSurgeon != -1)
		{
			Surgeon*surgeon = dynamic_cast<Surgeon*>(hospital->getStaffMemberByIndex(indexSurgeon));
			/*if (!surgeon)
			{
				res = BADINPUT;
				delete[] visitPurpose;
				return nullptr;
			}*/
			surgeon->addSurgery();
			string staffMemIncharge = surgeon->getName();
			VisitationRecord* visit = new VisitationRecord(patient, staffMemIncharge, *arrivalDate, visitPurpose);
			int surgeryRoomNum = getInt("Surgery Room Number: ");
			int fasting = getInt("Has the Patient been fasting? \n\t1.Yes\t2. No.\n");

			if (fasting == 1 || fasting == 0)
			{
				bool isFasting = (bool)fasting;
				VisitSurgery* newVisit = new VisitSurgery(*visit, surgeryRoomNum, isFasting);
				//delete[]staffMemIncharge;
				//delete[]visitPurpose;
				delete visit;
				return newVisit;
			}
		

		}
		else
		{
			//delete[]visitPurpose;
			throw FormatException();
			return nullptr;
		}
	}
	else
	{
		//delete[]visitPurpose;
		throw FormatException();
		return nullptr;
	}
}
Article* Ui::createArticle(Date* date) throw(StringException)
{
	string name = getString("Article's name: ");
	if (!Utils::isValidString(name))
		throw StringException();
	string magazineName = getString("The magazine in which article was published:");
	return new Article(name, magazineName,*date);
}

Nurse* Ui::createNurse()
{
	string name = getString("Nurse's name: ");
	int yearsExprience = getInt("Years of Experience: ");
 	return new Nurse(name, yearsExprience);
}


int Ui::getInt(const string str)
{
	int num;
	cout << str << endl;
	cin >> num;
	cin.ignore();
	return num;

}
Doctor* Ui::createDoctor()
{
	string name = getString("Doctor's name: ");
	string specialty = getString("Doctor's speciality: ");
	return new Doctor(name,specialty);
}
	
Patient* Ui::createPatient(string id) throw(StringException)
{
	const string name = getString("Patient's name: ");
	if (!Utils::isValidString(name))
		throw StringException();
	string yearOfBirth = getString("Patient's year of birth: ");
	if(!Utils::isValidString(yearOfBirth))
		throw StringException();
	try
	{
	eGender gen = inputGender();
	return (new Patient(name, id, gen, yearOfBirth));
	}
	catch (FormatException& e)
	{
		e.show();
	}
}

string Ui::getString(const string prompt)

{
	cout << prompt << endl;
	string str;
	getline(cin, str);
	
	return str;
}

enum eGender Ui::inputGender() throw (FormatException)
{
	int gen;
	enum eGender gender;
	cout << "Patient's gender: \n\t1. Male.\n\t2. Female." << endl;
	cin >> gen;
	if (gen != 1 && gen != 2)
		throw FormatException();
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
	/*The number of visit more than one because we know the patient exists,
	we want to get the last visitation to check if it was for Surgery or Checkup */
	VisitationRecord* lastVisit = patient->getVisitByIndex(numVisits);

	VisitSurgery* temp = dynamic_cast<VisitSurgery*>(lastVisit);
	if (temp)
		cout << "The last patient visitation was for surgery" << endl;
	else
		cout << "The last patient visitation was for checkup" << endl;
}


void Ui::addNewDepartment() throw(DepartmentExistException)
{
	string name = getString("Department's name: ");
	int index = hospital->binSearchDepartmentByName(name);
	if (index == -1) //if this is new department name
	{
		Department* department = new Department(name);
		hospital->addDepartment(*department); //add to the departments array
	}
	else
	{
		throw DepartmentExistException();
	}
}

Results Ui::addNewNurse() 
{
	Results res = SUCCESS;
	if (hospital->isDepartmentsEmpty())
	{
		throw DepartmentsEmptyException();
		res = NODEPS;
	}
	else {
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
		{
			throw FormatException();
			res = BADINPUT;
		}
	}
	return res;
}


void Ui::addNewDoctor() throw(HospitalException)
{
	if (hospital->isDepartmentsEmpty())
	{
		throw DepartmentsEmptyException();
	}
	else {
		int docType = getInt("Please choose whether the Doctor is also:\n\t1.Researcher.\n\t2.Surgeon.\n\t3.Surgeon - Researcher.\n\t4.None.\n");
		if ((docType < 1) || (docType > 4))
		{
			throw FormatException();
		}
		else
		{
			int depNum;
			cout << "Please choose the Department number from the following list: " << endl;
			hospital->showDepartments();
			cin >> depNum;
			cin.ignore();
			int depInd = depNum - 1;
			if (!Utils::ifIndexInRange(depInd, hospital->getNumOfDepartments()))
				throw FormatException();

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

Results Ui::addNewVisitation()
throw(DepartmentsEmptyException,PatientException,FormatException,StringException,DateException)
{
	
	if (hospital->getNumOfDepartments() == 0)
	{
		throw DepartmentsEmptyException();
		return NODEPS;
	}
	Results res = SUCCESS;
	Department* department = nullptr;
	string inID = getString("Patient's ID number: ");
	if (!Utils::isValidString(inID))
		throw StringException();
	bool isFirstTime = checkIfItFirstTimeInHospital();
	bool isExists = false;
	Patient* patient = hospital->getPatientByID(inID, &isExists);

	if (isFirstTime) //this is the first visit in the hospital
	{
		if (isExists) // 1st time = Shouldn't exist
		{
			res = PIDEXIST;
			return res;
		}
		else
		{
			try
			{
				patient = createPatient(inID);
			}
			catch (StringException & e)
			{
				e.show();
			}
		}
	}
	else //it is not the first visit
	{
		if (!isExists) // Should exist
		{
			throw PatientException();
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
		delete patient;
		throw FormatException();
		res = BADINPUT;
	}
	else
	{
		Department* inDep = nullptr;
		inDep = hospital->getDepartmentByIndex(depInd);

		string inDate = getString("Patient's arrival date: [DD/MM/YYYY]");
		Date* arrivalDate=new Date(inDate);
		int visitChosen = getInt("Purpose of Visitation:\n\t1. Checkup.\n\t2. Surgery.\n");

		bool ok = true;
		if (visitChosen == SURGERY)
		{
			if (hospital->getNumOfSurgeons() == 0)
			{
				throw SurgeonException();
				res = NOSURGINHOS;
			}
			else if (inDep->getNumOfSurgeons() == 0)
			{
				throw SurgeonException();
				res = NOSURGINHOS;
			}
		}
		try
		{
			VisitationRecord* newVisit = createVisit(*patient, arrivalDate, visitChosen, res);
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
		catch (StringException& e)
		{
			e.show();
		}
		catch (FormatException& e)
		{
			e.show();
		}
	}
}

void Ui::addNewResearcher()
{
	string name = getString("Researcher's name: ");
	Researcher* researcher = new Researcher(name);
	hospital->addResearcher(researcher);
}

Results Ui::addArticleToResearcher() throw(ResearchersEmptyException)
{
	Results res = SUCCESS;
	if (hospital->getSizeOfResearchers() > 0)
	{
		try
		{
			string researcherName = getString("Which researcher would you like to add an article to?");
			bool exist = false;
			Researcher*researcher = hospital->findResearcherAccordingToName(researcherName, exist);
			if (exist) //if the researcher name input is ok
			{
				string strDate = getString("Publication Date: [DD/MM/YYYY]");
				Date* date = new Date(strDate);
				Article * article = createArticle(date);
				hospital->addArticleToResearcher(*article, researcher);
			}
		}
		catch (DateException& e)
		{
			e.show();
		}
		catch (ResearcherDoesntExistException& e)
		{
			e.show();
		}
		catch (StringException& e)
		{
			e.show();
		}
		catch (FormatException & e)
		{
			e.show();
		}
	}
	else
	{
		throw ResearchersEmptyException();
	}
		return res;
	
}

void Ui::showPatientsInDepartment() throw(HospitalException)
{
	if (hospital->isDepartmentsEmpty())
		throw DepartmentsEmptyException();

	cout << "Please choose the Department number from the following list: " << endl;
	hospital->showDepartments();
	int depNum;
	cin >> depNum;
	cin.ignore();
	int depInd = depNum - 1;

	////bool ok = Utils::ifIndexInRange(depInd, hospital->getNumOfDepartments());
	////if (ok)
	////	hospital->showPatientInSpecificDep(depInd);
	////else
	////	res = BADINPUT;

	if (!Utils::ifIndexInRange(depInd, hospital->getNumOfDepartments()))
		throw StringException();

	hospital->showPatientInSpecificDep(depInd);
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
	cout << "\t13. Exit Program." << "\n\n\n";
}


