
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T>

//Array Class
class Array {

	template<class V>

	//overide ostream operator to print out array object.
	friend ostream& operator<<(ostream& out, Array<V>&);

	//public functions.
	public:
		//constructor
		Array();

		//destructor
		~Array();

		//other
		void add(T);
		T& operator[](int) const;
		int getSize() const;
		bool isFull();

	//member variables.
	private:
		int size;
		T* elements;

};

//constructor used to create new array objects.
template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	size = 0;
}

//destructor used to delete array elements.
template <class T>
Array<T>::~Array(){
	delete [] elements;
}

//method used to add items to array.
template <class T>
void Array<T>::add(T element){
	if (size >= MAX_ARR)   return;
  	elements[size++] = element;
}

//return the size of the array.
template <class T>
int Array<T>::getSize() const{
	return size;
}

//check if the array is full
template <class T>
bool Array<T>::isFull(){
	return size >= MAX_ARR;
}

//overide ostream to print out each memory address of item in array,
template<class T>
ostream& operator<<(ostream& out, Array<T>& put)
{
    for(int i = 0; i< put.getSize();i++)
		{
			out << put.elements[i];
		}
    return out;
}

//used to iterate through the array.
template<class T>
T& Array<T>::operator[](int index) const
{
		if (index < 0 || index >= size)
		{
			cerr<<"Array index out of bounds"<<endl;
			exit(1);
		}

    return elements[index];
}



#endif
