#include <assert.h>
#include <float.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>

/**
    Return the number of seconds later that a time
    in seconds time_2 is than a time in seconds time_1.
 */
double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
}

/**
    Return the number of hours later that a time 
    in seconds time_2 is than a time in seconds time_1.
 */
double hours_difference(double time_1, double time_2)
{
    return (time_2 - time_1) / 3600.0;
}

/**
    Return the total number of hours in the specified 
    number of hours, minutes, and seconds.

    Precondition: 0 <= minutes < 60  and  0 <= seconds < 60
 */
double to_float_hours(int hours, int minutes, int seconds)
{
    assert(hours >= 0);
    assert(0 <= minutes && minutes < 60.0);
    assert(0 <= seconds && seconds < 60.0);

    return hours + minutes / 60.0 + seconds / 3600.0;
}

/**
    Return the hour as seen on a 24-hour clock.
    Hours is a number of hours since midnight. 

    Precondition: hours >= 0
*/
double to_24_hour_clock(double hours)
{
    //assert(hours >= 0);
    return fmod(hours, 24.0);
}

/**
    Return the hours part of a time in seconds.
*/
double get_hours(double seconds) 
{
    return trunc(seconds / 3600.0);
}

/**
    Return the minutes part of a time in seconds.
*/
double get_minutes(double seconds) 
{
    double sign = seconds >= 0 ? 1 : -1;
    seconds = fmod(abs(seconds), 3600.0);
    return sign * trunc(seconds / 60);
}

/**
    Return the seconds part of a time in seconds.
*/
double get_seconds(double seconds) 
{
    double sign = seconds >= 0 ? 1 : -1;
    seconds = fmod(abs(seconds), 60.0);
    return sign * trunc(seconds);
}

/**
    Return time at UTC+0, where utc_offset 
    is the number of hours away from UTC+0.
*/
double time_to_utc(int utc_offset, double time)
{
    time = to_24_hour_clock(time - utc_offset); // in (-24, 24)
    return time > 0 ? time : time + 24;
}

/**
    Return UTC time in time zone utc_offset.
*/
double time_from_utc(int utc_offset, double time)
{
    return time_to_utc(-utc_offset, time);
}

unsigned testCounter = 0;

/**
    Checks, whether two double variables are equal.
    Raise assertion error if not. 
 */
void assertEquals(double expected, double actual) 
{
    bool correct = fabs(expected - actual) < DBL_EPSILON;
    testCounter++;

    if (!correct) {
        const char * format = "Test #%d failed! Expected: %f, Actual: %f\n\0";
        printf(format, testCounter, expected, actual);
        assert(0);
    }
}


int main() 
{
    // test seconds_difference()
    assertEquals(1800.0, seconds_difference(1800.0, 3600.0));
    assertEquals(-1800.0, seconds_difference(3600.0, 1800.0));
    assertEquals(360.0, seconds_difference(1800.0, 2160.0));
    assertEquals(0.0, seconds_difference(1800.0, 1800.0));

    // test hours_difference()
    assertEquals(0.5, hours_difference(1800.0, 3600.0));
    assertEquals(-0.5, hours_difference(3600.0, 1800.0));
    assertEquals(0.1, hours_difference(1800.0, 2160.0));
    assertEquals(0.0, hours_difference(1800.0, 1800.0));

    // test to_float_hours()
    assertEquals(0.25, to_float_hours(0, 15, 0));
    assertEquals(2.7525, to_float_hours(2, 45, 9));
    assertEquals(1.01, to_float_hours(1, 0, 36));

    // test to_24_hour_clock()
    assertEquals(0, to_24_hour_clock(24));
    assertEquals(0, to_24_hour_clock(48));
    assertEquals(1, to_24_hour_clock(25));

    assertEquals(4, to_24_hour_clock(4));
    assertEquals(4.5, to_24_hour_clock(28.5));
    assertEquals(-1, to_24_hour_clock(-25));

    // test get_hours(), get_minutes(), get_seconds()
    assertEquals(1, get_hours(3800));
    assertEquals(3, get_minutes(3800));
    assertEquals(20, get_seconds(3800));

    assertEquals(-1, get_hours(-3800));
    assertEquals(-3, get_minutes(-3800));
    assertEquals(-20, get_seconds(-3800));

    // test time_to_utc()
    assertEquals(12.0, time_to_utc(+0, 12.0));
    assertEquals(11.0, time_to_utc(+1, 12.0));
    assertEquals(13.0, time_to_utc(-1, 12.0));

    assertEquals(5.0, time_to_utc(-11, 18.0));
    assertEquals(1.0, time_to_utc(-1, 0.0));
    assertEquals(0.0, time_to_utc(-1, 23.0));
    assertEquals(0.0, time_to_utc(24 * 5 + 1, 1.0));

    // test time_from_utc()
    assertEquals(12.0, time_from_utc(+0, 12.0));
    assertEquals(13.0, time_from_utc(+1, 12.0));
    assertEquals(11.0, time_from_utc(-1, 12.0));
    assertEquals(12.0, time_from_utc(+6, 6.0));

    assertEquals(23.0, time_from_utc(-7, 6.0));
    assertEquals(23.0, time_from_utc(-1, 0.0));
    assertEquals(22.0, time_from_utc(-1, 23.0));
    assertEquals(0.0, time_from_utc(+1, 23.0));
}