#include <iostream>
#include <cassert> 
#include <cmath>

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
	return seconds_difference(time_1, time_2) / 3600.0;
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
	assert((minutes >= 0) && (minutes < 60) && "Invalid value of minutes");
	return (hours * 3600 + minutes * 60 + seconds) / 3600.0;
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
	assert((hours >= 0) && "Invalid value of hours");
	return floor(hours) % 24 + hours - floor(hours) ;
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

//Return the hours part of a time in seconds
int get_hours(int time)
{
	return time / 3600;
}

//Return the minutes part of a time in seconds
int get_minutes(int time)
{
	return (time % 3600) / 60;
}

//Return the seconds part of a time in seconds
int get_seconds(int time)
{
	return time - get_hours(time) * 3600 - get_minutes(time) * 60;
}


double time_to_utc(int utc_offset, double time)
{
	return (floor(time) - utc_offset) % 24 + time - floor(time);
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
	return (floor(time) + utc_offset + 24) % 24 + time - floor(time);

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
	//Tests for seconds_difference
	assert((fabs(seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON) && "Test 1");
	assert((fabs(seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON) && "Test 2");
	assert((fabs(seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON) && "Test 3");
	assert((fabs(seconds_difference(1800.0, 1800.0)) < DBL_EPSILON) && "Test 4");

	//Tests for hours_difference
	assert((fabs(hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON) && "Test 5");
	assert((fabs(hours_difference(1800.0, 3600.0) + 0.5) < DBL_EPSILON) && "Test 6");
	assert((fabs(hours_difference(1800.0, 3600.0) - 0.1) < DBL_EPSILON) && "Test 7");
	assert((fabs(hours_difference(1800.0, 3600.0)) < DBL_EPSILON) && "Test 8");

	//Tests for to_float_hours
	assert((fabs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON) && "Test 9");
	assert((fabs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON) && "Test 10");
	assert((fabs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON) && "Test 11");


	//Tests for to_24_hour_clock
	assert((fabs(to_24_hour_clock(24)) < DBL_EPSILON) && "Test 12");
	assert((fabs(to_24_hour_clock(48)) < DBL_EPSILON) && "Test 13");
	assert((fabs(to_24_hour_clock(25) - 1) < DBL_EPSILON) && "Test 14");
	assert((fabs(to_24_hour_clock(4) - 4) < DBL_EPSILON) && "Test 15");
	assert((fabs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON) && "Test 16");

	//Tests for time_to_utc
	assert((fabs(time_to_utc(0, 12.0) - 12.0) < DBL_EPSILON) && "Test 17");
	assert((fabs(time_to_utc(1, 12.0) - 11.0) < DBL_EPSILON) && "Test 18");
	assert((fabs(time_to_utc(-1, 12.0) - 13.0) < DBL_EPSILON) && "Test 19");
	assert((fabs(time_to_utc(-11, 18.0) - 5.0) < DBL_EPSILON) && "Test 20");
	assert((fabs(time_to_utc(-1, 0.0) - 1.0) < DBL_EPSILON) && "Test 21");
	assert((fabs(time_to_utc(-1, 23.0)) < DBL_EPSILON) && "Test 22");

	//Tests for time_from_utc
	assert((fabs(time_from_utc(0, 12.0) - 12.0) < DBL_EPSILON) && "Test 23");
	assert((fabs(time_from_utc(1, 12.0) - 13.0) < DBL_EPSILON) && "Test 24");
	assert((fabs(time_from_utc(-1, 12.0) - 11.0) < DBL_EPSILON) && "Test 25");
	assert((fabs(time_from_utc(6, 6.0) - 12.0) < DBL_EPSILON) && "Test 26");
	assert((fabs(time_from_utc(-7, 6.0) - 23.0) < DBL_EPSILON) && "Test 27");
	assert((fabs(time_from_utc(-1, 0.0) - 23.0) < DBL_EPSILON) && "Test 28");
	assert((fabs(time_from_utc(-1, 23.0) - 22.0) < DBL_EPSILON) && "Test 29");


}
