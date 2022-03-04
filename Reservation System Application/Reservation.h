#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include "Student.h"
#include "Date.h"
#include "Room.h"

using namespace std;

class Reservation
{

	public:
		//constructor
		Reservation(Student* student, Room* room, Date& date);

		//getters for student, room and date objects.
		Student getStudent();
		Room getRoom();
		Date getDate();

		//compare and print reservations.
		bool lessThan(Reservation& res);
		bool overlaps(string r, Date& d);
		void print();

	private:
		Student *student;
		Room *room;
		Date date;

};
#endif
