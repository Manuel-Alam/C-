
#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Array.h"
#include "Part.h"
#include "Aircraft.h"
#include "IT_Part.h"
#include "FH_Part.h"
#include "FHIT_Part.h"

using namespace std;

//Airline Class
class Airline {

	//overide ostream operator to print out Airline Objects.
	friend ostream& operator<<(ostream& out, Airline&);

  //public methods.
	public:
		//Constructor
		Airline(const string& name);

		//Destructor
		~Airline();

		//method used to add a new Aircraft to the aircraft array.
		void addAircraft(string type, string registration);

		//method used toadd a new Part to the part array.
		void addPart(const string& part, int fh_inspect, int it_inspect);

		//method used to find a specific aircraft and have it take a flight.
		void takeFlight(string reg, int hours);

		//methods used to print aircraft and part array.
		void printAircraft();
		void printParts();

		//method used to determine if aircraft needs an inspection
		void inspectionReport(string reg, Date& d);

		//method used to install parts onto an aircraft.
		bool install(string aircraft_registration, string part_name, Date& d);

	//private member variables
	private:
		string name;
		Array<Part*> partsArray;
		Array<Aircraft*> aircraftArray;

		//private getter helper functions
		void getAircraft(string registration, Aircraft **air) const;
		void getPart(string name, Part **par) const;

};
#endif
