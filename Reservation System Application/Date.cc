
#include "Date.h"
Date::Date(){
	setDate(1901,1,1,1,1);
}

Date::Date(int y, int m, int d, int h, int dr){
	setDate(y,m,d,h,dr);
}

Date::Date(Date& date)
{
	setDate(date);
}


//setters
void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}

void Date::setDate(int y, int m, int d, int h, int dr){
	setMonth(m);
	setDay(d);
	setYear(y);
	setHour(h);
	setDuration(dr);
}

void Date::setDate(Date& d){
	setDate(d.year, d.month, d.day,d.hour,d.duration);
}

void Date::setHour(int h)
{
	if (h > 23) h = 23;
	if (h < 1) h = 1;
	hour = h;
}

void Date::setDuration(int d)
{
	if (d > MAX_DURATION) d = MAX_DURATION;
	if (d < 1) d = 1;
	duration = d;
}


//getters
int Date::getDay(){ return day; }
int Date::getMonth(){ return month; }
int Date::getYear(){ return year; }
int Date::getHour(){ return hour; }
int Date::getDuration(){ return duration; }

const string& Date::getMonthName(){return months[month-1];}


//other

bool Date::lessThan(Date& d){
	if (year == d.year)
	{
		if (month == d.month)
		{
			if(day == d.day)
			{
				return hour < d.hour;
			}
			else
			{
				return day < d.day;
			}

		}
		else
		{
			return month  < d.month;
		}
	}
	else
	{
		return year < d.year;
	}
}

//check if dates overlaps
bool Date::overlaps(Date& d)
{
	if(d.day == day && d.month == month && d.year == year && d.hour == hour)
	{
		return true;
	}

	if(d.day == day && d.month == month && d.year == year)
	{

		//define ranges for both dates
		int range = d.hour + d.duration;
		int range2 = hour + duration;
		if(d.hour > hour)
		{
			if(range2 > d.hour)
			{
				return true;
			}

		}
		if(hour > d.hour)
		{
			if(range > hour)
			{
				return true;
			}
		}

	}

	return false;
}
void Date::print(){
	cout << getMonthName()<<" "<<getDay()<<", "<<getYear()<<" "<< getHour()<<"H"<<" "<<getDuration()<<"Duration"<<endl;
}

int Date::getMaxDay(){
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}
