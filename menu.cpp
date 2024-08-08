#include <iostream>
#include <string.h> 
#include <iomanip>
#include "PatientDetail.cpp" // link with PatientDetail.cpp file //
#include "Location.cpp" // link with Location.cpp file //
#include "Symptom.cpp" // link with Symptom.cpp file //

using namespace std;

// ------------------- //
// Create "menu" class // 
// ------------------- //

class menu 
{
    public: // elements declared in this "public" section will be available everywhere // 

		PatientDetail listPatientDetail[100]; // Create an array with 100 elements name "listPatientDetail" store patient detail read from text file // 
		int numPatientDetail = 0; // Initialize variable "numPatientDetail" and assign the value = 0 //
		Location listLocation[100]; 
		int numLocation = 0; 
		Symptom listSymptom[100]; 
		int numSymptom = 0; 

		void readFilePatientDetail(){ // Read patient detail from text file //
			string patientID, name, dOB, address, phoneNumber, visitedLocation, dateTime, lastOverseasTravel, listSymptom, covidTest, status;
			ifstream file("COVID_Patient_data.txt",ios::in); 
			if(!file){
				cout << "Error:can not open file";
				return;
			}
			file >> numPatientDetail; // Read numbers of patient in the file (1st line) // 
			for (int i = 0; i < numPatientDetail; i++) { // for loop //
				// Read every single line in the text file (use "getline") // 
				getline(file, patientID, ','); // "," : read from start until the comma // 
				getline(file, name, ',');
				getline(file, dOB, ',');	
				getline(file, address, ',');
				getline(file, phoneNumber, ',');
				getline(file, visitedLocation, ',');
				getline(file, dateTime, ',');
				getline(file, lastOverseasTravel, ',');
				getline(file, listSymptom, ',');
				getline(file, covidTest, ',');
				getline(file, status, '\n');
				// Initialize the temporary variables for storing patient's data // 
				PatientDetail temp {atoi (patientID.c_str()), name, dOB, address, phoneNumber, visitedLocation, dateTime, lastOverseasTravel, listSymptom, covidTest, status};
				// atoi : convert the patienID from string to integer // 
				listPatientDetail[i] = temp; // all information store in temporary variables // 
			}
			
			file.close(); // Close the file //
		}

		void writeFilePatientDetail() // Write into the PatientDetail text file // 
		{
			ofstream file("COVID_Patient_data.txt",ios::out); 
			file << numPatientDetail << endl; // Write the number of patients to the first line of the text file // 
			for (int i = 0; i < numPatientDetail; i++) { // for loop //
				file << listPatientDetail[i].getPatientID() << ","; // Write information and add comma ',' at the end//
				file << listPatientDetail[i].getName() << ",";
				file << listPatientDetail[i].getdOB() << ",";
				file << listPatientDetail[i].getAddress() << ",";
				file << listPatientDetail[i].getPhoneNumber() << ",";
				file << listPatientDetail[i].getVisitedLocation() << ",";
				file << listPatientDetail[i].getDateTime() << ",";
				file << listPatientDetail[i].getLastOverseasTravel() << ",";
				file << listPatientDetail[i].getSymptoms() << ",";
				file << listPatientDetail[i].getCovidTest() << ",";
				file << listPatientDetail[i].getStatus() << endl;
			}
			// Close the file // 
			file.close();
		}

		void readFileSymptom(){ // Read the Symptom text file // 
			string line;
			ifstream file("COVID_Symptom_data.txt",ios::in);
			if(!file){
				cout << "Error:can not open file";
				return;
			}
			file >> numSymptom; // read the numbers of how many symptoms (1st line) //
			for (int i = 0; i < numSymptom; i++) { // for loop //
				// Read every single line from text file // 
				getline(file, line, ','); // Read information from text file and save into "line" variable // 
				listSymptom[i].setSymptomID(atoi(line.c_str())); // Set id of patient by "line" variable // 
				getline(file, line, ',');
				listSymptom[i].setName(line);
				getline(file, line, '\n');
				listSymptom[i].setTypeRisk(line);
			}
			// Close the file // 
			file.close();
		}

