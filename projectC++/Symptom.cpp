#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class Symptom 
{
	public:
		int symptomID; // initialize symptom ID
		string name; // symptom
		string typeRisk; // low, medium or high risk

		// Function declared without parameter
		Symptom(){
		}

		// Function declared with parameter
		// parameterized constructor
		Symptom(int symptomID, string name, string typeRisk)
		{
			this->symptomID = symptomID;
			this->name = name;
			this->typeRisk = typeRisk;
		}

		int getSymptomID() {
			return this->symptomID;
		}
		void setSymptomID(int symptomID) {
			this->symptomID = symptomID;
		}
		string getName() {
			return this->name;
		}
		void setName(string name) {
			this->name = name;
		}
		string getTypeRisk() {
			return this->typeRisk;
		}
		void setTypeRisk(string typeRisk) {
			this->typeRisk = typeRisk;
		}	
};