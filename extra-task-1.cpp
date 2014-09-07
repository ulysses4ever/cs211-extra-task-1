#include <iostream>
#include<cmath>
#include<cassert>

using namespace std;

/*
Return the number of seconds later that a time in seconds
time_2 is than a time in seconds time_1.
*/

double seconds_difference(double time_1, double time_2)
{
	assert((time_1 >= 0) && (time_2 >= 0));
	return time_2 - time_1;
}

/*
Return the number of hours later that a time in seconds
time_2 is than a time in seconds time_1.
*/

double hours_difference(double time_1, double time_2)
{
	assert((time_1 > 0) && (time_2 > 0));
	return seconds_difference(time_1, time_2) / 3600;
}

/*
Return the total number of hours in the specified number
of hours, minutes, and seconds.
*/

double to_float_hours(int hours, int minutes, int seconds)
{
	assert((hours >= 0) && (minutes >= 0) && (seconds >= 0));
	return (hours * 3600 + minutes * 60 + seconds) / 3600.0;
}

/*
hours is a number of hours since midnight. Return the
hour as seen on a 24-hour clock.
*/

double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	return hours-24*floor(hours / 24.0);
}

/*
Implement three functions
* get_hours
* get_minutes
* get_seconds
They are used to determine the hours part, minutes part and seconds part
of a time in seconds. E.g.:
*/

//get_hours
int get_hours(int seconds)
{
	assert(seconds >= 0);
	return floor(seconds / 3600);
}

//get_minutes
int get_minutes(int seconds)
{
	assert(seconds >= 0);
	return (seconds - get_hours(seconds) * 3600) / 60;
}

//get_seconds
int get_seconds(int seconds)
{
	assert(seconds >= 0);
	return seconds - get_hours(seconds) * 3600 - get_minutes(seconds)*60;
}

/*
Return time at UTC+0, where utc_offset is the number of hours away from
UTC+0.
*/

double time_to_utc(int utc_offset, double time)
{
	assert((utc_offset > -12) && (utc_offset <= 12) && (time >= 0));
	if (time <utc_offset) 
		return to_24_hour_clock(time - utc_offset+24);
	else return to_24_hour_clock(time - utc_offset);
}

/*
Return UTC time in time zone utc_offset.
*/

double time_from_utc(int utc_offset, double time)
{
	assert((utc_offset > -12) && (utc_offset <= 12) && (time >= 0));
	if ((time <abs(utc_offset)) && (time >utc_offset))
		return to_24_hour_clock(time + utc_offset + 24);
	else return to_24_hour_clock(time + utc_offset);
}

