#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include "Product.h"

using namespace std;

//List class.
class List
{
	//nested Node class for storing data.
	class Node
	{
		//member variables of a ndoe.
  	public:
    	Product* data;
      Node*    next;
  };

	public:

				//default constructor
			  List();

        // Any data left in the List gets destroyed
        ~List();
        //we have unlimited size, so add always succeeds
        void add(Product* prod);
        //return false if name not found
        void findProduct(const string& name, Product** prod) const;
        //double pointer for a return parameter of a pointer
        void remove(const string& name, Product** prod);

				//remove elements up to a certain point from the list.
        void removeUpTo(const string& name);

				//print the data in the list.
        void print() const;  //not modify this List object

				//check if the list is empty.
				bool isEmpty() const;

	private:
		//member variable to keep track of the first node in the list.
		Node* head;

};
#endif
