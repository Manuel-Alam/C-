#include "Airline.h"

//constructor used to init member variables
Airline::Airline(const string& name)
{
	this->name = name;
}

//destructor used to delete parts and aircraft array elements.
Airline::~Airline()
{
	//iterating and deleting
	for(int i = 0; i< partsArray.getSize();i++)
	{
		delete partsArray[i];
	}

	for(int i = 0; i< aircraftArray.getSize();i++)
	{
		delete aircraftArray[i];
	}

}

//method add a new aircraft to the aircraft array.
void Airline::addAircraft(string type, string registration)
{
	//adding new aircraft to array.
	aircraftArray.add(new Aircraft(type, registration));
}

//method to add a new part to part array.
void Airline::addPart(const string& part, int fh_inspect, int it_inspect)
{

	//if the type of part is IT_Part then create an IT_Part.
	if(fh_inspect == 0)
	{
		partsArray.add(new IT_Part(part, it_inspect));
	}

	//if the type of part is FH_Part then create an FH_Part.
	else if(it_inspect == 0)
	{
		partsArray.add(new FH_Part(part, fh_inspect));
	}

	//if the type of object is neither FH or IT then create an FHIT_Part
	else
	{
		partsArray.add(new FHIT_Part(part, fh_inspect, it_inspect));
	}
}

//method used to take a flight for an aircraft
void Airline::takeFlight(string reg, int hours)
{
	int exist = 0;

	//find the desired aircraft
	Aircraft *a;
	getAircraft(reg,&a);

	//if it exist take a flight
	if(a!= NULL)
	{
		a->takeFlight(hours);
	}

	//otherwise aircraft wasnt found
	else
	{
		cout<<"Aircraft was not found."<<endl;
	}

}

//method usede to print all aircraft elements
void Airline::printAircraft()
{
	//iterate and print each element
	for(int i = 0; i < aircraftArray.getSize();i++)
	{
		cout<< *aircraftArray[i];
	}

}

//method used to print all parts elements
void Airline::printParts()
{
	//iterate and print each element.
	for(int i = 0; i < partsArray.getSize();i++)
	{
		cout<< *partsArray[i];
	}
}

//method used to check if aircraft needs inspection
void Airline::inspectionReport(string reg, Date& d)
{
	//variable to store output for aircraft
	Aircraft *a;
	getAircraft(reg,&a);

	//if aircraft exist then print all the parts in it.
	if(a != NULL)
	{
		//output paramter varaible
		Array<Part*> array;

		//check if array needs inspection
		a->inspectionReport(d,&array);

		//printout all parts that need inspection.
		cout<<"\nThe following parts from "<<a->getRegistration()<<" require inspection: \n";
		for(int i = 0; i < array.getSize();i++)
		{
			cout << *array[i];
		}

	}

	else
	{
		cout<<"NOT FOUND:INSPECTION REPORT";
	}
}

//getter used to search and retrieve for a specific aircraft from the aircraft array.
void Airline::getAircraft(string registration, Aircraft **air) const
{
	//iterate and store found item in output paramter.
	for(int i =0; i < aircraftArray.getSize();i++)
	{
		if(aircraftArray[i]->getRegistration() == registration)
		{
			*air = aircraftArray[i];
		}
	}
}

//getter used to search and retrieve for a specific part from the part array.
void Airline::getPart(string name, Part **par) const
{

	//iterate and store found item in output paramter.
	for(int i =0; i < partsArray.getSize();i++)
	{
		if(partsArray[i]->getName() == name)
		{
			*par = partsArray[i];
		}
	}
}

//method used to install a new part and date to the aircraft.
bool Airline::install(string aircraft_registration, string part_name, Date& d)
{
	//variable to store output paramter for aircraft.
	Aircraft *a;
	getAircraft(aircraft_registration,&a);

	//variable to store output paramter for part.
	Part *p;
	getPart(part_name,&p);

	//if the aircraft and part exist then install the new part and date.
	if(a != NULL && p != NULL)
	{
		a->install(p,d);
		return true;
	}

	//doesnt exist for one or the other 
	cout<<"PART OR AIRCRAFT DOESN't EXIST";
	return false;
}
