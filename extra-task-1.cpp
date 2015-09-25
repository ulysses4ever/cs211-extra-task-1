#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

/*
Return the number of seconds later that a time in seconds
time_2 is than a time in seconds time_1.*/
double seconds_difference(double time_1, double time_2)
{
	return time_2 - time_1;
}

/*
Return the number of hours later that a time in seconds
time_2 is than a time in seconds time_1.
*/
double hours_difference(double time_1, double time_2)
{
	return seconds_difference(time_1, time_2) / 3600;
}

/*
Return the total number of hours in the specified number
of hours, minutes, and seconds.

Precondition: 0 <= minutes < 60  and  0 <= seconds < 60
*/
double to_float_hours(int hours, int minutes, int seconds)
{
	assert((minutes >= 0) && (minutes < 60));
	assert((seconds >= 0) && (seconds < 60));

	return double(hours) + (double(minutes) + double(seconds) / 60) / 60;
}

/*
hours is a number of hours since midnight. Return the
hour as seen on a 24-hour clock.
Precondition: hours >= 0
*/
double to_24_hour_clock(double hours)
{

	assert(hours >= 0);

	double intPart;
	double fracPart = modf(hours, &intPart);
	return int(intPart) % 24 + fracPart;

}

/*
Implement three functions
* get_hours
* get_minutes
* get_seconds
They are used to determine the hours part, minutes part and seconds part
of a time in seconds. E.g.:

>>> get_hours(3800)
1

>>> get_minutes(3800)
3

>>> get_seconds(3800)
20

In other words, if 3800 seconds have elapsed since midnight,
it is currently 01:03:20 (hh:mm:ss).
*/
int get_hours(int seconds) {
	return seconds / 3600;
}

int get_minutes(int seconds) {
	return (seconds % 3600) / 60;
}

int get_seconds(int seconds) {
	return (seconds % 3600) % 60;
}

/*
Return time at UTC+0, where utc_offset is the number of hours away from
UTC+0.
*/
double time_to_utc(int utc_offset, double time)
{

	double temp = time - utc_offset;
	if (temp < 0)
		temp = 24 + temp;
	return to_24_hour_clock(temp);
}

/*
	Return UTC time in time zone utc_offset.
	*/
double time_from_utc(int utc_offset, double time)
{
	
	double temp = time + utc_offset;
	if (temp < 0)
		temp = 24 + temp;
	return 	to_24_hour_clock(temp);
}


int main() {

	/*
	Return the number of seconds later that a time in seconds
	time_2 is than a time in seconds time_1.*/

	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 1800.0)) < DBL_EPSILON);

	cout << "Tests for the function 'seconds_difference' are completed successfully" << endl;

	/*
	Return the number of hours later that a time in seconds
	time_2 is than a time in seconds time_1.
	*/

	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 1800.0)) < DBL_EPSILON);

	cout << "Tests for the function 'hours_difference' are completed successfully" << endl;

	/*
	Return the total number of hours in the specified number
	of hours, minutes, and seconds.

	Precondition: 0 <= minutes < 60  and  0 <= seconds < 60
	*/

	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

	cout << "Tests for the function 'to_float_hours' are completed successfully" << endl;

	/*
	hours is a number of hours since midnight. Return the
	hour as seen on a 24-hour clock.
	Precondition: hours >= 0
	*/

	assert(fabs(to_24_hour_clock(24)) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(48)) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);

	cout << "Tests for the function 'to_24_hour_clock' are completed successfully" << endl;

	//Implement three functions
	//	* get_hours
	//	* get_minutes
	//	* get_seconds
	//	They are used to determine the hours part, minutes part and seconds part
	//	of a time in seconds.

	assert(get_hours(3800) == 1);
	assert(get_minutes(3800) == 3);
	assert(get_seconds(3800) == 20);

	cout << "Tests for functions 'get_hours', 'get_minutes', 'get_seconds' are completed successfully" << endl;

	/*
	Return time at UTC+0, where utc_offset is the number of hours away from
	UTC+0.
	*/

	assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON);
	assert(fabs(time_to_utc(-1, 23.0)) < DBL_EPSILON);

	cout << "Tests for the function 'time_to_utc' are completed successfully" << endl;

	assert(fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON);
	assert(fabs(time_from_utc(+1, 23.0) - 0) < DBL_EPSILON);

	cout << "Tests for the function 'time_from_utc' are completed successfully" << endl;

}
