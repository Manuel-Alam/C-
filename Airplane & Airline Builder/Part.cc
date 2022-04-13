#include "Part.h"

//constructor used to init member variables
Part::Part(string name): name(name)
{
	flighthours = 0;
}

//destructor
Part::~Part()
{

}

//increment flighthours variable.
void Part::addFlightHours(int amount)
{
	flighthours+=amount;
}

//set a new date for the paramter.
void Part::install(Date& d)
{
	installationDate.setDate(d);
}

//getter for name variable
const string& Part::getName() const
{
	return name;
}

//overide ostreamoperator to print out object.
ostream& operator<<(ostream& out, Part& p){
	p.print(out);
	return out;
}

//print method to print object.
void Part::print(ostream& out)
{
	out<<"Part:              "<<this->name<<"\nFlight hours:      "<<this->flighthours<< "\nInstallation Date: "<<this->installationDate;
}
