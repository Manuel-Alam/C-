#include "Library.h"

Library::Library()
{
  studentSize = 0;
  roomSize = 0;
  reservationSize = 0;

  students = new Student*[MAX_STUDENT_SIZE];
  reservations = new Reservation*[MAX_RESERVATION_SIZE];

}

Library::~Library()
{

  for(int i =0; i< studentSize;i++)
  {
    delete students[i];

  }

  delete [] students;

  for(int j =0; j< reservationSize;j++)
  {
    delete reservations[j];
  }

  delete [] reservations;

  for(int k =0; k< roomSize;k++)
  {
    delete rooms[k];

  }

}

bool Library::addStudent(string& name, string& number)
{
  if(studentSize >= MAX_STUDENT_SIZE)
  {
    return false;
  }

  students[studentSize++] = new Student(name, number);

  return true;
}

bool Library::addRoom(string name, int capacity , int computers, bool whiteboard)
{
  if(roomSize >= MAX_ROOM_SIZE)
  {
    return false;
  }
  rooms[roomSize++] = new Room(name,capacity,computers,whiteboard);

  return true;
}

bool Library::getStudent(string name, Student** student)
{
  for(int i =0; i < studentSize;i++)
  {
    if(students[i]->getName() == name)
    {
      *student = students[i];

      return true;
    }
  }

  return false;
}

bool Library::getRoom(string roomName, Room** room)
{
  for(int i =0; i < roomSize;i++)
  {
    if(rooms[i]->getName() == roomName)
    {
      *room = rooms[i];

      return true;
    }
  }

  return false;
}

bool Library::isFree(string room, Date& date)
{

  Room *r;
  if(getRoom(room,&r) == false)
  {
    return false;
  }

  for(int i = 0; i < reservationSize;i++)
  {
    if(reservations[i]->overlaps(room,date))
    {
      return false;
    }
  }

  return true;
}

bool Library::makeReservation(string student, string room, Date& d)
{

  Student *s;
  Room *r;

  if(getStudent(student, &s) == false | getRoom(room, &r) == false)
  {
    return false;
  }

  bool free = isFree(room,d);
  if(reservationSize >= MAX_RESERVATION_SIZE|free == false )
  {
    return false;
  }

  if(free == true)
  {
    reservations[reservationSize++] = new Reservation(s, r, d);

    return true;
  }

  return false;
}
