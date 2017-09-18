#include<cmath>
#include<cassert>

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
	return (time_2 - time_1) / 3600.0;
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

        
    */
	return int(trunc(hours)) % 24 + (hours - trunc(hours));
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
	return seconds / 3600;
}

int get_minutes(int seconds)
{
	return seconds % 3600 / 60;
}

int get_seconds(int seconds)
{
	return seconds % 3600 % 60;
}

double time_to_utc(int utc_offset, double time)
{
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

	return 0;
}

double time_from_utc(int utc_offset, double time)
{
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

	return 0;
} 

const double Eps = 0.0000001;

void main()
{
	//tests#1 seconds_difference
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < Eps && "test-1-1");
	assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < Eps && "test-1-2");
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < Eps && "test-1-3");
	assert(fabs(seconds_difference(1800.0, 1800.0)) < Eps && "test-1-4");

	//tests#2 hours_difference
	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < Eps && "test-2-1");
	assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < Eps && "test-2-2");
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < Eps && "test-2-3");
	assert(fabs(hours_difference(1800.0, 1800.0)) < Eps && "test-2-4");

	//tests#3 to_float_hours
	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < Eps && "test-3-1");
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < Eps && "test-3-2");
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < Eps && "test-3-3");

	//tests#4 to_24_hour_clock
	assert(fabs(to_24_hour_clock(24)) < Eps && "test-4-1");
	assert(fabs(to_24_hour_clock(48)) < Eps && "test-4-2");
	assert(fabs(to_24_hour_clock(25) - 1) < Eps && "test-4-3");
	assert(fabs(to_24_hour_clock(4) - 4) < Eps && "test-4-4");
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < Eps && "test-4-5");

	//tests#5 get_hours get_minutes get_seconds
	assert(get_hours(3800) == 1 && "test-5-1");
	assert(get_hours(7700) == 2 && "test-5-2");
	assert(get_hours(10800) == 3 && "test-5-3");

	assert(get_minutes(3800) == 3 && "test-5-4");
	assert(get_minutes(7700) == 8 && "test-5-5");
	assert(get_minutes(10800) == 0 && "test-5-6");

	assert(get_seconds(3800) == 20 && "test-5-7");
	assert(get_seconds(7700) == 20 && "test-5-8");
	assert(get_seconds(10800) == 0 && "test-5-9");
}