		void writeFileSymptom() // Write the symptom into text file // 
		{
			ofstream file("COVID_Symptom_data.txt",ios::out);
			file << numSymptom << endl; // Write the numbers of symptoms into text file //
			for (int i = 0; i < numSymptom; i++) {
				file << listSymptom[i].getSymptomID() << ","; // get the symptom ID from the array // 
				file << listSymptom[i].getName() << ",";
				file << listSymptom[i].getTypeRisk() << endl;
			}
			file.close();
		}

		void readFileLocation(){ // Read the location detail from the text file //
			string line;
			ifstream file("COVID_Location_data.txt",ios::in);
			if(!file){
				cout << "Error:can not open file";
				return;
			}
			file >> numLocation; // read the numbers of how many locations (1st line) //
			for (int i = 0; i < numLocation; i++) {
				// Read every single line from the text // 
				getline(file, line, ',');
				listLocation[i].setLocationID(atoi(line.c_str())); // Set ID of patient by "line" variable //
				getline(file, line, '\n'); 
				listLocation[i].setLocation(line); 
			}
			// Close the file //
			file.close();
		}

		void writeFileLocation() // Write the location detail to the text file //
		{
			ofstream file("COVID_Location_data.txt",ios::out);
			file << numLocation << endl;
			for (int i = 0; i < numLocation; i++) {
				file << listLocation[i].getLocationID() << ",";
				file << listLocation[i].getLocation() << endl;
			}
			file.close();
		}

		// Check exist of Patient ID?
		bool checkPatientID(int id) {
			for (int i = 0; i < numPatientDetail; i++) {
				if (listPatientDetail[i].getPatientID() == id){
					return true;
				}
			}
			return false;
		}

		// Check high risk base on symptom id (single symptom)
		bool checkHighRiskBySymptomID(int id) { 
			for (int i = 0; i < numSymptom; i++) {
				if (listSymptom[i].getSymptomID() == id && listSymptom[i].getTypeRisk() == "high risk"){
					return true;
				}
			}
			return false;
		}

		// Check high risk of list symptom id (multiple symptoms)
		bool checkHighRisk(string listSymptomID) {
			// refer to https://laptrinhcanban.com/cpp/lap-trinh-cpp-co-ban/chuoi-string-trong-cpp/tach-chuoi-trong-cpp/
			char* char_arr;
			char_arr = &listSymptomID[0];
			const char s[2] = " ";
			char *token;

			token = strtok(char_arr, s);
			while(token != NULL)
			{
				if (checkHighRiskBySymptomID(atoi(token))) {
					return true;
				}
				token = strtok(NULL, s);
			}
			return false;
		}

		string recommendCOVIDTest(string visitedLocation, string symptoms) {
			if (visitedLocation != "" && symptoms != "") {
				return "You should go to for TEST";
			} 
			else if (visitedLocation != "" && symptoms == "") {
				return "Isolate yourself at home";
			}
			else if (visitedLocation == "" && symptoms == "") {
				return "You don't have to test";
			}
			else if (visitedLocation == "" && checkHighRisk(symptoms)) {
				return "You should go to for TEST";
			}
			else if (visitedLocation == "" && !checkHighRisk(symptoms)) {
				return "Isolate yourself at home";
			}
			return "You should go to for TEST";
		}

		string getLocationByLocationID(int locationID) { // Single location
			for (int i = 0; i < numLocation; i++) {
				if (listLocation[i].getLocationID() == locationID) {
					return listLocation[i].getLocation();
				}
			}
			return "";
		}

		string getLocation(string listLocationID) { // Multiple locations
			// refer to https://laptrinhcanban.com/cpp/lap-trinh-cpp-co-ban/chuoi-string-trong-cpp/tach-chuoi-trong-cpp/
			string result = "";
			char* char_arr;
			char_arr = &listLocationID[0];
			const char s[2] = " ";
			char *token;
		
			token = strtok(char_arr, s);
			while(token != NULL)
			{
				char *temp = token;
				token = strtok(NULL, s);
				result = result + temp + ", " + getLocationByLocationID(atoi(temp)) + "\n";
			}
			return result;
		}

