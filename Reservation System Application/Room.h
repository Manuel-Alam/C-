#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

using namespace std;

class Room
{

	public:
		//constructors
		Room();
		Room(string name, int capacity, int computers, bool whiteboard);
		Room(Room& room);

		//getters
		string getName();
		int getCapacity();
		int getComputers();
		bool hasWhiteboard();

		//setters
		void setName(string name);
		void setCapacity(int capacity);
		void setComputers(int computers);
		void setWhiteboard(bool whiteboard);

		//methods for printing and comparing rooms etc..
		bool meetsCriteria(int capacity, int computers, bool whiteboard);
		bool lessThan(Room& r);
		void print();

	private:
		string name;
    int capacity;
    int computers;
    bool whiteboard;
};
#endif
