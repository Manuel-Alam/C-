
#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string>

using namespace std;

//location class super class.
class Location
{
	public:
		//overloaded constructor.
		Location(char character, int number);

		//destructor.
		~Location();

		//getters used to get member variables.
		const string& getId() const;
		const string& getProduct() const;
		int getQuantity() const;

		//check if location is empty.
		bool isEmpty() const;

		//check if location is available.
		bool isAvailable() const;

		//print location.
		void print() const;

		//super class methods to be inherited.
		virtual int getCapacity() const;

		virtual bool add(const string& product, int quantity);

		virtual bool remove(int quantity);

	protected:
		//member variables.
		string id;
		string product;
		int quantity;
		static const string NONE;

};
#endif
