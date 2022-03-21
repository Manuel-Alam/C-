#include "WHLocation.h"

//init static member variables.
const char WHLocation::code = 'B';
const int WHLocation::capacity = WHLOC_CAPACITY;
int WHLocation::nextId = 0;

//default constructor int inherited member variables.
WHLocation::WHLocation():Location(code,nextId+=1)
{
}

//destructor.
WHLocation::~WHLocation()
{

}

//get capacity.
int WHLocation::getCapacity() const
{
  return capacity;
}

//add product to WHLocaiton.
bool WHLocation::add(const string& product, int amount)
{
  //only add if product is available.
  if(isAvailable() && amount <= capacity)
  {
    this->product = product;
    quantity=amount;

    return true;
  }
  return false;
}

//remove amouint of product from location.
bool WHLocation::remove(int amount)
{
  //error checking.

  if(amount < 0)
  {
    return false;
  }
  if(amount > quantity)
  {
    return false;
  }

  quantity -= amount;

  //if quantity is 0 after subtracting amount se product to null.
  if(quantity == 0)
  {
    product = NONE;
  }
  return true;
}

//print whlocation.
void WHLocation::print() const
{
  Location::print();
}
