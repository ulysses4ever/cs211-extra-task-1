#include "stdafx.h"
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;
const double eps = 0.001;

double seconds_difference(double time_1, double time_2)
{
	return (time_2 - time_1);
	return 0;
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
}

double hours_difference(double time_1, double time_2)
{
	return seconds_difference(time_1, time_2) / 3600;
	return 0;
	
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
}

double to_float_hours(int hours, int minutes, int seconds)
{
	assert((0 <= minutes) && (minutes < 60) && (0 <= seconds) && (seconds < 60));
	return (hours + (minutes / 60.0) + (seconds / 3600.0));
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
}

double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	return (((int)hours) % 24 + (hours - (int)hours));
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
}
int get_hours(int hours)
{
	assert(hours >= 0);
	return (hours / 3600);
}
int get_minutes(int minutes)
{
	assert(minutes >= 0);
	return ((minutes - 3600 * (get_hours(minutes))) / 60);
}
int get_seconds(int seconds)
{
	assert(seconds >= 0);
	return (seconds - 60 * get_minutes(seconds) - 3600 * get_hours(seconds));
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

double time_to_utc(int utc_offset, double time)
{
	return to_24_hour_clock(time - utc_offset*1.0);
    /*
        Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.
        You may be interested in:
        https://en.wikipedia.org/wiki/Coordinated_Universal_Time

        >>> time_to_utc(+0, 12.0)
        12.0
 
        >>> time_to_utc(+1, 12.0)
        11.0
 
        >>> time_to_utc(-1, 12.0)
        13.0
 
        >>> time_to_utc(-11, 18.0)
        5.0
 
        >>> time_to_utc(-1, 0.0)
        1.0
 
        >>> time_to_utc(-1, 23.0)
        0.0
    */
}

double time_from_utc(int utc_offset, double time)
{
	return to_24_hour_clock(24 + (utc_offset + time));
    /*
        Return UTC time in time zone utc_offset.

        >>> time_from_utc(+0, 12.0)
        12.0
 
        >>> time_from_utc(+1, 12.0)
        13.0
 
        >>> time_from_utc(-1, 12.0)
        11.0
 
        >>> time_from_utc(+6, 6.0)
        12.0
 
        >>> time_from_utc(-7, 6.0)
        23.0
 
        >>> time_from_utc(-1, 0.0)
        23.0
 
        >>> time_from_utc(-1, 23.0)
        22.0
 
        >>> time_from_utc(+1, 23.0)
        0.0
    */
}



int main()
{
	assert((abs(seconds_difference(1800.0, 3600.0) - 1800.0)<eps) && "test 1.1");
	assert((abs(seconds_difference(3600.0, 1800.0) + 1800.0)<eps) && "test 1.2");
	assert((abs(seconds_difference(1800.0, 2160.0) - 360.0)<eps) && "test 1.3");
	assert((abs(seconds_difference(1800.0, 1800.0) - 0.0)<eps) && "test 1.4");
	cout << "test 1 is succasseful" << endl;

	assert(abs(hours_difference(1800.0, 3600.0) - 0.5)<eps && "test 2.1");
	assert(abs(hours_difference(3600.0, 1800.0) + 0.5)<eps && "test 2.2");
	assert(abs(hours_difference(1800.0, 2160.0) - 0.1)<eps && "test 2.3");
	assert(abs(hours_difference(1800.0, 1800.0) - 0.0)<eps && "test 2.4");
	cout << "test 2 is succasseful" << endl;

	assert(abs(to_float_hours(0, 15, 0) - 0.25)<eps && "test 3.1");
	assert(abs(to_float_hours(2, 45, 9) - 2.7525)<eps && "test 3.2");
	assert(abs(to_float_hours(1, 0, 36) - 1.01)<eps && "test 3.3");
	cout << "test 3 is succasseful" << endl;

	assert(abs(to_24_hour_clock(24) - 0)<eps && "test 4.1");
	assert(abs(to_24_hour_clock(48) - 0)<eps && "test 4.2");
	assert(abs(to_24_hour_clock(25) - 1)<eps && "test 4.3");
	assert(abs(to_24_hour_clock(4) - 4)<eps && "test 4.4");
	assert(abs(to_24_hour_clock(28.5) - 4.5)<eps && "test 4.5");
	cout << "test 4 is succasseful" << endl;

	assert((get_hours(3800) == 1) && "test 5.1");
	assert((get_minutes(3800) == 3) && "test 5.2");
	assert((get_seconds(3800) == 20) && "test 5.3");
	cout << "test 5 is succasseful" << endl;

	assert(abs(time_to_utc(+0, 12.0) - 12.0)<eps && "test 6.1");
	assert(abs(time_to_utc(+1, 12.0) - 11.0)<eps && "test 6.2");
	assert(abs(time_to_utc(-1, 12.0) - 13.0)<eps && "test 6.3");
	assert(abs(time_to_utc(-11, 18.0) - 5.0)<eps && "test 6.4");
	assert(abs(time_to_utc(-1, 0.0) - 1.0)<eps && "test 6.5");
	assert(abs(time_to_utc(-1, 23.0) - 0.0)<eps && "test 6.6");
	cout << "test 6 is succasseful " << endl;

	assert(abs(time_from_utc(+0, 12.0) - 12.0)<eps && "test 7.1");
	assert(abs(time_from_utc(+1, 12.0) - 13.0)<eps && "test 7.2");
	assert(abs(time_from_utc(-1, 12.0) - 11.0)<eps && "test 7.3");
	assert(abs(time_from_utc(+6, 6.0) - 12.0)<eps && "test 7.4");
	assert(abs(time_from_utc(-7, 6.0) - 23.0)<eps && "test 7.5");
	assert(abs(time_from_utc(-1, 0.0) - 23.0)<eps && "test 7.6");
	assert(abs(time_from_utc(-1, 23.0) - 22.0)<eps && "test 7.7");
	assert(abs(time_from_utc(+1, 23.0) - 0.0)<eps && "test 7.8");
	cout << "test 7 is succasseful " << endl;
	system("PAUSE");
}