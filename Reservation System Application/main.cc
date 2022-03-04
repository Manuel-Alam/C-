#include "a1-global.cc"

int main()
{
	//Date
	//(int year, int month, int day, int hour, int duration);

	//test a
	Date d1(2020,1,24,11,3);
	Date d2(2020,1,23,11,3);
	testDate(d1,d2,false);

	//test b
	Date d3(2020, 2, 20,12,1);
	Date d4(2020, 2, 20,15,1);
	testDate(d3,d4,false);

	//test c
	Date d5(2020, 2, 20,12,1);
	Date d6(2020, 2, 20,13,3);
	testDate(d5,d6,false);

	//test d
	Date d7(2020, 2, 20,12,2);
	Date d8(2020, 2, 20,13,1);
	testDate(d7,d8,true);


	//test e
	Date d9(2020, 2, 20,12,2);
	Date d10(2020, 2, 20,12,1);
	testDate(d9,d10,true);

	//create library object
	Library *l1 = new Library();
	populate(*l1);
	testReservations(*l1);

	//delete afterwards since done with
	delete l1;

}
