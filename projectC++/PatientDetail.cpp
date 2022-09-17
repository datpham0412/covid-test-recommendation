#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class PatientDetail 
{
	protected:
		int patientID; // patient ID
		string name; // patient's name
		string dOB; // patient's date of birth 
		string address; // patient's address
		string phoneNumber; // patient's phone number
		string visitedLocation; // place potentially exposed to covid
		string dateTime; // time visited
		string lastOverseasTravel; // travel overseas or not
		string symptoms; // symptoms list
		string covidTest; // covid test result
		string status; // patient's status

	public:
		// Initialize function without parameter //
		PatientDetail(){
			// To access members of a structure through a pointer, use the arrow operator. //

		}

		// Initialize function with 11 parameters //
		// parameterized constructor //
		PatientDetail(int patientID, string name, string dOB, string address, string phoneNumber, string visitedLocation,
						string dateTime, string lastOverseasTravel, string symptoms, string covidTest, string status)
		{
			// To access members of a structure through a pointer, use the arrow operator. //
			this->patientID = patientID; // assign all attributes for this object with the parameters //
			this->name = name;
			this->dOB = dOB;
			this->address = address;
			this->phoneNumber = phoneNumber;
			this->visitedLocation = visitedLocation;
			this->dateTime = dateTime;
			this->lastOverseasTravel = lastOverseasTravel;
			this->symptoms = symptoms;
			this->covidTest = covidTest;
			this->status = status;
		}
		
		int getPatientID() {
			return this->patientID;
		}
		void setPatientID(int patientID) {
			this->patientID = patientID;
		}
		string getName() {
			return this->name;
		}
		void setName(string name) {
			this->name = name;
		}
		string getdOB() {
			return this->dOB;
		}
		void setdOB(string dOB) {
			this->dOB = dOB;
		}
		string getAddress() {
			return this->address;
		}
		void setAddress(string address) {
			this->address = address;
		}
		string getPhoneNumber() {
			return this->phoneNumber;
		}
		void setPhoneNumber(string phoneNumber) {
			this->phoneNumber = phoneNumber;
		}
		string getVisitedLocation() {
			return this->visitedLocation;
		}
		void setVisitedLocation(string visitedLocation) {
			this->visitedLocation = visitedLocation;
		}
		string getDateTime() {
			return this->dateTime;
		}
		void setDateTime(string dateTime) {
			this->dateTime = dateTime;
		}
		string getLastOverseasTravel() {
			return this->lastOverseasTravel;
		}
		void setLastOverseasTravel(string lastOverseasTravel) {
			this->lastOverseasTravel = lastOverseasTravel;
		}
		string getSymptoms() {
			return this->symptoms;
		}
		void setSymptoms(string symptoms) {
			this->symptoms = symptoms;
		}
		string getCovidTest() {
			return this->covidTest;
		}
		void setCovidTest(string covidTest) {
			this->covidTest = covidTest;
		}
		string getStatus() {
			return this->status;
		}
		void setStatus(string status) {
			this->status = status;
		}

		PatientDetail(int patientID, string name, string dOB, string address, string phoneNumber, string lastOverseasTravel, string symptoms, string visitedLocation, string dateTime) {
			this->patientID = patientID;
			this->name = name;
			this->dOB = dOB;
			this->address = address;
			this->phoneNumber = phoneNumber;
			this->visitedLocation = visitedLocation;
			this->dateTime = dateTime;
			this->lastOverseasTravel = lastOverseasTravel;
			this->symptoms = symptoms;
			this->covidTest = "";
			this->status = "";
		}	
};