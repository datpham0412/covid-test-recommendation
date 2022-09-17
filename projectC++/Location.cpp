#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class Location 
{
	public:
		int locationID; // location ID
		string location; 

		// Function Initialized without parameter
		Location(){ 
		}

		// Function Initialized with parameter
		// parameterized constructor
		Location(int locationID, string location)
		{
			this->locationID = locationID;
			this->location = location;
		}


		int getLocationID() {
			return this->locationID;
		}
		void setLocationID(int locationID) {
			this->locationID = locationID;
		}
		string getLocation() {
			return this->location;
		}
		void setLocation(string location) {
			this->location = location;
		}	
};