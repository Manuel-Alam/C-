#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student
{

	public:
		//constructors
		Student();
		Student(Student& student);
		Student(string name, string number);

		//getters
    string getName();
		string getNumber();

		//setters
		void setName(string name);
		void setNumber(string number);

		//comparing and printing students
    bool lessThan(Student& s);
    void print();

	private:
		string name;
		string number;
};
#endif
