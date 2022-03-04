#include "Reservation.h"

//overloaded constructor
Reservation::Reservation(Student* student, Room* room, Date& date)
{
	this->student = student;
	this->room = room;
	this->date.setDate(date);
}

//getters for specific objects
Student Reservation::getStudent()
{
	return *student;
}

Room Reservation::getRoom()
{
	return *room;
}

Date Reservation::getDate()
{
	return date;
}

//compare dates.
bool Reservation::lessThan(Reservation& res)
{
	if(this->date.lessThan(res.date))
	{
		return true;
	}
	return false;
}

//check if dates overlaps with rooms
bool Reservation::overlaps(string r, Date& d)
{
	if(r == room->getName() && this->date.overlaps(d))
	{
		return true;
	}
	return false;
}

//print reservation
void Reservation::print()
{
	cout << "Reservation for:"<<endl;
	date.print();
	room->print();
	student->print();

}
