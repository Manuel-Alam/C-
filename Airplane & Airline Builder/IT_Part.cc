#include "IT_Part.h"

//constructor
IT_Part::IT_Part(string name, int it_inspect):Part(name)
{
	this->it_inspect = it_inspect;
}

//destructor
IT_Part::~IT_Part()
{

}

//method used to inspec it part.
bool IT_Part::inspection(const Date& inspectionDate)
{
	//store difference in days between inspection and installation date.
	int difference = 0;

	//error checkign below to ensure no negative numbers.
	if(installationDate.toDays() >= inspectionDate.toDays())
	{
		difference = installationDate.toDays() -inspectionDate.toDays();
	}

	else if(inspectionDate.toDays() >= installationDate.toDays())
	{
		difference = inspectionDate.toDays() -installationDate.toDays();
	}

	//if the difference is greater than return true.
	if(difference >= it_inspect)
	{
		return true;
	}

	//return false.
	return false;
}

//method used to print out the object.
void IT_Part::print(ostream& out)
{
	Part::print(out);
	out << "Inspect Every:     "<<it_inspect<<" days installed"<<endl;
	out << "\n";
}
