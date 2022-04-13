
#ifndef FHIT_PART_H
#define FHIT_PART_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Part.h"
#include "FH_Part.h"
#include "IT_Part.h"

using namespace std;

//FHIT_Part subclass inherits from 2 classes.
class FHIT_Part: public FH_Part, public IT_Part
{

	public:
		//constructor
		FHIT_Part(string name, int fh_inspect, int it_inspect);

		//destructor
		virtual ~FHIT_Part();

		//method used for inspection
		virtual bool inspection(const Date& d);

		//method used to print part.
		virtual void print(ostream& out);


};
#endif
