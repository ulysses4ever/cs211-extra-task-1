//extra-task-1.cpp
#include <iostream>
#include <cassert>
#include <math.h>
using namespace std;

// Return the number of seconds later that a time in seconds
// time_2 is than a time in seconds time_1.

double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}


//Return the number of hours later that a time in seconds
//time_2 is than a time in seconds time_1.

double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1) / 3600.0;
}


//Return the total number of hours in the specified number
//of hours, minutes, and seconds.

double to_float_hours(int hours, int minutes, int seconds)
{
	return hours + minutes / 60.0 + seconds / 3600.0;
}


// hours is a number of hours since midnight. Return the
//hour as seen on a 24 - hour clock.

double to_24_hour_clock(double hours)
{
	return hours - 24 * floor(hours / 24.0);
}


//Implement three functions
//* get_hours
//* get_minutes
//* get_seconds
//They are used to determine the hours part, minutes part and seconds part
//of a time in seconds.E.g.:

//get_hours
int get_hours(int seconds)
{
	return floor(seconds / 3600);
}

//get_minutes
int get_minutes(int seconds)
{
	return (seconds - get_hours(seconds) * 3600) / 60;
}

//get_seconds
int get_seconds(int seconds)
{
	return seconds - get_hours(seconds) * 3600 - get_minutes(seconds) * 60;
}

//Return time at UTC+0, where utc_offset is the number of hours away from
//+UTC + 0.

double time_to_utc(int utc_offset, double time)
{
	if (time > utc_offset)
		return to_24_hour_clock(time - utc_offset);
	else return to_24_hour_clock(time + utc_offset);
}

//Return UTC time in time zone utc_offset.

double time_from_utc(int utc_offset, double time)
{
	if (time < utc_offset)
		return to_24_hour_clock(time - utc_offset);
	else return to_24_hour_clock(time + utc_offset);
}

int main() {
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON && "test-1");
	assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON && "test-2");
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON && "test-3");
	assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON && "test-4");
	cout << "seconds_difference passed" << endl;

	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON && "test-5");
	assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON && "test-6");
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON && "test-7");
	assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON && "test-8");
	cout << "hours_difference passed" << endl;

	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON && "test-9");
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON && "test-10");
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON && "test-11");
	cout << "to_float_hours passed" << endl;

	assert(fabs(to_24_hour_clock(24) - 0.0) < DBL_EPSILON && "test-12");
	assert(fabs(to_24_hour_clock(48) - 0.0) < DBL_EPSILON && "test-13");
	assert(fabs(to_24_hour_clock(25) - 1.0) < DBL_EPSILON && "test-14");
	assert(fabs(to_24_hour_clock(4) - 4.0) < DBL_EPSILON && "test-15");
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON && "test-16");
	cout << "to_24_hour_clock passed" << endl;

	assert((get_hours(3800) - 1.0) < DBL_EPSILON && "test-17");
	cout << "get_hours passed" << endl;
	assert((get_minutes(3800) - 3.0) < DBL_EPSILON && "test-18");
	cout << "get_minutes passed" << endl;
	assert((get_seconds(3800) - 20.0) < DBL_EPSILON && "test-19");
	cout << "get_seconds passed" << endl;

	assert((time_to_utc(+0, 12) - 12.0) < DBL_EPSILON);
	assert((time_to_utc(+1, 12) - 11.0) < DBL_EPSILON);
	assert((time_to_utc(+1, 9.3) - 8.3) < DBL_EPSILON);
	assert((time_to_utc(+12, 12)) < DBL_EPSILON);
	assert((time_to_utc(-1, 12) - 13.0) < DBL_EPSILON);
	assert((time_to_utc(-11, 18) - 5.0) < DBL_EPSILON);
	assert((time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
	assert((time_to_utc(-1, 23.0)) < DBL_EPSILON);
	cout << "time_to_utc passed" << endl;

	assert((time_from_utc(+0, 12.0) - 12.0)< DBL_EPSILON);
	assert((time_from_utc(+1, 12.0) - 13.0)< DBL_EPSILON);
	assert((time_from_utc(-1, 12.0) - 11.0)< DBL_EPSILON);
	assert((time_from_utc(+6, 6.0) - 12.0)< DBL_EPSILON);
	assert((time_from_utc(-7, 6.0) - 23.0)< DBL_EPSILON);
	assert((time_from_utc(-1, 0.0) - 23.0)< DBL_EPSILON);
	assert((time_from_utc(-1, 23.0) - 22.0)< DBL_EPSILON);
	assert((time_from_utc(+1, 23.0)) < DBL_EPSILON);
	cout << "time_from_utc passed" << endl;

	cout << "all tests were clearly passed" << endl;
}

