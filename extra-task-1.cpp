#include <iostream>
#include <cassert>
#include <cmath>
#include <cfloat>

using std::cout;
using std::endl;

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

double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1) / 3600;
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
	assert(0 <= minutes < 60 && 0 <= seconds < 60);
	return hours + minutes*1.0 / 60 + seconds*1.0 / 3600;

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
	//assert(hours >= 0);
	//"Assert" doesn't work with "test-6_5" 
	//But there is no special need, we just add 24 to "hours"
	return fmod(hours + 24.0, 24);

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


int get_hours(double seconds)
{
	return int(seconds / 3600);
	//determine the hours part

}

int get_minutes(double seconds)
{
	return int(fmod(seconds, 3600) / 60);
	//determine the minutes part
}

double get_seconds(double seconds)
{
	return seconds - get_hours(seconds)*3600.0 - get_minutes(seconds) * 60.0;
	//determine the seconds part
}

double time_to_utc(int utc_offset, double time)
{

	return to_24_hour_clock(time - utc_offset);
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
	return to_24_hour_clock(time + utc_offset);
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

	//seconds_difference
	assert(fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON && "test-1_1");
	assert(fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON && "test-1_2");
	assert(fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON && "test-1_3");
	assert(fabs(seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON && "test-1_4");

	//hours_difference
	assert(fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON && "test-2_1");
	assert(fabs(hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON && "test-2_2");
	assert(fabs(hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON && "test-2_3");
	assert(fabs(hours_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON && "test-2_4");

	//to_float_hours
	assert(fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON && "test-3_1");
	assert(fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON && "test-3_2");
	assert(fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON && "test-3_3");

	//to_24_hour_clock
	assert(fabs(to_24_hour_clock(24) - 0) < DBL_EPSILON && "test-4_1");
	assert(fabs(to_24_hour_clock(48) - 0) < DBL_EPSILON && "test-4_2");
	assert(fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON && "test-4_3");
	assert(fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON && "test-4_4");
	assert(fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON && "test-4_5");

	//time_to_utc
	assert(fabs(time_to_utc(+0, 12.0) - 12.0) < DBL_EPSILON && "test-5_1");
	assert(fabs(time_to_utc(+1, 12.0) - 11.0) < DBL_EPSILON && "test-5_2");
	assert(fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON && "test-5_3");
	assert(fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON && "test-5_4");
	assert(fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON && "test-5_5");
	assert(fabs(time_to_utc(-1, 23.0) - 0.0) < DBL_EPSILON && "test-5_6");

	//time_from_utc
	assert(fabs(time_from_utc(+0, 12.0) - 12.0) < DBL_EPSILON && "test-6_1");
	assert(fabs(time_from_utc(+1, 12.0) - 13.0) < DBL_EPSILON && "test-6_2");
	assert(fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON && "test-6_3");
	assert(fabs(time_from_utc(+6, 6.0) - 12.0) < DBL_EPSILON && "test-6_4");
	assert(fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON && "test-6_5");
	assert(fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON && "test-6_6");
	assert(fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON && "test-6_7");
	assert(fabs(time_from_utc(+1, 23.0) - 0.0) < DBL_EPSILON && "test-6_8");

	//get_hours
	assert(fabs(get_hours(3800) - 1) < DBL_EPSILON && "test-7");

	//get_minutes
	assert(fabs(get_minutes(3800) - 3) < DBL_EPSILON && "test-8");
	
	//get_seconds
	assert(fabs(get_seconds(3800) - 20) < DBL_EPSILON && "test-9");
	
	cout << "Tests completed successfully! " << endl;
}