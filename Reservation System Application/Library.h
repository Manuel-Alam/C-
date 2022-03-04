#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include "Reservation.h"

using namespace std;

//global constant to limit size of each object array
const int MAX_ROOM_SIZE =  50;
const int MAX_STUDENT_SIZE =  50;
const int MAX_RESERVATION_SIZE =  50;

class Library
{

	public:
		//constructor and destructor
		Library();
		~Library();

		//add objects to arrays
		bool addStudent(string& name, string& number);
		bool addRoom(string name, int capacity=1, int computers=0, bool whiteboard=false);

		//get objects from arrays
		bool getStudent(string name, Student** student);
		bool getRoom(string roomName, Room** room);

		//check if reservation is possible
		bool isFree(string room, Date&);
		bool makeReservation(string student, string room, Date& d);



	private:
		Student** students;
		Room* rooms[MAX_ROOM_SIZE];
		Reservation** reservations;

		int studentSize;
		int roomSize;
		int reservationSize;

};
#endif
