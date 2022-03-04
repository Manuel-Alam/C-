#include "Subscriber.h"

//overloaded constructor used to initialize the member variables of a subscriber object.
Subscriber::Subscriber(string name, string creditcard)
{
	this->name = name;
	this->creditcard = creditcard;
}

//matches function used to check if a subscriber object has the same name as another subscriber.
bool Subscriber::matches(const string& name)
{
	//check if names match.
	if(name == this->name)
	{
		//if they do match return true.
		return true;
	}

	// if they dont match return false.
	return false;

}

//print method used to print subscriber member variables.
void Subscriber::print()
{
	cout<<"\nName: "<<name<< "\nCreditcard: "<<creditcard;
}
