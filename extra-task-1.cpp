#include <cfloat>
#include <cmath>
#include <assert.h>

//Return the number of seconds later that a time in seconds
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

//Return the number of hours later that a time in seconds
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

//eturn the total number of hours in the specified number of h, m, s.
double to_float_hours(int hours, int minutes, int seconds)
{
	return hours + double(minutes) / 60 + double(seconds) / 3600;
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

//hours is a number of hours since midnight. Return the
//hour as seen on a 24 - hour clock.
double to_24_hour_clock(double hours)
{
	int full_hours(floor(hours));
	double remain(hours - full_hours);
	return full_hours % 24 + remain;
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

//Return the hours part of a time in seconds
int get_hours(int seconds)
{
	return (seconds / 3600) % 24;
}

//Return the minutes part of a time in seconds
int get_minutes(int seconds)
{
	return (seconds / 60) % 60;
}

//Return the seconds part of a time in seconds
int get_seconds(int seconds)
{
	return seconds % 60;
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
	int full_hours(floor(time));
	double remain(time - full_hours);
	int result = (full_hours - utc_offset) % 24;
	if (result < 0)
		result = 24 + result;
	return result + remain;
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
	int full_hours(floor(time));
	double remain(time - full_hours);
	int result = (full_hours + utc_offset) % 24;
	if (result < 0)
		result = 24 + result;
	return result + remain;
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

bool are_equal(double a, double b)
{
	return fabs(a - b) < DBL_EPSILON;
}
int main()
{
	//seconds_difference
	assert(are_equal(seconds_difference(1800.0, 3600.0), 1800.0) && "test 1.1");//test 1.1
	assert(are_equal(seconds_difference(3600.0, 1800.0), -1800.0) && "test 1.2");//test 1.2
	assert(are_equal(seconds_difference(1800.0, 2160.0), 360.0) && "test 1.3");//test 1.3
	assert(are_equal(seconds_difference(1800.0, 1800.0), 0.0) && "test 1.4");//test 1.4

	//hours_difference
	assert(are_equal(hours_difference(1800.0, 3600.0), 0.5) && "test 2.1");//test 2.1
	assert(are_equal(hours_difference(3600.0, 1800.0), -0.5) && "test 2.2");//test 2.2
	assert(are_equal(hours_difference(1800.0, 2160.0), 0.1) && "test 2.3");//test 2.3
	assert(are_equal(hours_difference(1800.0, 1800.0), 0.0) && "test 2.4");//test 2.4

	//to_float_hours
	assert(are_equal(to_float_hours(0, 15, 0), 0.25) && "test 3.1");//test 3.1
	assert(are_equal(to_float_hours(2, 45, 9), 2.7525) && "test 3.2");//test 3.2
	assert(are_equal(to_float_hours(1, 0, 36), 1.01) && "test 3.3");//test 3.3

	//to_24_hour_clock
	assert(are_equal(to_24_hour_clock(24), 0) && "test 4.1");//test 4.1
	assert(are_equal(to_24_hour_clock(48), 0) && "test 4.2");//test 4.2
	assert(are_equal(to_24_hour_clock(25), 1) && "test 4.3");//test 4.3
	assert(are_equal(to_24_hour_clock(4), 4) && "test 4.4");//test 4.4
	assert(are_equal(to_24_hour_clock(28.5), 4.5) && "test 4.5");//test 4.5

	//get_hours
	assert(are_equal(get_hours(3800), 1) && "test 5.1");//test 5.1

	//get_minutes
	assert(are_equal(get_minutes(3800), 3) && "test 5.2");//test 5.2
	
	//get_seconds
	assert(are_equal(get_seconds(3800), 20) && "test 5.3");//test 5.3

	//time_to_utc
	assert(are_equal(time_to_utc(+0, 12.0), 12) && "test 6.1");//test 6.1
	assert(are_equal(time_to_utc(+1, 12.0), 11) && "test 6.2");//test 6.2
	assert(are_equal(time_to_utc(-1, 12.0), 13) && "test 6.3");//test 6.3
	assert(are_equal(time_to_utc(-11, 18.0), 5) && "test 6.4");//test 6.4
	assert(are_equal(time_to_utc(-1, 0.0), 1) && "test 6.5");//test 6.5
	assert(are_equal(time_to_utc(-1, 23.0), 0) && "test 6.6");//test 6.6

	//time_from_utc
	assert(are_equal(time_from_utc(+0, 12.0), 12) && "test 7.1");//test 7.1
	assert(are_equal(time_from_utc(+1, 12.0), 13) && "test 7.2");//test 7.2
	assert(are_equal(time_from_utc(-1, 12.0), 11) && "test 7.3");//test 7.3
	assert(are_equal(time_from_utc(+6, 6.0), 12) && "test 7.4");//test 7.4
	assert(are_equal(time_from_utc(-7, 6.0), 23) && "test 7.5");//test 7.5
	assert(are_equal(time_from_utc(-1, 0.0), 23) && "test 7.6");//test 7.6
	assert(are_equal(time_from_utc(-1, 23.0), 22) && "test 7.7");//test 7.7
	assert(are_equal(time_from_utc(+1, 23.0), 0) && "test 7.8");//test 7.8
}