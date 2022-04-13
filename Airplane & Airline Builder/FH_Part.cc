#include "FH_Part.h"

//constructor to init member variables
FH_Part::FH_Part(string name, int fh_inspect):Part(name)
{
	this->fh_inspect = fh_inspect;
}

//destructor.
FH_Part::~FH_Part()
{

}

//check if part need inspection
bool FH_Part::inspection(const Date& d)
{
	//needs inspection
	if(flighthours >= fh_inspect)
	{
		return true;
	}

	//doesnt need.
	return false;
}

//prints the object out in this format.
void FH_Part::print(ostream& out)
{
	Part::print(out);
	out << "Inspect Every:     "<<fh_inspect<<" flight hours"<<endl;
	out << "\n";
}
