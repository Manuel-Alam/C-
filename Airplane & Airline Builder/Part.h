
#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;

//Part super class
class Part {

	//ovride ostream operator
	friend ostream& operator<<(ostream& out, Part&);

	public:
		//getter for name variable
		const string& getName() const;

		//constructor
		Part(string name);

		//virtual destructor
		virtual ~Part();

		//method to increment flighthours variable
		void addFlightHours(int amount);

		//installs a new date to part.
		void install(Date& d);

		//pure virtual function to inspect date.
		virtual bool inspection(const Date& d) = 0;

		//virtual print method.
		virtual void print(ostream& out);

	protected:
		//functions
		string name;
		Date installationDate;
		int flighthours;


};
#endif
