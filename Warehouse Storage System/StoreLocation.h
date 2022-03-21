
#ifndef STORELOCATION_H
#define STORELOCATION_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Location.h"

using namespace std;

//Storelocation class inherits properties of Location class.
class StoreLocation: public Location
{
	public:
		//default constructor.
		StoreLocation();

		//destructor.
		~StoreLocation();

		//setter to change the inherited product variable.
		void setProduct(const string& product);

		//check if location has free space.
		int getFreeSpace() const;

		//inherited methods from location class.
		virtual int getCapacity() const;
		virtual bool add(const string& product, int quantity);
		virtual bool remove(int amount);

		//print data of storelocation object.
		void print() const;

	private:

		//member variables.
		static const char code;
		static const int capacity;
		static int nextId;

};
#endif
