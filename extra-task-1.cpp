#include<iostream>
#include<cassert>
#include<cmath>

using namespace std;

double seconds_difference(double time_1, double time_2)
{
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



double to_float_hours(int hours, int minutes, int seconds)
{
	assert((0 <= minutes) && (minutes < 60));
	assert((0 <= seconds) && (seconds < 60));
	return (double)hours + minutes / 60.0 + seconds / 3600.0;

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
	return fmod(hours, 24);

    /*
        hours is a number of hours since midnight. return the
        hour as seen on a 24-hour clock.

        precondition: hours >= 0

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
        
        you may wish to inspect various function in <cmath> to work
        with integer and fractional part of a hours separately.
        
    */
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

int get_hours(int seconds)
{
	assert(seconds >= 0);
	return seconds / 3600;
}

int get_minutes(int seconds)
{
	assert(seconds >= 0);
	return seconds % 3600 / 60;
}

int get_seconds(int seconds)
{
	assert(seconds >= 0);
	return seconds % 3600 % 60;
}


double time_to_utc(int utc_offset, double time)
{
	return time - utc_offset > 0 ? to_24_hour_clock(time - utc_offset) : to_24_hour_clock(time - utc_offset + 24);

    /*
        return time at utc+0, where utc_offset is the number of hours away from
        utc+0.
        you may be interested in:
        https://en.wikipedia.org/wiki/coordinated_universal_time

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
	
	return time + utc_offset > 0 ? to_24_hour_clock(time + utc_offset) : to_24_hour_clock(time + utc_offset + 24);

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

int main() {
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) <  DBL_EPSILON && "test - 11");
	assert(fabs(seconds_difference(3600.0, 1800.0) - (-1800.0)) <  DBL_EPSILON && "test - 12");
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) <  DBL_EPSILON && "test - 13");
	assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) <  DBL_EPSILON && "test - 14");

	assert(fabs(to_float_hours(0, 15, 0) - 0.25) <  DBL_EPSILON && "test - 21");
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) <  DBL_EPSILON && "test - 22");
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) <  DBL_EPSILON && "test - 23");

	assert(to_24_hour_clock(24) <  DBL_EPSILON && "test - 31");
	assert(to_24_hour_clock(48) <  DBL_EPSILON && "test - 32");
	assert(fabs(to_24_hour_clock(25) - 1) <  DBL_EPSILON && "test - 33");
	assert(fabs(to_24_hour_clock(4) - 4) <  DBL_EPSILON && "test - 34");
	assert(fabs(to_24_hour_clock(28.5) - 4.5) <  DBL_EPSILON && "test - 35");

	assert(get_hours(3800) == 1 && "test - 41");
	assert(get_minutes(3800) == 3 && "test - 42");
	assert(get_seconds(3800) == 20 && "test - 43");
	
	assert(fabs(time_to_utc(+0, 12.0) - 12.0) <  DBL_EPSILON && "test - 51");
	assert(fabs(time_to_utc(+1, 12.0) - 11.0) <  DBL_EPSILON && "test - 52");
	assert(fabs(time_to_utc(-1, 12.0) - 13.0) <  DBL_EPSILON && "test - 53");
	assert(fabs(time_to_utc(-11, 18.0) - 5.0) <  DBL_EPSILON && "test - 54");
	assert(fabs(time_to_utc(-1, 0.0) - 1.0) <  DBL_EPSILON && "test - 55");
	assert(time_to_utc(-1, 23.0) <  DBL_EPSILON && "test - 56");

	assert(fabs(time_from_utc(+0, 12.0) - 12.0) <  DBL_EPSILON && "test - 61");
	assert(fabs(time_from_utc(+1, 12.0) - 13.0) <  DBL_EPSILON && "test - 62");
	assert(fabs(time_from_utc(-1, 12.0) - 11.0) <  DBL_EPSILON && "test - 63");
	assert(fabs(time_from_utc(+6, 6.0) - 12.0) <  DBL_EPSILON && "test - 64");
	assert(fabs(time_from_utc(-7, 6.0) - 23.0) <  DBL_EPSILON && "test - 65");
	assert(fabs(time_from_utc(-1, 0.0) - 23.0) <  DBL_EPSILON && "test - 66");
	assert(fabs(time_from_utc(-1, 23.0) - 22.0) <  DBL_EPSILON && "test - 67");
	assert(time_from_utc(+1, 23.0) < DBL_EPSILON && "test - 68");

}

