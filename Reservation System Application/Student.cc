#include "Student.h"

//student default constructor
Student::Student()
{
	name = "N/A";
	number = "N/A";
}

//student copy constructor
Student::Student(Student& student)
{
  student.setName(this->name);
	student.setNumber(this->number);
}
//student overloaded constructor
Student::Student(string name, string number)
{
	this->name = name;
	this->number = number;
}
//Student(Student&);

//getter for student attributes
string Student::getName()
{
	return name;
}

//getter for student attributes
string Student::getNumber()
{
	return number;
}

//setters for student attributes
void Student::setName(string name)
{
	this->name = name;
}
void Student::setNumber(string number)
{
	this->number = number;
}

//method to compare student numbers
bool Student::lessThan(Student& s)
{
	if(this->number < s.number)
	{
		return true;
	}

	return false;
}

//print student and attributes
void Student::print()
{
	cout << "Name: "<<name << " Student Number: "<<number<<endl;
}
