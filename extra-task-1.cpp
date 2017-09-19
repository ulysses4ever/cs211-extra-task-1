#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

double seconds_difference(double time_1, double time_2)
{
    /*    
        Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.
            
        >>> seconds_difference(1800.0, 3600.0)
        1800.0

        >>> seconds_difference(3600.0, 1800.0)
        -1800.0

        >>> seconds_difference(1800.0, 2160.0)
        360.0

        >>> seconds_difference(1800.0, 1800.0)
        0.0
    */
	assert(time_1 >= 0);
	assert(time_2 >= 0);
	return time_2 - time_1;
}

double hours_difference(double time_1, double time_2)
{
	/*
	Return the number of hours later that a time in seconds
	time_2 is than a time in seconds time_1.

	>>> hours_difference(1800.0, 3600.0)
	0.5

	>>> hours_difference(3600.0, 1800.0)
	-0.5

	>>> hours_difference(1800.0, 2160.0)
	0.1

	>>> hours_difference(1800.0, 1800.0)
	0.0
	*/
	assert(time_1 >= 0);
	assert(time_2 >= 0);
	return seconds_difference(time_1, time_2) / 3600.0;
}

double to_float_hours(int hours, int minutes, int seconds)
{
	/*
	Return the total number of hours in the specified number
	of hours, minutes, and seconds.

	Precondition: 0 <= minutes < 60  and  0 <= seconds < 60

	>>> to_float_hours(0, 15, 0)
	0.25

	>>> to_float_hours(2, 45, 9)
	2.7525

	>>> to_float_hours(1, 0, 36)
	1.01
	*/
	assert(hours >= 0);
	assert(0 <= minutes && minutes < 60);
	assert(0 <= seconds && seconds < 60);

	return hours + minutes / 60.0 + seconds / 3600.0;
}

double to_24_hour_clock(double hours)
{
	/*
	hours is a number of hours since midnight. Return the
	hour as seen on a 24-hour clock.

	Precondition: hours >= 0

	>>> to_24_hour_clock(24)
	0

	>>> to_24_hour_clock(48)
	0

	>>> to_24_hour_clock(25)
	1

	>>> to_24_hour_clock(4)
	4

	>>> to_24_hour_clock(28.5)
	4.5

	You may wish to inspect various function in <cmath> to work
	with integer and fractional part of a hours separately.
	*/
	assert(hours >= 0);
	return fmod(hours, 24);
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

int main()
{
	//seconds_difference
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(3600.0, 1800.0) - -1800.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
	assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

	//hours_difference
	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(3600.0, 1800.0) - -0.5) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
	assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);

	//to_float_hours
	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);

	//to_24_hour_clock
	assert(fabs(to_24_hour_clock(24) - 0) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(48) - 0) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON);
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);
}