// main program
int main()
{
	cout << endl;
	cout << "this project was made by Abramov Anatoly (group 2.8.2)" << endl;
	cout << endl;
	cout << "seconds_difference test" << endl;
	assert((seconds_difference(1800.0, 3600.0) - 1800)< DBL_EPSILON);
	assert((seconds_difference(3600.0, 1800.0) + 1800)< DBL_EPSILON);
	assert((seconds_difference(1800.0, 2160.0) - 360)< DBL_EPSILON);
	assert(seconds_difference(1800.0, 1800.0) < DBL_EPSILON);
	assert((seconds_difference(42.45, 174.5)-132.05) < DBL_EPSILON);
	assert((seconds_difference(100.0, 10.0)+90) < DBL_EPSILON);
	cout << "seconds_difference passed" << endl;

	cout << "**************************************" << endl;

	cout << "hours_difference test" << endl;
	assert((hours_difference(1800.0, 3600.0) - 0.5)< DBL_EPSILON);
	assert((hours_difference(3600.0, 1800.0) + 0.5)< DBL_EPSILON);
	assert((hours_difference(1800.0, 2160.0) - 0.1)< DBL_EPSILON);
	assert((hours_difference(5481.4, 2397.9) + 0.8565)< DBL_EPSILON);
	assert((hours_difference(1200.0, 2160.0) - 0.2666667)< DBL_EPSILON);
	assert(hours_difference(1800.0, 1800.0) < DBL_EPSILON);
	cout << "hours_difference passed" << endl;

	cout << "**************************************" << endl;

	cout << "to_float_hours test" << endl;
	assert((to_float_hours(0,15,0) - 0.25)< DBL_EPSILON);
	assert((to_float_hours(2, 45, 9) - 2.7525)< DBL_EPSILON);
	assert((to_float_hours(1,0,36) - 1.01)< DBL_EPSILON);
	assert((to_float_hours(3, 57, 21) - 3.956)< DBL_EPSILON);
	assert((to_float_hours(0, 0, 36) - 0.01)< DBL_EPSILON);
	assert((to_float_hours(10,10, 10) - 10.17)< DBL_EPSILON);
	cout << "to_float_hours passed" << endl;

	cout << "**************************************" << endl;


	cout << "to_24_hour_clock test" << endl;
	assert((to_24_hour_clock(24))< DBL_EPSILON);
	assert((to_24_hour_clock(90000))< DBL_EPSILON);
	assert((to_24_hour_clock(3)-3)< DBL_EPSILON);
	assert((to_24_hour_clock(14893)-13)< DBL_EPSILON);
	assert((to_24_hour_clock(48))< DBL_EPSILON);
	assert((to_24_hour_clock(25)-1.0)< DBL_EPSILON);
	assert((to_24_hour_clock(4) - 4.0)< DBL_EPSILON);
	assert((to_24_hour_clock(28.5) - 4.5)< DBL_EPSILON);
	cout << "to_24_hour_clock passed" << endl;

	cout << "**************************************" << endl;

	cout << "get_hours test" << endl;
	assert((get_hours(3800)-1)< DBL_EPSILON);
	assert((get_hours(2733))< DBL_EPSILON);
	assert((get_hours(90100)-25)< DBL_EPSILON);
	assert((get_hours(125))< DBL_EPSILON);
	assert((get_hours(6433) - 1.0)< DBL_EPSILON);
	assert((get_hours(7200) - 2.0)< DBL_EPSILON);
	assert((get_hours(0))< DBL_EPSILON);
	cout << "get_hours passed" << endl;

	cout << "**************************************" << endl;

	cout << "get_minutes test" << endl;
	assert((get_minutes(3800) - 3)< DBL_EPSILON);
	assert((get_minutes(2733)-45)< DBL_EPSILON);
	assert((get_minutes(90100) - 1)< DBL_EPSILON);
	assert((get_minutes(125)-2)< DBL_EPSILON);
	assert((get_minutes(6433) - 47)< DBL_EPSILON);
	assert((get_minutes(7200) - 0)< DBL_EPSILON);
	assert((get_minutes(0))< DBL_EPSILON);
	cout << "get_minutes passed" << endl;

	cout << "**************************************" << endl;

	cout << "get_seconds test" << endl;
	assert((get_seconds(3800) - 20)< DBL_EPSILON);
	assert((get_seconds(2733) - 33)< DBL_EPSILON);
	assert((get_seconds(90100)-40)< DBL_EPSILON);
	assert((get_seconds(125) - 5)< DBL_EPSILON);
	assert((get_seconds(6433) - 13)< DBL_EPSILON);
	assert((get_seconds(7200) - 0)< DBL_EPSILON);
	assert((get_seconds(0))< DBL_EPSILON);
	cout << "get_seconds passed" << endl;

	cout << "**************************************" << endl;

	cout << "time_to_utc test" << endl;
	assert((time_to_utc(+0,12) - 12)< DBL_EPSILON);
	assert((time_to_utc(+1,12) - 11)< DBL_EPSILON);
	assert((time_to_utc(+1, 9.3) - 8.3)< DBL_EPSILON);
	assert((time_to_utc(+12, 12))< DBL_EPSILON);
	assert((time_to_utc(-1,12) - 13)< DBL_EPSILON);
	assert((time_to_utc(-11,18) -5)< DBL_EPSILON);
	assert((time_to_utc(-1, 23.0))< DBL_EPSILON);
	assert((time_to_utc(-1, 0.0) - 1)< DBL_EPSILON);
	assert((time_to_utc(-11, 23.9) - 10.9)< DBL_EPSILON);
	assert((time_to_utc(+1, 0.9) - 23.9)< DBL_EPSILON);
	cout << "time_to_utc passed" << endl;

	cout << "**************************************" << endl;

	cout << "time_from_utc test" << endl;
	assert((time_from_utc(+0, 12) - 12)< DBL_EPSILON);
	assert((time_from_utc(+1, 12) - 13)< DBL_EPSILON);
	assert((time_from_utc(-1, 12) - 11)< DBL_EPSILON);
	assert((time_from_utc(-1, 23.0)-22)< DBL_EPSILON);
	assert((time_from_utc(+6, 6.0)-12)< DBL_EPSILON);
	assert((time_from_utc(-7, 6.0) - 23)< DBL_EPSILON);
	assert((time_from_utc(-1, 0.0) - 23)< DBL_EPSILON);
	assert(time_from_utc(+1, 23.0)< DBL_EPSILON);
	assert((time_from_utc(+11, 23.9) - 10.9)< DBL_EPSILON);
	assert((time_from_utc(-1, 0.9) - 23.9)< DBL_EPSILON);
	cout << "time_from_utc passed" << endl;
	
	cout << "**************************************" << endl;
	
	cout << endl;
	cout <<"all tests were clearly passed"<< endl;
	cout << endl;
}
