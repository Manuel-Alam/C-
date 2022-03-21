#include "StoreLocation.h"

//initialize static member variables for class.
const char StoreLocation::code = 'A';
const int StoreLocation::capacity = SLOC_CAPACITY;
int StoreLocation::nextId = 0;

//initialize inherited member variables from location class.
StoreLocation::StoreLocation():Location(code,nextId+=1)
{
}

//destructor.
StoreLocation::~StoreLocation()
{

}

//set the product name.
void StoreLocation::setProduct(const string& product)
{
  this->product = product;
}

//check if there's free space in the storelocation.
int StoreLocation::getFreeSpace() const
{
  //make sure returned value isnt negative.
  if(quantity >= capacity)
  {
    return quantity - capacity;
  }

  return capacity - quantity;
}

//get capacity.
int StoreLocation::getCapacity() const
{
  return capacity;
}

//add a product to the storelocation
bool StoreLocation::add(const string& product, int amount)
{
  //if the current product already exist than increase the quantity.
  if(getProduct() == product && amount <= capacity)
  {
    quantity+=amount;
    return true;
  }

  //if the product is available add it to the store location.
  if(isAvailable() && amount <= capacity)
  {
    this->setProduct(product);
    quantity+=amount;
    return true;
  }

  //return false if product doesnt exist or is not avaialbable.
  return false;
}

//remove certain product amount from store location.
bool StoreLocation::remove(int amount)
{
  //error checkign.
  if(amount < 0 )
  {
    return false;
  }

  //error checking.
  if(amount > quantity)
  {
    return false;
  }

  //subtract amoujnt.
  quantity -= amount;
  return true;
}

//print properties.
void StoreLocation::print() const
{
  Location::print();
}