		string getSymptomBySymptomID(int symptomID) { // Single symptom
			for (int i = 0; i < numLocation; i++) {
				if (listSymptom[i].getSymptomID() == symptomID) {
					return listSymptom[i].getName();
				}
			}
			return "";
		}

		string getSymptom(string listSymptomID) { // Multiple symptoms
			string result = "";
			char* char_arr;
			char_arr = &listSymptomID[0];
			const char s[2] = " ";
			char *token;
		
			token = strtok(char_arr, s);
			while(token != NULL)
			{
				char *temp = token;
				token = strtok(NULL, s);
				result = result + temp + ", " + getSymptomBySymptomID(atoi(temp)) + "\n";
			}
			return result;
		}

		// Check exist of Patient ID who positive?
		bool checkPatientIDPositive(int id) {
			for (int i = 0; i < numPatientDetail; i++) {
				if (listPatientDetail[i].getPatientID() == id && listPatientDetail[i].getCovidTest() == "Positive") {
					return true;
				}
			}
			return false;
		}

		// Input options as menu to execute
        void executeByMenu()
		{
			readFilePatientDetail();
			if (numPatientDetail == 0) { // If the first line of the patient file = 0 --> "return the database is empty" //
				cout << "[] - the database is empty" << endl;
				exit(1); // exit(1) indicates that the program terminated with an error //
			}			// exit(0) indicates that the program terminated without an error // 
			readFileSymptom();
			if (numSymptom == 0) {
				cout << "Unable to recommend COVID Test – required data missing" << endl;
				exit(1);
			}
			readFileLocation();

			int choose;
			do
			{
				cout << "\n ====================== Recommend the COVID Test =====================" << endl;
				cout << " | 1- Enter your detail for COVID-Test Recommendation                |" << endl;
				cout << " | 2- Submit Your Covid test status & Update the Location database   |" << endl;
				cout << " | 3- Display the Updated Location (High Risk for COVID)             |" << endl;
				cout << " | 4- Update COVID Patient Details           			     |" << endl;
				cout << " | 5- Display the COVID Positive Patient Detail                      |" << endl;
				cout << " | 6- Quit                       		   		     |" << endl;
				cout << " =====================================================================" << endl;
        	    cout << "Enter choose: "; cin >> choose;

        	    switch(choose)
        	    {
        	    	case 1:
        	    		{
							int patientID;
							string name, dOB, address, phoneNumber, lastOverseasTravel, symptoms = "", visitedLocation = "", dateTime;
							do{
								cout << "Enter patient id: "; cin >> patientID;
							} while(checkPatientID(patientID)); // If the input ID is repeated, user has to re-input //
							cin.ignore(); // Skip the "enter" // 
							cout << "Enter name: "; getline(cin, name); // "getline" was used to take input of a string//
							cout << "Enter date of birth: "; getline(cin, dOB);
							cout << "Enter address: "; getline(cin, address);
							cout << "Enter phone number: "; getline(cin, phoneNumber);
							cout << "Enter last overseas travel (Yes or No): "; getline(cin, lastOverseasTravel);
							if (lastOverseasTravel == "Yes"){
								cout << "Enter date time: "; getline(cin, dateTime);
							}
							for (int i = 0; i < numLocation; i++){ // Display the list of locations in file Location_data
								cout << listLocation[i].getLocationID() << ". " << listLocation[i].getLocation() << endl;
							}
							cout << "Select id of visited location (Press ENTER if you did not visit any of the areas): "; getline(cin, visitedLocation);
							for (int i = 0; i < numSymptom; i++){
								cout << listSymptom[i].getSymptomID() << ". " << listSymptom[i].getName() << endl;
							}
							cout << "Select id of symptoms (Press ENTER if you do not have any of the symptoms): "; getline(cin, symptoms);
							PatientDetail temp(patientID, name, dOB, address, phoneNumber, lastOverseasTravel, symptoms, visitedLocation, dateTime);
							listPatientDetail[numPatientDetail++] = temp; // after each iteration of option 1, the number of patient(1st line of the patient data file) will increase by 1 //
							writeFilePatientDetail(); // Write into the PatientDetail text file // 
							cout << recommendCOVIDTest(visitedLocation, symptoms) << endl;
        	    			break;
						}
					case 2:
						{
							int patientID;
							do{
								cout << "Enter patient id: "; cin >> patientID;
							} while(!checkPatientID(patientID)); // must be same as existed patient ID // 
							cin.ignore();
							string covidTest;
							cout << "Enter result of test covid (Positive or Negative): "; getline(cin, covidTest);
							if (covidTest == "Positive"){
								int numVisitedLocation = 0;
								string visitedLocation[100]; // create an array to store patient's visited location // 
								string listLocationID = ""; 
								cout << "Enter number of visited location: "; cin >> numVisitedLocation;
								cin.ignore(); // skip the "ENTER" //
								for (int i = 1; i <= numVisitedLocation; i++) {
									cout << "Enter visited location " << i << ": "; getline(cin, visitedLocation[i]); // take input visited location //
									listLocation[numLocation].setLocationID(numLocation + 1); 
									listLocation[numLocation].setLocation(visitedLocation[i]);
									numLocation++;
									writeFileLocation();
									listLocationID += to_string(numLocation) + " "; // to_string : convert number of locations into string //
								}
								for (int i = 0; i < numPatientDetail; i++) {
									if (listPatientDetail[i].getPatientID() == patientID) {
										listPatientDetail[i].setCovidTest(covidTest); // The set method takes a parameter (Name) and assigns it to the name variable.
										listPatientDetail[i].setVisitedLocation(listLocationID);
										writeFilePatientDetail();
									}
								}
							}
							break;
						}                  				
					case 3:
					    {
							cout << "====================== THE LOCATION FOR HIGH-RISK LOCATION===========================" << endl;
							cout << "Location ID" << "		Location" << endl;
					    	for (int i = 0; i < numLocation; i++) {
								cout << listLocation[i].getLocationID() << "		" << listLocation[i].getLocation() << endl;
							}
					    	break;
						}					
                    case 4:
						{
							int patientID;
							do{
								cout << "Enter patient id: "; cin >> patientID;
							} while(!checkPatientIDPositive(patientID));
							cin.ignore();
							string status;
							cout << "Enter status of patient (Cured or Dead): "; getline(cin, status);
							
							for (int i = 0; i < numPatientDetail; i++) {
								if (listPatientDetail[i].getPatientID() == patientID) {
									if (status == "Cured") {
										listPatientDetail[i].setCovidTest("Negative");
										listPatientDetail[i].setStatus("Alive");
									}
									else {
										listPatientDetail[i].setStatus("Dead");
									}
									
								}
							}
							
							writeFilePatientDetail();
							break;
						}
                    case 5:
                        {
							cout << "====================== THE COVID POSITIVE PATIENTS DETAIL===========================" << endl;
							for (int i = 0; i < numPatientDetail; i++) {
								if (listPatientDetail[i].getCovidTest() == "Positive") {
									cout << "Patient ID: " << listPatientDetail[i].getPatientID() << endl;
									cout << "Visited Location: " << endl << getLocation(listPatientDetail[i].getVisitedLocation());
									cout << "Last Overseas Travel: " << listPatientDetail[i].getLastOverseasTravel() << endl;
									cout << "Date time: " << listPatientDetail[i].getDateTime() << endl;
									cout << "Symptom: " << endl << getSymptom(listPatientDetail[i].getSymptoms()) << endl;
								}
							}
                            break;
                        }
					case 6:
					    {
					    	cout << "Goodbye" << endl;
                            exit(1);
						}	
                    default :
                        {
                            cout << "Unknown selection, please try again" << endl;
                        }
				}
			}
			while(choose != 6);
		}
};
