
#ifndef WHLOCATION_H
#define WHLOCATION_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Location.h"

using namespace std;

//WHLocation class inherit Location class properties.
class WHLocation: public Location
{
	public:

		//default constructor.
		WHLocation();

		//destructor.
		~WHLocation();

		//inherited methods.
		virtual int getCapacity() const;
		virtual bool add(const string& product, int quantity);
		virtual bool remove(int amount);

		//print.
		void print() const;

	private:
		//member variables.
		static const char code;
	 	static const int capacity;
		static int nextId;

};
#endif
