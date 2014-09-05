/*
Kvachev Vsevolod Dmitrievich, 2 course, 9th group
*/

#include <iostream>
#include <math.h>
#include <ctime>
#include <cassert>

using namespace std;


bool is_equal(double first, double second)
{
    return fabs(first - second) < DBL_EPSILON;
}

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
    assert(minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60);

    double ret = hours;
    //Add minutes, converted to hours
    ret += minutes / 60.0;
    //Seconds
    ret += seconds / 3600.0;

    return ret;
    /*
    Return the total number of hours in the specified number
    of hours, minutes, and seconds.
    Precondition: 0 <= minutes < 60 and 0 <= seconds < 60
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

    return fmod(hours, 24.0);
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

int get_hours(double time_in_seconds)
{
    return int(time_in_seconds / 3600.0);
}

int get_minutes(double time_in_seconds)
{
    return int(time_in_seconds / 60.0);
}

int get_seconds(double time_in_seconds)
{
    return int(time_in_seconds);
}

double time_to_utc(int utc_offset, double time)
{
    return fmod(24 + time - utc_offset, 24.0);

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
    return fmod(24 + time + utc_offset, 24.0);
    
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

void assert_compare(double first, double second)
{
    assert(is_equal(first, second));
}

int main()
{
    //is_equal
    assert(is_equal(1.00001, 1.00001) == true);
    assert(is_equal(12.00000000000000000001, 12.0) == true);
    assert(is_equal(-3.045, -3.045001) == false);
    
    //seconds_difference
    assert_compare(seconds_difference(1800.0, 3600.0), 1800.0);
    assert_compare(seconds_difference(3600.0, 1800.0), -1800.0);
    assert_compare(seconds_difference(1800.0, 2160.0), 360.0);
    assert_compare(seconds_difference(1800.0, 1800.0), 0.0);

    //hours_difference
    assert_compare(hours_difference(1800.0, 3600.0), 0.5);
    assert_compare(hours_difference(3600.0, 1800.0), -0.5);
    assert_compare(hours_difference(1800.0, 2160.0), 0.1);
    assert_compare(hours_difference(1800.0, 1800.0), 0.0);
    
    //to_float_hours
    assert_compare(to_float_hours(0, 15, 0), 0.25);
    assert_compare(to_float_hours(2, 45, 9), 2.7525);
    assert_compare(to_float_hours(1, 0, 36), 1.01);
    
    //to_24_hours_clock
    assert_compare(to_24_hour_clock(24), 0);
    assert_compare(to_24_hour_clock(25), 1);
    assert_compare(to_24_hour_clock(4), 4);
    assert_compare(to_24_hour_clock(28.5), 4.5);

    //get_hours
    assert(get_hours(3600.0) == 1);
    assert(get_hours(60.0) == 0);
    assert(get_hours(8888.0) == 2);

    //get_minutes
    assert(get_minutes(3600.0) == 60);
    assert(get_minutes(60.0) == 1);
    assert(get_minutes(7260.0) == 121);

    //get_seconds
    assert(get_seconds(3600.0) == 3600);
    assert(get_seconds(60.0) == 60);
    assert(get_seconds(8888.0) == 8888);

    //time_to_utc
    assert_compare(time_to_utc(+0, 12.0), 12.0);
    assert_compare(time_to_utc(+1, 12.0), 11.0);
    assert_compare(time_to_utc(-1, 12.0), 13.0);
    assert_compare(time_to_utc(-11, 18.0), 5.0);
    assert_compare(time_to_utc(-1, 0.0), 1.0);
    assert_compare(time_to_utc(-1, 23.0), 0.0);
    
    //time_from_utc
    assert_compare(time_from_utc(+0, 12.0), 12.0);
    assert_compare(time_from_utc(+1, 12.0), 13.0);
    assert_compare(time_from_utc(-1, 12.0), 11.0);
    assert_compare(time_from_utc(+6, 6.0), 12.0);
    assert_compare(time_from_utc(-7, 6.0), 23.0);
    assert_compare(time_from_utc(-1, 0.0), 23.0);
    assert_compare(time_from_utc(-1, 23.0), 22.0);
    assert_compare(time_from_utc(+1, 23.0), 0.0);


    return 0;
}