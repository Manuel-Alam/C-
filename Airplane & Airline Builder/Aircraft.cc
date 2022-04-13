#include "Aircraft.h"

//Aircraft constructor init member variables
Aircraft::Aircraft(string type, string registration)
{
	this->type = type;
	this->registration = registration;
	//init flight to 0 maybe
	flighthours = 0;
}

//destructor
Aircraft::~Aircraft()
{

}

//method will install new parts to the parts array.
void Aircraft::install(Part* p, Date& d)
{
	//adding new part to the array.
	array.add(p);

	//install the date to the part
	p->install(d);
}

//method will increase the flighhours membervariable for each part and aircraft
void Aircraft::takeFlight(int hours)
{
	//increment
	flighthours+=hours;

	//increment each parts flighthours
	for(int i =0; i <array.getSize();i++)
	{
		array[i]->addFlightHours(hours);
	}
}

//method will return the output array of parts that need inspection
void Aircraft::inspectionReport(Date d, Array<Part*>*out)
{
	//iterate through array for and check each part for inspection
	for(int i =0; i < array.getSize();i++)
	{
		if(array[i]->inspection(d))
		{
			//add array element to output array.
			out->add(array[i]);
		}
	}
}

//ostream operator overloaded to print out elements of aircraft object.
ostream& operator<<(ostream& out, Aircraft& aircraft)
{
	return out <<"Aircraft:      " <<aircraft.type <<"\nRegistration:  "<<aircraft.registration<<endl;
}

//getter
const string& Aircraft::getRegistration() const
{
	return registration;
}
