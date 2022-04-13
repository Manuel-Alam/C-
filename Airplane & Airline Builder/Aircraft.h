
#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Array.h"
#include "Part.h"

using namespace std;

//Aircraft Class
class Aircraft {

	//overide ostream operator to print out Aircraft Objects.
	friend ostream& operator<<(ostream& out, Aircraft&);

	//public methods.
	public:

		//Constructor
		Aircraft(string type, string registration);

		//Destructor
		~Aircraft();

		//method used to install Part object into an Aircraft object.
		void install(Part*, Date&);

		//method used to increment flighthours member variable.
		void takeFlight(int hours);

		//method used to check inspection date for each part and return an array of matching parts.
		void inspectionReport(Date d, Array<Part*>*);

		//getter used to return registration member variable.
		const string& getRegistration() const;

	//member variables
	private:
		string type;
		string registration;
		int flighthours;
		Array<Part*> array;


};
#endif
