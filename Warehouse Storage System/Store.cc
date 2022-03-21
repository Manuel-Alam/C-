
#include "Store.h"

//constructor to init name and list of products for store.
Store::Store(const string& name)
{
  this->name = name;

  products = new List;

}

//destructor used to delete list of products (deallocate memory)
Store::~Store()
{
  delete products;
}

//find available storelocations in the store.
void Store::findAvailableSLoc(StoreLocation** sloc)
{
  //iterate through storelocaiton objects stored in static array.
  for(int i = 0; i < SLOCS;i++)
  {
    //if storelocation is available store it in sloc.
    if(storeLocationObjects[i].isAvailable())
    {
      *sloc = &storeLocationObjects[i];
      break;
    }
  }
}

//find available whlocations in the store.
void Store::findAvailableWHLoc(WHLocation** wloc)
{
  //iterate through the whlocaiton objects stored in static array.
  for(int i = 0; i < WHLOCS;i++)
  {
    //if whlocation is available store it in wloc.
    if(whLocationObjects[i].isAvailable())
    {
      *wloc = &whLocationObjects[i];
      break;
    }
  }
}

//method used to find product in the store.
void Store::findProduct(const string& name, Product** prod) const
{
  //call find product method in product class.
  products->findProduct(name,prod);
}

//print stock that is not empty in the storelocation array.
void Store::printStoreStock() const
{
  //iterate throuygh array.
  for(int i = 0; i< SLOCS;i++)
  {
    //print if product is not empty
    if(storeLocationObjects[i].getProduct() != "Empty")
    {
      storeLocationObjects[i].print();
    }
  }
}

//print stock that is not empty in the whlocaiton array.
void Store::printWareHouseStock() const
{
  //iterate through array.
  for(int i = 0; i< WHLOCS;i++)
  {
    //print if product is not empty.
    if(whLocationObjects[i].getProduct() != "Empty")
    {
      whLocationObjects[i].print();
    }
  }
}

//print all products in list.
void Store::printProducts() const
{

  //call print from List class.
  products->print();
}

//method used for a store to receive new products.
void Store::receiveProduct(const string& pname, int quantity){
    Product* prod = NULL;
    cout<<"Receiving..."<<endl;
    products->findProduct(pname, &prod);
    if (prod==NULL){
        cout<<"Making new product"<<endl;
        StoreLocation* sloc;
        findAvailableSLoc(&sloc);
        prod = new Product(pname, sloc);
        products->add(prod);

    }


    WHLocation* bloc;
    while(quantity > 0){
        findAvailableWHLoc(&bloc);
        if (quantity > bloc->getCapacity()){
            bloc->add(pname, bloc->getCapacity());
            prod->addWHLocation(bloc);
            quantity -= bloc->getCapacity();
        }else{
            bloc->add(pname, quantity);
            prod->addWHLocation(bloc);
            quantity = 0;
        }
    }

    cout<<"stocking store location..."<<endl;
    prod->stockStoreLocation();

}

//method used to fill an order for the store.
void Store::fillOrder(const string& product, int& quantity){
    Product* prod;
    findProduct(product, &prod);
    if (prod == NULL){
        return;
    }
    prod->fillOrder(quantity);
}


//print out the store data.
void Store::print() const{
    cout<<"Store: "<<name<<endl;
}
