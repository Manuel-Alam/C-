#include "Room.h"

//default constructor
Room::Room()
{
  name = "N/A";
  capacity = 0;
  computers = 0;
  whiteboard = false;
}

//copy constructor
Room::Room(Room& room)
{
  room.setName(this->name);
  room.setCapacity(this->capacity);
  room.setComputers(this->computers);
  room.setWhiteboard(this->whiteboard);
}

//overloaded constructor
Room::Room(string name, int capacity, int computers, bool whiteboard)
{
  this->name = name;
  this->capacity = capacity;
  this->computers = computers;
  this->whiteboard = whiteboard;
}
//Room(Room&);

//getters
string Room::getName()
{
  return name;
}

int Room::getCapacity()
{
  return capacity;
}

int Room::getComputers()
{
  return computers;
}

bool Room::hasWhiteboard()
{
  return whiteboard;
}

//setters
void Room::setName(string name)
{
  this->name = name;
}

void Room::setCapacity(int capacity)
{
  this->capacity = capacity;
}

void Room::setComputers(int computers)
{
  this->computers = computers;
}

void Room::setWhiteboard(bool whiteboard)
{
  this->whiteboard = whiteboard;
}

//checks if room meets criteria
bool Room::meetsCriteria(int capacity, int computers= 0, bool whiteboard = false)
{

  return (this->capacity >= capacity && this->computers >= computers && this->whiteboard >= whiteboard);
}

//compares room by names
bool Room::lessThan(Room& r)
{
  if(this->name < r.name)
  {
    return true;
  }

  return false;
}

//prints room
void Room::print()
{
  cout << "\nRoom name: " << name << " \nCapacity: "<< capacity<<"\nComputers: "<<computers<< " \nWhiteboards: "<<whiteboard<<endl;
}
