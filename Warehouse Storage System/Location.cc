#include "Location.h"

//init static variable.
const string Location::NONE = "Empty";

//overloaded constructor to init member variables.
Location::Location(char character, int number)
{
  this->id = character+to_string(number);
  this->product = NONE;
  this->quantity = 0;
}

//destructor.
Location::~Location()
{

}

//check if location is empty.
bool Location::isEmpty() const
{
  if(quantity == 0)
  {
    return true;
  }

  return false;
}

//check if location is avaible.
bool Location::isAvailable() const
{
  if(product == NONE)
  {
    return true;
  }

  return false;
}

//print location data.
void Location::print() const
{
  cout<<"\nLocation ID: "<<id<<"\nProduct: "<<product<<"\nQuantity: "<<quantity<<endl;
}

//get location id
const string& Location::getId() const
{
  return id;
}

//get product from location
const string& Location::getProduct() const
{
  return product;
}

//get quantity from location.
int Location::getQuantity() const
{
  return quantity;
}

//get capacity from location.
int Location::getCapacity() const
{
  return 0;
}

//add product to locaiton.;
bool Location::add(const string& product, int quantity)
{

  return false;
}

//remove product from locaiton.
bool Location::remove(int amount)
{
  return true;
}
