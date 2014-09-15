#include <iostream>
#include <cassert>
#include <cmath>
#include <cfloat>
using namespace std;

bool are_equal(double x, double y)
{
	return fabs(x - y) <= DBL_EPSILON;
}
double seconds_difference(double time_1, double time_2)
{
    // your implementation goes here...
	return time_2 - time_1;
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
	return (time_2 - time_1) / 3600.0;
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
	assert(0 <= minutes && minutes < 60);
	assert(0 <= seconds && seconds < 60);
	return hours + minutes / 60.0 + seconds / 3600.0;
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
	return hours - ((int)hours / 24) * 24;
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

double get_hours(double seconds)
{
	assert(0 <= seconds);
	return (int)seconds / 3600;
}

double get_minutes(double seconds)
{
	assert(0 <= seconds);
	return (int)(seconds - get_hours(seconds) * 3600) / 60;
}

double get_seconds(double seconds)
{
	assert(0 <= seconds);
	return seconds - get_hours(seconds) * 3600 - get_minutes(seconds) * 60;
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
	double CurrentTime = time - utc_offset;
	if (CurrentTime < 0)
		return 24 + CurrentTime + ((int)(-CurrentTime) / 24) * 24;
	else
		return CurrentTime - ((int)CurrentTime / 24) * 24;
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
	double CurrentTime = time + utc_offset;
	if (CurrentTime < 0)
		return 24 + CurrentTime + ((int)(-CurrentTime) / 24) * 24;
	else
		return CurrentTime - ((int)CurrentTime / 24) * 24;
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
		assert(are_equal(seconds_difference(1800.0, 3600.0), 1800.0));
		assert(are_equal(seconds_difference(3600.0, 1800.0), -1800.0));
		assert(are_equal(seconds_difference(1800.0, 2160.0), 360.0));
		assert(are_equal(seconds_difference(1800.0, 1800.0), 0.0));

		assert(are_equal(hours_difference(1800.0, 3600.0), 0.5));
		assert(are_equal(hours_difference(3600.0, 1800.0), -0.5));
		assert(are_equal(hours_difference(1800.0, 2160.0), 0.1));
		assert(are_equal(hours_difference(1800.0, 1800.0), 0.0));

		assert(are_equal(to_float_hours(0, 15, 0), 0.25));
		assert(are_equal(to_float_hours(2, 45, 9), 2.7525));
		assert(are_equal(to_float_hours(1, 0, 36), 1.01));

		assert(are_equal(to_24_hour_clock(24), 0));
		assert(are_equal(to_24_hour_clock(48), 0));
		assert(are_equal(to_24_hour_clock(25), 1));
		assert(are_equal(to_24_hour_clock(4), 4));
		assert(are_equal(to_24_hour_clock(28.5), 4.5));

		assert(are_equal(get_hours(3800), 1));
		assert(are_equal(get_minutes(3800), 3));
		assert(are_equal(get_seconds(3800), 20));

		assert(are_equal(time_to_utc(+0, 12.0), 12.0));
		assert(are_equal(time_to_utc(+1, 12.0), 11.0));
		assert(are_equal(time_to_utc(-1, 12.0), 13.0));
		assert(are_equal(time_to_utc(-11, 18.0), 5.0));
		assert(are_equal(time_to_utc(-1, 0.0), 1.0));
		assert(are_equal(time_to_utc(-1, 23.0), 0.0));

		assert(are_equal(time_from_utc(+0, 12.0), 12.0));
		assert(are_equal(time_from_utc(+1, 12.0), 13.0));
		assert(are_equal(time_from_utc(-1, 12.0), 11.0));
		assert(are_equal(time_from_utc(+6, 6.0), 12.0));
		assert(are_equal(time_from_utc(-7, 6.0), 23.0));
		assert(are_equal(time_from_utc(-1, 0.0), 23.0));
		assert(are_equal(time_from_utc(-1, 23.0), 22.0));
		assert(are_equal(time_from_utc(+1, 23.0), 0.0));
}