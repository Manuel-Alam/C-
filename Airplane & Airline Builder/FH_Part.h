
#ifndef FH_PART_H
#define FH_PART_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Part.h"

using namespace std;

//FH_Part Class
class FH_Part: virtual public Part {

	public:
		//constructor
		FH_Part(string name, int fh_inspect);

		//destructor
		virtual ~FH_Part();

		//insepction date method.
		virtual bool inspection(const Date& d);

		//print method
		virtual void print(ostream& out);

	protected:
		//functions
		int fh_inspect;


};
#endif
