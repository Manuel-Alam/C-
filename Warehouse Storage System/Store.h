
#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Product.h"
#include "List.h"
#include "defs.h"

using namespace std;

//Store class.
class Store {

	public:
		//constructor
		Store(const string& name);

		//destructor
		~Store();

		//other
		void findAvailableSLoc(StoreLocation**);
		void findAvailableWHLoc(WHLocation**);

		//print out the stock of each location type and products.
		void printStoreStock() const;
		void printWareHouseStock() const;
		void printProducts() const;

		//find a product in the store.
		void findProduct(const string&, Product**) const;

		//add new product to store.
		void receiveProduct(const string&, int quantity);

		//fill an order for the store.
		void fillOrder(const string&, int &quantity);

		//print out the current items in the store.
		void print() const;

	private:
		//private member variables
		string name;
		StoreLocation storeLocationObjects[SLOCS];
		WHLocation whLocationObjects[WHLOCS];
		List* products;





};
#endif
