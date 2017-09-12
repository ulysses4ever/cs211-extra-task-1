#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

bool areequal(double x, double y)
{
	return (abs(x - y) < 1e-10);
}

/*
Return the number of seconds later that a time in seconds
time_2 is than a time in seconds time_1.
*/
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
	return seconds_difference(time_1, time_2) / 3600.0;
}

/*Return the total number of hours in the specified number
  of hours, minutes, and seconds.*/
double to_float_hours(int hours, int minutes, int seconds)
{
	assert(0 <= minutes && minutes < 60);
	assert(0 <= seconds && seconds < 60);
	return (hours + minutes / 60.0 + seconds / 3600.0);
    
}

/*hours is a number of hours since midnight. Return the
hour as seen on a 24 - hour clock.*/
double to_24_hour_clock(double hours)
{
	assert(hours >= 0);
	return int(floor(hours)) % 24 + hours - floor(hours);
    
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
	return 0;
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
	return 0;
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

	//seconds_difference testing
	assert(areequal(seconds_difference(1800.0, 3600.0), 1800) && "test1");
	assert(areequal(seconds_difference(3600.0, 1800.0), -1800) && "test2");
	assert(areequal(seconds_difference(1800.0, 2160.0), 360) && "test3");
	assert(areequal(seconds_difference(1800.0, 1800.0), 0) && "test4");

	//hours_difference testing
	assert(areequal(hours_difference(1800.0, 3600.0), 0.5) && "test5");
	assert(areequal(hours_difference(3600.0, 1800.0), -0.5) && "test6");
	assert(areequal(hours_difference(1800.0, 2160.0), 0.1) && "test7");
	assert(areequal(hours_difference(1800.0, 1800.0), 0) && "test8");

	//to_float_hours testing
	assert(areequal(to_float_hours(0, 15, 0), 0.25) && "test9");
	assert(areequal(to_float_hours(2, 45, 9), 2.7525) && "test10");
	assert(areequal(to_float_hours(1, 0, 36), 1.01) && "test11");

	//to_24_hour_clock testing
	assert(areequal(to_24_hour_clock(24), 0) && "test12");
	assert(areequal(to_24_hour_clock(48), 0) && "test13");
	assert(areequal(to_24_hour_clock(25), 1) && "test14");
	assert(areequal(to_24_hour_clock(4), 4) && "test15");
	assert(areequal(to_24_hour_clock(28.5), 4.5) && "test16");

	cout << "Tests have been passed\n";
	system("PAUSE");
}