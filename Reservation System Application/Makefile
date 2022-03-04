all: a1

a1: Student.o Room.o Date.o Reservation.o Library.o main.o
	g++ -o a1 Student.o Room.o Date.o Reservation.o Library.o main.o

Student.o: Student.cc
	g++ -c Student.cc

Room.o: Room.cc
	g++ -c Room.cc

Date.o: Date.cc
	g++ -c Date.cc

Reservation.o: Reservation.cc
	g++ -c Reservation.cc

Library.o: Library.cc
	g++ -c Library.cc

main.o: main.cc
	g++ -c main.cc


clean:
	rm -f *.o a1
