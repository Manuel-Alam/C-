#include "FHIT_Part.h"

//constructor to init member variables.
FHIT_Part::FHIT_Part(string name, int fh_inspect, int it_inspect):FH_Part(name, fh_inspect),IT_Part(name, it_inspect),Part(name)
{

}

//destructor
FHIT_Part::~FHIT_Part()
{

}

//used to check part for inspection
bool FHIT_Part::inspection(const Date& inspectionDate)
{
	//if any of the parts need inspection then return trrue.
	if(FH_Part::inspection(inspectionDate) || IT_Part::inspection(inspectionDate))
	{
		return true;
	}

	//return false.
	return false;
}

//print method to print out object.
void FHIT_Part::print(ostream& out)
{
	Part::print(out);
	out << "Inspect Every:     "<<fh_inspect<<" flight hours"<<endl;
	out << "Inspect Every:     "<<it_inspect<<" days installed"<<endl;
	out << "\n";
}
