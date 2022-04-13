
#ifndef IT_PART_H
#define IT_PART_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Part.h"

using namespace std;

//IT_Part subClass
class IT_Part: virtual public Part {

	public:
		//constructor
		IT_Part(string name, int it_inspect);

		//destructor
		virtual ~IT_Part();

		//inspection date method.
		virtual bool inspection(const Date& d);

		//print method.
		virtual void print(ostream& out);

	protected:
		//functions
		int it_inspect;


};
#endif
