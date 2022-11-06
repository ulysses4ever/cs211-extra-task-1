#include <assert.h>
#include <cmath>

double seconds_difference(double time_1, double time_2)
{
    return time_2 - time_1;
    
    /*    
        Return the number of seconds later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
}

double hours_difference(double time_1, double time_2)
{
    return (time_2 / 3600) - (time_1 / 3600);
    /*
        Return the number of hours later that a time in seconds
        time_2 is than a time in seconds time_1.
    */
}

double to_float_hours(int hours, int minutes, int seconds)
{
    assert(0 <= minutes < 60 && 0 <= seconds < 60);
    return hours + (minutes / 60.0) + (seconds / 3600.0);
    /*
        Return the total number of hours in the specified number
        of hours, minutes, and seconds.
    */
}

double to_24_hour_clock(double hours)
{
    assert(hours >= 0);
    double fract_part;
    double int_part;
    fract_part = modf(hours, &int_part);
    return ((int)int_part % 24) + fract_part;
    /*
        hours is a number of hours since midnight. Return the
        hour as seen on a 24-hour clock.
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

int get_hours(double time)
{
    return (int)time / 3600;
}

int get_minutes(double time)
{
    int hours{ get_hours(time) };
    return (time - (hours * 3600)) / 60;
}

int get_seconds(double time)
{
    int hours{ get_hours(time) };
    int minutes{ get_minutes(time) };
    return time - (hours * 3600) - (minutes * 60);
}

double time_to_utc(int utc_offset, double time)
{
    return ((int)(time)-utc_offset) % 24;
    /*
        Return time at UTC+0, where utc_offset is the number of hours away from
        UTC+0.
        You may be interested in:
        https://en.wikipedia.org/wiki/Coordinated_Universal_Time
    */
}

double time_from_utc(int utc_offset, double time)
{
    double res{ time + utc_offset };
    if (res < 0)
        return 24 + res;
    else if (res >= 24)
        return res - 24;
    return res;
    /*
        Return UTC time in time zone utc_offset.
    */
}